#ifndef LINE3D_H
#define LINE3D_H

#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
#include <cmath>

#include "Point3D.h"

using namespace std;

class Line3D
{
protected:
    Point3D pt1;
    Point3D pt2;
    double length;

    void setLength();

public:
    Line3D(Point3D pt1, Point3D pt2);
    ~Line3D();

    Point3D getPt1();
    Point3D getPt2();
    double getScalarValue();

    Point3D setPt1(Point3D pt1);
    Point3D setPt2(Point3D pt2);

    friend ostream &operator<<(ostream &os, Line3D &line);
};

#endif