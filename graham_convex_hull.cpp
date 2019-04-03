#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include "point.h"
#include "grahamConvexHull.h"

using namespace std;

int main()
{
    int n;//number of points

    freopen("Input.txt","r",stdin);
    freopen("Preciseinput.txt","w",stdout);

    Point p[10000];
    double a,b;
    int j=0;

    //read input points from file "Input.txt"
    while(cin>>a>>b)
    {
        cout<<fixed<<setprecision(6)<<a<<" "<<b<<endl;
        p[j]=Point(a,b);
        j++;
    }

    freopen("Output_Graham.txt","w",stdout);

    n=j;
    if(n<3)//check if at least 3 points are present
    {
    	cout<<"enter >=3 points\n";
    	return 0;
    }

    GrahamConvexHull graham(n, p);
    graham.getBaseAndSort();

    // check if a convex hull is possible or not
    int check = graham.modifyArray();
    if(check == -1)
    {
        cout<<"Convex Hull not possible!\n";
        exit(1);
    }

    graham.acceptPoints();
    graham.printHull();

    return 0;
}
