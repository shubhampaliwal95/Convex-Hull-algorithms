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

    int n;/**< number of points */
    Point points[100005];/**< array of Points */

    /** Parameterised constructor of GrahamConvehHull used to create an object with parameters as number of points and the data points */
    JarvisConvexHull (int a, Point *p)
    {
        n = a;
        for(int i=0; i<n; i++)
            points[i]=p[i];
    }


    int left_pos = 0;/** Variable to maintian the index number of the left-most Point in the array of Points. */

    vector<Point> vec;/** Vector to manipulate the data points and store the final points of the Convex Hull */
    int vsize = 0;/** Variable to hold the size of vector instead of continuously calling vector.size() function */

    /** This function is used to find the Left-most Point i.e the point with the least x-coordinate. If there are more 
    than one such points, we choose the one with the lower index number amongst them. */
    void getLeft()
    {
        for(int i=0; i<n; i++)
        {
            if(points[i].x < points[left_pos].x)
                left_pos=i;
        }
    }

    /* This function is used to check and accept the points which will be part of the convex hull. We start from the Left-most point obtained above 
    and push it onto the solutoin vector. Then we move to the next point 'q' in a counterclockwise order. We iterate through all the points and search 
    for a point 'i' such that the orientation od (p, i, q) is counterclockwise and update q=i if we obtain such a point. We then set this point as the new
    left-most point and run this in a loop until we reach the original left-most point. */
    void acceptPoints()
    {
        int p = left_pos, q;

        /** Loop to start from the leftmost point and run through potential points in a counterclockwise order. */
        do{
            vec.push_back(points[p]);
            vsize++;

            q=(p+1)%n;

            /* Obtain a point i such that orientation of (p, i, q) is counterclockwise. Update the point q if any such point 'i' which is more counterclockwise
            is found. */
            for(int i=0; i<n; i++)
            {
                if(points[p].orientation(points[i],points[q]) == -1)
                    q=i;
            }

            /** Setting p=q to make q the next left-most point and have it added to hull in the next iteration. Then search for the next point with q 
            as the new start. */
            p=q;
        }while( p != left_pos);
    }

    /** This function is used to print the points from the solution vector which make up the Convex Hull. We keep popping points from
    the vector and printing them till the vector is empty. */
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
