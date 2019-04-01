#include<string>
#include<vector>
#include<utility>
#include<stdlib.h>
#include "Graham.h"
#include "Stack.h"
using namespace std;
pair<int,int> reference;
int new_size;
Graham::Graham(vector< pair<int,int> > input)
{
	this->input=input;
}
int Graham::lowestPoint()
{	
	int lowest = input[0].second, min = 0; 
	int n=input.size();
	int i;
	for ( i = 1; i < n; i++) 
	   { 
	     int y = input[i].second; 
	  
	     // Pick the bottom-most or chose the left 
	     // most point in case of tie 
	     if ((y < lowest) || (lowest == y && 
	         input[i].first < input[min].first)) 
	        lowest = input[i].second, min = i; 
	   }
    reference = make_pair(input[i].first,input[i].second);
	return min;  

}
int squaredDistance(pair<int,int> x,pair<int,int> y)
{
	return (x.first - y.first)*(x.first - y.first) + 
          (x.second - y.second)*(x.second - y.second); 
}
int orientation(pair<int,int> p,pair<int,int> q,pair<int,int> r)
{
	int val = (q.second - p.second) * (r.first - q.first) - 
              (q.first - p.first) * (r.second - q.second); 
  
    if (val == 0) return 0;  // colinear 
    return (val > 0)? 1: 2; // clock or counterclock wise 
}
int comparator(const void* vp1, const void* vp2)
{
	pair<int,int> *p1 = (pair<int,int>*)(vp1); 
   	pair<int,int> *p2 = (pair<int,int>*)(vp2); 
  
   	// Find orientation 
   	int o = orientation(reference, *p1, *p2); 
   	if (o == 0) 
     return (squaredDistance(reference, *p2) >= squaredDistance(reference, *p1))? -1 : 1; 
  
   	return (o == 2)? -1: 1; 
}
void Graham::sortPolarAngle(int index)
{	//vector<pair<int,int> >::iterator it;
	qsort(&input[index],input.size()-1,sizeof(pair<int,int>),comparator);
	/*cout<<"Sorted are:"<<endl;
	for(int i=0;i<input.size();i++)
		cout<<input[i].first<<" "<<input[i].second<<endl;*/

}
bool Graham::modify()
{	
  int n=input.size();
	int m = 1; // Initialize size of modified array 
   for (int i=1; i<n; i++) 
   { 
       // Keep removing i while angle of i and i+1 is same 
       // with respect to p0 
       while (i < n-1 && orientation(reference, input[i], 
                                    input[i+1]) == 0) 
          i++; 
  
  
       input[m] = input[i]; 
       m++;  // Update size of modified array 
   }
   new_size=m;
   if(m<3)
   return false;
   return true; 
}
pair<int,int> nextToTop(Stack &s) 
{ 
    pair<int,int> p = s.top(); 
    s.pop(); 
    pair<int,int> res = s.top(); 
    s.push(p); 
    return res; 
}
void Graham::convexHull()
{
	Stack s;
  s.push(input[0]); 
  s.push(input[1]); 
  s.push(input[2]); 
	for (int i = 3; i < new_size; i++) 
   { 
      // Keep removing top while the angle formed by 
      // points next-to-top, top, and points[i] makes 
      // a non-left turn 
      while (orientation(nextToTop(s), s.top(), input[i]) != 2) 
         s.pop(); 
      s.push(input[i]); 
   } 
  
   // Now stack has the output points, print contents of stack 
   cout<<"Convex hull points are:"<<endl;
   while (s.size()!=0) 
   { 
       pair<int,int> p = s.top(); 
       cout << "(" << p.first << ", " << p.second <<")" << endl; 
       s.pop(); 
   } 
}
