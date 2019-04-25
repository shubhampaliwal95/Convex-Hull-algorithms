#ifndef MoM
//#include "MoM.cpp"
using namespace std;
#define MoM
pair<double,double> findMedian(vector<pair<double,double> >&arr,int n);
int partition(vector<pair<double,double> > &arr,int l,int r,pair<double,double> x);
pair<double,double> kthSmallest(vector<pair<double,double> >&arr,int l,int r,int k);
#endif

