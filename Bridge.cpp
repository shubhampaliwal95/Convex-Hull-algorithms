#include <iostream>
#include<bits/stdc++.h>
#include "MoM.h"

using namespace std;

/** Returns upper bridge of given set of points.
*
*/
vector<pair<double,double> > UpperBridge(vector<pair<double,double>> &arr,pair<double,double> med)
{
    vector<pair<double,double> >ans,maxi;/*! Stores the answer. maxi stores points inside MAX.*/
    if(arr.size()==2)
    {
        if(arr[0]<arr[1])return arr;
        reverse(arr.begin(),arr.end());
        return arr;
    }
    int n=arr.size();
    if(n&1)
    {
        --n;
        ans.push_back(arr[n]);
    }
    int perm[n];/*! Used for shuffling.*/
    for(int i=0;i<n;i++)perm[i]=i;
    int i,j;
    for(i=0;i<n;i++)
    {
        j=rand()%n;
        swap(perm[i],perm[j]);
    }
    vector<pair<pair<double,double>,pair<double,double> > > pairs,small,eq,large; /*! Stores the pairs of points, points in SMALL, points in EQUAL, and points in LARGE respectively.*/
    pair<pair<double,double>,pair<double,double> > temp; /*! Used to populate pairs vector.*/
    for(i=0;i<n and pairs.size()<n;++i)
    {
        if(arr[i]>arr[perm[i]])
        {
            swap(arr[i],arr[perm[i]]);
        }
        temp.first=arr[i];
        temp.second=arr[perm[i]];
        pairs.push_back(temp);
    }

    vector<pair<double, double > > slope;/*! Stores the slope and index.*/
    pair<double,double> pk,pm;

    for(int j=0;j<pairs.size();j++)
    {
        auto i=pairs[j];
        if(i.first.first==i.second.first) // If vertical line
        {
            if(i.first.second>i.second.second)
                ans.push_back(i.first);
            else
                ans.push_back(i.second);
        }
        else
        {
            slope.push_back(make_pair( (i.second.second-i.first.second)/(i.second.first-i.first.first),j*1.0));
        }

    }
    if(slope.size()==0)
    {
        return UpperBridge(ans,med);
    }
    double K=kthSmallest(slope,0,slope.size()-1,( (slope.size()+1)/2) ).first;/*! K'th largest element of slope..*/

    for(auto i:slope)
    {
        if(i.first<K)
            small.push_back(pairs[(int)round(i.second)]);
        else if(abs(i.first-K)<=0.000001)
            eq.push_back(pairs[(int)round(i.second)]);
        else
            large.push_back(pairs[(int)round(i.second)]);
    }

    double maximum=-100000000000;
    for(auto i:arr)
    {
        maximum=max(i.second-K*i.first,maximum);
    }

    for(auto i:arr)
    {
        if( abs(i.second-K*i.first-maximum)<=0.000001)
        {
            maxi.push_back(i);
        }
    }
    pk=pm=maxi[0];
    for(auto i:maxi)
    {
        if(i.first<pk.first)pk=i;
        else if(abs(i.first-pk.first)<=0.000001 and i.second>pk.second)pk=i;

        if(pm.first<i.first)pm=i;
        else if(abs(i.first-pm.first)<=1e-6 and i.second>pk.second)pk=i;
    }

    if(pk.first<=med.first and pm.first >=med.first)
    {
        vector<pair<double,double> > ret = {pk,pm};
        return ret;
    }
    if(pm.first<=med.first)
    {
        for(auto i:large)ans.push_back(i.second);
        for(auto i:eq)ans.push_back(i.second);
        for(auto i:small)ans.push_back(i.first),ans.push_back(i.second);
    }
    if(pk.first>med.first)
    {
        for(auto i:small)ans.push_back(i.first);
        for(auto i:eq)ans.push_back(i.first);
        for(auto i:large)ans.push_back(i.first),ans.push_back(i.second);
    }

    return UpperBridge(ans,med);



}
