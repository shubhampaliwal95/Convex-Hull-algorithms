#include<string>
#include<vector>
#include<utility>
#include "Stack.h"
using namespace std;
Stack::Stack()
{
	
}
int Stack::size()
{
	return st.size();
}
void Stack::push(int x,int y)
{
	st.push_back(make_pair(x,y));
}
void Stack::pop()
{
	st.pop_back();
}
pair<int,int> Stack::top()
{
	int n=size();
	return st[n-1];
}