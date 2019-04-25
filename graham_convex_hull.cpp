#include<iostream>
#include<stdio.h>
#include<stdlib.h>

/** Including the user made Header files of Point and Convex Hull */
#include "point.h"
#include "grahamConvexHull.h"

using namespace std;

int main()
{
    int n;/**< number of points */

    freopen("Input.txt","r",stdin);
    freopen("Preciseinput.txt","w",stdout);

    Point p[100005];/**< array of Points */
    double a,b;

    /** Reading input points from file "Input.txt" */
    while(cin>>a>>b)
    {	
    	cout<<fixed<<setprecision(6)<<a<<" "<<b<<endl;
        p[n]=Point(a,b);
        n++;
    }

    freopen("Output_Graham.txt","w",stdout);

    /** Check if at least 3 points are present. If not, then exit the program abruptly. */
    if(n<3)
    {
    	cout<<"enter >=3 points\n";
    	return 0;
    }
    
    /** Pass the Data Points and number of points to construtor of GrahamConvexHull class */
    GrahamConvexHull graham(n, p);

    /** Calling member functions */
    graham.getBaseAndSort();
    if(graham.modifyArray() == -1)
    {
        cout<<"Convex Hull not possible!\n";
        exit(1);
    }
    graham.acceptPoints();
	graham.printHull();

    return 0;
}
