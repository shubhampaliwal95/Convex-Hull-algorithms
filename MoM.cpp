#include<bits/stdc++.h>
#include "MoM.h"
using namespace std;
/** Given an array, returns the median of the array.
*
*/
pair<double,double> findMedian(vector <pair<double,double> > &arr,int k,int n)
{
    sort(arr.begin()+k,arr.begin()+k+n);
    return arr[n/2];
}
/** Returns the position of element in sorted array using quicksort partition heuristic.
*
*/
int partition(vector< pair<double,double> > &arr,int l,int r,pair<double,double> x)
{
    int i;
    for(i=l;i<r;i++)
    {
        if(arr[i]==x)break;
    }
    swap(arr[i],arr[r]);
    i=l;
    int j;
    for(j=l;j<=r-1;j++)
    {
        if(arr[j]<=x)
        {
            swap(arr[i],arr[j]);
            ++i;
        }
    }
    swap(arr[i],arr[r]);
    return i;
}
/** Returns k'th smallest element in linear time.
*
*/
pair<double,double> kthSmallest(vector<pair<double,double> > &arr,int l,int r,int k)
{

    assert(k>0 and k<=r-l+1);
    //cout<<arr.size()<<" is the size, k="<<k<<" l="<<l<<" r="<<r<<endl;
    int n=r-l+1;

    int i=0;
    vector< pair<double,double> >median((n+4)/5); /*! Stores median.*/
    for(i=0;i<n/5;i++)median[i]=findMedian(arr,l+i*5,5);
    if(i*5<n)
    {
        median[i]=findMedian(arr,l+i*5,n%5);
        ++i;
    }

    pair<double,double> medOfMed=(i==1)?median[i-1]:kthSmallest(median,0,i-1,i/2);/*! Stores median of median.*/
    int pos=partition(arr,l,r,medOfMed);
    //cout<<pos-l<<" "<<k<<endl;
    if(pos-l==k-1)
    {
        //cout<<"Returning"<<endl;
        return arr[pos];
    }
    else if(pos-l>k-1)return kthSmallest(arr,l,pos-1,k);
    else return kthSmallest(arr,pos+1,r,k-pos+l-1);
}

