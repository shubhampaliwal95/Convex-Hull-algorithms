#include<iostream>
#include "Stack.h"
using namespace std;
int main()
{
	Stack s;
	s.push(1,2);
	pair<int,int> t=s.top();
	cout<<t.first<<endl;
	cout<<s.size()<<endl;
	s.pop();
	cout<<s.size()<<endl;

}