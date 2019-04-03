#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include "point.h"
#include "jarvisConvexHull.h"

using namespace std;

int main()
{
    int n;// number of points

    freopen("Input.txt","r",stdin);
    freopen("Preciseinput.txt","w",stdout);

    Point p[10000];
    double a,b;
    int j=0;

    // read input from file "Input.txt"
    while(cin>>a>>b)
    {
    	cout<<fixed<<setprecision(6)<<a<<" "<<b<<endl;
        p[j]=Point(a,b);
        j++;
    }

    freopen("Output_Jarvis.txt","w",stdout);

    n=j;
    if(n<3)//check if at least 3 points are present
    {
    	cout<<"enter >=3 points\n";
    	return 0;
    }

    // pass the number of points and the points to the constructor of JarvisConvexHull class
    JarvisConvexHull jarvis(n, p);
    jarvis.getLeft();
    jarvis.acceptPoints();
    jarvis.printHull();

    return 0;
}
