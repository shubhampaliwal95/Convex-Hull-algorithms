#include<vector>
#include<utility>
#include<iostream>
//#include"Stack.h"
using namespace std;
//extern pair<int,int> reference;
class Graham{
	
	public:
		vector< pair<int,int> > input;
	
		Graham(vector<pair<int,int>> input);
		int lowestPoint();

	 	void sortPolarAngle(int index);
	 	
	 	bool modify();
	 	void convexHull();

	 	

};