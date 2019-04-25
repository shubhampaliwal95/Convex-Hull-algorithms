#include<bits/stdc++.h>
#include "MakeHull.h"
#include "MoM.h"
#include "Bridge.h"
#define x first
#define y second
using namespace std;

/** Tells if a given point is to left of line AB or not
*
*/
bool isLeft(pair<double,double> A,pair<double,double>B, pair<double,double>M)
{
    long long ans=(B.x-A.x)*(M.y-A.y)-(B.y-A.y)*(M.x-A.x);
    return ans>0;
}
/** Tells if a given point is towards right of the line AB or not 
*
*/
bool isRight(pair<double,double> A,pair<double,double>B, pair<double,double>M)
{
    long long ans=(B.x-A.x)*(M.y-A.y)-(B.y-A.y)*(M.x-A.x);
    return ans<0;
}
/** Returns the UpperHull of given set of points 
*
*/
vector<pair<double,double> > UpperHull(pair<double,double>pmin,pair<double,double>pmax,vector<pair<double,double> > &T)
{
    //cout<<"T's size="<<T.size()<<endl;
    //cout<<"Pmin:"<<pmin.first<<" "<<pmin.second<<endl;
    //cout<<"Pmax:"<<pmax.first<<" "<<pmax.first<<endl;
    if(T.size()<=2)return T;
    double maxi=T[0].first;
    double mini=T[0].first;
    for(auto i:T)
    {
        maxi=max(i.first,maxi);
        mini=min(i.first,mini);

    }
    pair<double,double>med;/*! Median of set of points.*/
    med.second=0;
    med.first=(maxi+mini)/2+0.000001;
    vector<pair<double,double> >TL,TR; 
    vector<pair<double,double> >UB=UpperBridge(T,med);/*! Stores upper bridge.*/
    TL.push_back(UB[0]);
    int i;

    for(i=0;i<T.size();i++)
    {
        if(isLeft(pmin,UB[0],T[i]))
            TL.push_back(T[i]);
    }

    for(i=0;i<T.size();i++)
    {
        if(isLeft(UB[1],pmax,T[i]))
        {
            TR.push_back(T[i]);
        }
    }
    TR.push_back(UB[1]);

    vector<pair<double,double> >a,b;

    /*cout<<"For T:"<<endl;
    for(auto i:T)cout<<i.first<<" "<<i.second<<endl;
    cout<<"UB:"<<UB[0].first<<" "<<UB[0].second<<" "<<UB[1].first<<" "<<UB[1].second<<endl;
    cout<<"TL:"<<endl;
    for(auto i:TL)cout<<i.first<<" "<<i.second<<endl;
    cout<<"TR:"<<endl;
    for(auto i:TR)cout<<i.first<<" "<<i.second<<endl;*/
    a=UpperHull(pmin,UB[0],TL);/*! a stores the hull of left partition.*/
    b=UpperHull(UB[1],pmax,TR);/*! b stores hull of right partition.*/


    //cout<<"returning"<<endl;
    for(auto i:b)a.push_back(i);
   // for(auto i:a)cout<<i.first<<" "<<i.second<<endl;
    return a;
}

/** Gives LowerHull of given set of points 
*
*/

vector<pair<double,double> > LowerHull(vector<pair<double,double> > arr)
{
    assert(arr.size()>0);
    pair<double,double> pmin,pmax;/*! pmin and pmax are points with min and max x coordinates respectively.*/
    vector<pair<double,double> >TL;/*! Stores the list of points to pass to lower hull.*/
    int i;
    int n=arr.size();
    for(i=0;i<arr.size();i++)
    {
        arr[i].x*=-1;
        arr[i].y*=-1;
    }
    pmin=pmax=arr[0];

    for(i=0;i<n;i++)
    {
        if(arr[i].x<pmin.x or (arr[i].x==pmin.x and arr[i].y<pmin.y))
        {
            pmin=arr[i];
        }
        if(arr[i].x>pmax.x or (arr[i].x==pmax.x and arr[i].y<pmax.y) )
        {
            pmax=arr[i];
        }
    }

    TL.push_back(pmin);
    for(i=0;i<n;i++)
    {
        if(pmin.x<arr[i].x and arr[i].x<pmax.x)
        {
            TL.push_back(arr[i]);
        }
    }
    TL.push_back(pmax);

    vector<pair<double,double> > LH=UpperHull(pmin,pmax,arr);/*! Stores the lower hull.*/
    //LH.push_back(pmin);
    //LH.push_back(pmax);
    for(i=0;i<LH.size();i++)
    {

        LH[i].first*=-1;
        LH[i].second*=-1;
    }
    return LH;
}
