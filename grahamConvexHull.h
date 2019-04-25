#ifndef GRAHAMCONVEXHULL_H_INCLUDED
#define GRAHAMCONVEXHULL_H_INCLUDED

#include<iostream>
#include<stdlib.h>
#include<stdio.h>
#include<vector>
#include<iomanip>

#include "point.h"

using namespace std;

Point base;/** This global point is used as the reference for sorting other Points of the array */

/** Comparator function called by the qsort() function in order to sort the Points in given array */
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

    int n;/**< number of points */
    Point points[100005];/**< array of Points */

    /** Parameterised constructor of GrahamConvehHull used to create an object with parameters as number of points and the data points */
    GrahamConvexHull (int a, Point *p)
    {
        n=a;
        for(int i=0; i<n; i++)
            points[i]=p[i];
    }

    int m=1;/** Size of modified array */
    vector<Point> vec;/** Vector to manipulate the data points and store the final points of the Convex Hull */
    int vsize = 0;/** Variable to hold the size of vector instead of continuously calling vector.size() function */

    /** This function is used to find the Base Point i.e the point with the least y-coordinate. If there are more 
    than one such points, we choose the one with the least x-coordinate from amongst them. We then sort the other points with 
    respect to the base point in the increasing order of the counterclockwise polar angle between that point and the base point. */
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

        /** swapping the first point of array with the obtained base point */
        swap(points[0], points[pos_min]);
        base = points[0];

        /** sorting the array points using inbuilt function qsort() whose comparator function has been defined previously */
        qsort(&points[1], n-1, sizeof(Point), cmp);
    }

    /** This function is used to find points which have the same polar angle with the Base Point. If there are are more than 
    1 point with the same polar angle, we retain only that one with the maximum squared euclidian distance from the Base Point 
    and discard all other points. The function return -1 if there are less than 3 points left after the  modification of the array 
    which denotes that a Convex Hull is not possible, else returns 0. */
    int modifyArray()
    {
        for (int i=1; i<n; i++)
        {
            while (i < n-1 && base.orientation(points[i], points[i+1]) == 0)
                i++;

            points[m] = points[i];
            m++;
        }

        /** If there are less than 3 points after modification, then a convex hull is not possible and the program will end abruptly after printing the error. */
        if(m<3)
            return -1;

        return 0;
    }

    /** In this function, we denote a 'current' and 'previous' point which are the last element of vector and next-to-last element 
    of the vector respectively. We then iterate through the modified array and remove points which do not have a counterclockwise orientation 
    with respect to the 'previous' and 'current' point. The previous and current are updated after each popping operation. If a point does have a
    counterclockwise orientation, then it is pushed onto the vector. */
    void acceptPoints()
    {
        /** Push the first three points of the modified array into the solution vector */
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
                /** Pop current if the point does not have a counterclockwise orientation with the triplet(previous, current, new). */
                vec.pop_back();
                vsize--;

                /** Update the current and previous variables */
                previous = vec[vsize-2];
                current = vec[vsize-1];
            }

            /** Add new point to solution vector when it makes a counterclockwise orientation with respect to current and previous points. */
            vec.push_back(points[i]);
            vsize++;
        }
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
};

#endif // GRAHAMCONVEXHULL_H_INCLUDED
