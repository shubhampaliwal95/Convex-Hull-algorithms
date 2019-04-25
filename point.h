#ifndef POINT_H_INCLUDED
#define POINT_H_INCLUDED

#include<iostream>
#include<stdio.h>

using namespace std;


class Point
{
public:
    double x,y;/** variables to store the x and y dimensions of the point. */

    /** Constructor to create an instance of a Point when no values are given. This defualt point is initaialised as (0,0) */
    Point()
    {
        x=0;
        y=0;
    }

    /** Parameterised constructor to create an instance of Point which has the dimensions passed as the arguments. */
    Point(double a, double b)
    {
        x=a;
        y=b;
    }

    /** This function is used to check whether the orientation of the triplet of points (p1, p2, p3) is collinear, clockwise or anticlockwise. Here p1
    is the point calling the function.*/
    int orientation(Point p2, Point p3)
    {
        double diff = (p2.y-this->y)*(p3.x-p2.x) - (p2.x-this->x)*(p3.y-p2.y);

        if (diff==0) return 0; //collinear
        else if (diff>0) return 1; //clockwise
        else return -1; //anti-clockwise

    }

    /**This function is used to compute the squared euclidean distance between two points p1 and p2. Here p1 is the point calling the fucntion. */
    double distance(Point p2)
    {
        return (this->x-p2.x)*(this->x-p2.x)+(this->y-p2.y)*(this->y-p2.y);
    }
};//end Point



#endif // POINT_H_INCLUDED
