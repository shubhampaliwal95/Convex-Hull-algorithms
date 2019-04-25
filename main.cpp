#include <iostream>
#include<bits/stdc++.h>
#include "MoM.h"
#include "MakeHull.h"

#define x first
#define y second

using namespace std;

int main()
{

    //cout<<"Enter n"<<endl;
    //int n;
    //cin>>n;
    freopen("Input.txt","r",stdin);
    freopen("Preciseinput.txt","w",stdout);
    vector<pair<double,double>>arr,TU,TL;// Store points, Upper hull point list and Lower hull point list
    int i;
     pair<double,double>temp;
    //cout<<"Enter points"<<endl;
    while(cin>>temp.first>>temp.second)
    {   cout<<fixed<<setprecision(6)<<temp.first<<" "<<temp.second<<endl;
        arr.push_back(temp);
    }
    freopen("Output_KPS.txt","w",stdout);
    int n=arr.size();
    pair<double,double> pmin=arr[0],pmax=arr[0];
    for(i=0;i<n;i++)
    {
        if(arr[i].x<pmin.x or (arr[i].x==pmin.x and arr[i].y>pmin.y))
        {
            pmin=arr[i];
        }
        if(arr[i].x>pmax.x or (arr[i].x==pmax.x and arr[i].y>pmax.y) )
        {
            pmax=arr[i];
        }
    }
    TU.push_back(pmin);
    for(i=0;i<n;i++)
    {
        if(pmin.x<arr[i].x and arr[i].x<pmax.x)
        {
            TU.push_back(arr[i]);
        }
    }
    TU.push_back(pmax);
    vector<pair<double,double> > UH, LH,ans;


    UH=UpperHull(pmin,pmax,TU);/*! Stores upper hull.*/
    UH.push_back(pmin);
    UH.push_back(pmax);

    //cout<<"UH is below"<<endl;
    //for(auto i:UH)cout<<i.first<<" "<<i.second<<endl;


    LH=LowerHull(arr);/*! Stores lower hull.*/



    //cout<<"LH is below"<<endl;
    //for(auto i:LH)cout<<i.first<<" "<<i.second<<endl;

    //cout<<"Ans is:"<<endl;
    UH.insert(UH.end(),LH.begin(),LH.end());

    int flag=true;
    for(auto i:UH)
    {
        if(abs(i.first-pmin.first)<=0.000001 and abs(i.second-pmin.second)<=0.000001)flag=false;
    }
    if(flag)
        ans.push_back(pmin);
    cout<<fixed<<setprecision(6);
    ans.insert(ans.end(),UH.begin(),UH.end());
    
        for(auto i:ans)cout<<i.first<<" "<<i.second<<endl;
    //cout<<pmin.x<<" "<<pmin.y<<endl;

    /*
    Testing MoM.
    int q;
    cout<<"Enter queries"<<endl;
    cin>>q;
    int k;

    while(q--)
    {
        cout<<"Which largest?"<<endl;
        cin>>k;
        temp=kthSmallest(arr,0,n-1,k);
        cout<<temp.first<<" "<<temp.second<<endl;
    }
    */
    return 0;

}
