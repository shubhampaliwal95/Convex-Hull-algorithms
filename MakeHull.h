#ifndef MakeHull
//#include "MoM.cpp"
using namespace std;
#define MakeHull
bool isLeft(pair<double,double> A,pair<double,double>B, pair<double,double>M);
bool isRight(pair<double,double> A,pair<double,double>B, pair<double,double>M);
vector<pair<double,double> > UpperHull(pair<double,double>pmin,pair<double,double>pmax,vector<pair<double,double> > &T);
vector<pair<double,double> > LowerHull(vector<pair<double,double> > arr);
#endif

