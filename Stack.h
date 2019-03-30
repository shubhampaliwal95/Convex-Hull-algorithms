#include<vector>
#include<utility>
using namespace std;
 
class Stack{
	public:

	vector< pair<int,int> > st;
	Stack();
	int size();
	void push(int x,int y);
	void pop();
	pair<int,int> top(); 
};