#ifndef LINE2D_H
#define LINE2D_H

#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
#include <cmath>
#include <iomanip>

#include "Point2D.h"

using namespace std;

class Line2D
{
protected:
    Point2D pt1;
    Point2D pt2;
    double length;

    void setLength();

public:
    Line2D(Point2D pt1, Point2D pt2);
    ~Line2D();

    Point2D getPt1();
    Point2D getPt2();
    double getScalarValue();

    Point2D setPt1(Point2D pt1);
    Point2D setPt2(Point2D pt2);

    friend ostream &operator<<(ostream &os, Line2D &line);
};

#endif