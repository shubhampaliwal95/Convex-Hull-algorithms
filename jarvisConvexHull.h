#ifndef JARVISCONVEXHULL_H_INCLUDED
#define JARVISCONVEXHULL_H_INCLUDED

#include<iostream>
#include<stdlib.h>
#include<stdio.h>
#include<vector>
#include<iomanip>
#include "point.h"

using namespace std;

class JarvisConvexHull
{

public:

    int n;
    Point points[100];

    // constructor to create an object with parameters as the number of points and the points themselves
    JarvisConvexHull (int a, Point *p)
    {
        n = a;
        for(int i=0; i<n; i++)
            points[i]=p[i];
    }

    int m=1;
    int left_pos = 0;
    vector<Point> vec;
    int vsize = 0;

    // function to get the left-most point i.e the point with the least x-coordinate
    void getLeft()
    {
        for(int i=0; i<n; i++)
        {
            if(points[i].x < points[left_pos].x)
                left_pos=i;
        }
    }

    // function to check and accept the points which will be part of the convex hull
    void acceptPoints()
    {
        int p = left_pos, q;

        // loop to run start from the leftmost point and run through potential points in a counterclockwise order
        do{
            vec.push_back(points[p]);
            vsize++;

            q=(p+1)%n;

            // obtain a point q such that orientation of (p, i, q) is counterclockwise. Update the point q if any point 'i' is more counterclockwise
            for(int i=0; i<n; i++)
            {
                if(points[p].orientation(points[i],points[q]) == -1)
                    q=i;
            }

            // setting p=q to add q to hull in the next iteration and search for the next point with q as the new start
            p=q;
        }while( p != left_pos);
    }

    // function to print the points that are part of the convex hull
    void printHull()
    {
        while(vec.empty() == false)
        {
            Point temp = vec[vsize-1];
            vec.pop_back();
            vsize--;
            cout<<fixed<<setprecision(6);
            cout<<temp.x<<" "<<temp.y<<"\n";
        }
    }
};// end JarvisConvexHull

#endif // JARVISCONVEXHULL_H_INCLUDED
