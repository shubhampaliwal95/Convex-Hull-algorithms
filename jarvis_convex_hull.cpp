#include<iostream>
#include<stdio.h>
#include<stdlib.h>

/** Including the user made Header files of Point and Convex Hull */
#include "point.h"
#include "jarvisConvexHull.h"

using namespace std;

int main()
{
    int n;/**< number of points */

    freopen("Input.txt","r",stdin);/** Opening the file "Input.txt" in read mode for reading input from stdin */
    freopen("Preciseinput.txt","w",stdout);

    Point p[100005];/**< array of Points */
    double a,b;

    /** Reading input points from file "Input.txt" */
    while(cin>>a>>b)
    {	cout<<fixed<<setprecision(6)<<a<<" "<<b<<endl;
        p[n]=Point(a,b);
        n++;
    }

    freopen("Output_Jarvis.txt","w",stdout);/** Opening the file "Output_Graham.txt" in write mode for writing the output of stdout */


    /** Check if at least 3 points are present. If not, then exit the program abruptly. */
    if(n<3)
    {
        cout<<"enter >=3 points\n";
        return 0;
    }

    /** Pass the number of points and the data points to the constructor of JarvisConvexHull class */
    JarvisConvexHull jarvis(n, p);

    /** Calling member functions */
    jarvis.getLeft();
    jarvis.acceptPoints();
    jarvis.printHull();

    return 0;
}
