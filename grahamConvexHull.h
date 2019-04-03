#ifndef GRAHAMCONVEXHULL_H_INCLUDED
#define GRAHAMCONVEXHULL_H_INCLUDED

#include<iostream>
#include<stdlib.h>
#include<stdio.h>
#include<vector>
#include<iomanip>
#include "point.h"

using namespace std;

// global Point to use as reference for the sorting of other points
Point base;

// function used by qsort() to sort an array of points with respect to the first point
int cmp(const void *vp1, const void *vp2)
{
   Point *p1 = (Point *)vp1;
   Point *p2 = (Point *)vp2;

   int val = base.orientation(*p1, *p2);
   if (val == 0)
     return (base.distance(*p2) >= base.distance(*p1))? -1 : 1;

   return val;
}


class GrahamConvexHull
{
public:

    int n;
    Point points[100];

    // constructor to create an object with parameters as number of points and the points themselves
    GrahamConvexHull (int a, Point *p)
    {
        n=a;
        for(int i=0; i<n; i++)
            points[i]=p[i];
    }

    int m=1;
    vector<Point> vec;
    int vsize = 0;

    // function to find the base point i.e the point with the least y-coordinate and then sort the other points with respect to the increasing counterclockwise polar angle between them and the base point
    void getBaseAndSort()
    {
        int y_min = points[0].y;
        int pos_min = 0;

        for(int i=1; i<n; i++)
        {
            int y_coord = points[i].y;
            if((y_coord < y_min) || ((y_coord == y_min ) && (points[i].x < points[pos_min].x)))
            {
                y_min = y_coord;
                pos_min = i;
            }
        }

        // swap the first point of array with the obtained base point
        swap(points[0], points[pos_min]);
        base = points[0];
        qsort(&points[1], n-1, sizeof(Point), cmp);
    }

    // function to find points which have the same polar angle with the base point and only retain the furthest in distance of all those points
    int modifyArray()
    {
        for (int i=1; i<n; i++)
        {
            while (i < n-1 && base.orientation(points[i], points[i+1]) == 0)
                i++;

            points[m] = points[i];
            m++;
        }

        // if there are less than 3 points after modification, then a convex hull is not possible
        if(m<3)
            return -1;

        return 0;
    }

    // function to iterate through the modified array and remove points which do not have a counterclockwise orientation with respect to the 'previous' and 'current' point.
    void acceptPoints()
    {
        // push the first three points into the solution vector
        vec.push_back(points[0]);
        vec.push_back(points[1]);
        vec.push_back(points[2]);
        vsize=3;

        for (int i = 3; i < m; i++)
        {
            Point previous = vec[vsize-2];
            Point current = vec[vsize-1];

            while(previous.orientation(current, points[i]) != -1)
            {
                vec.pop_back();
                vsize--;

                //update the current and previous points
                previous = vec[vsize-2];
                current = vec[vsize-1];
            }

            // add new point to solution vector when it makes a counterclockwise orientation wrt current and previous
            vec.push_back(points[i]);
            vsize++;
        }
    }

    // function to print the points from solution vector which are part of the Convex Hull
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
};

#endif // GRAHAMCONVEXHULL_H_INCLUDED
