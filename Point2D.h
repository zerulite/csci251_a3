#ifndef POINTTWOD_H
#define POINTTWOD_H

#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
#include <cmath>

using namespace std;

class Point2D
{
protected:
    int x;
    int y;
    double distFrOrigin;
    virtual void setDistFrOrigin();

public:
    Point2D(int x, int y);
    ~Point2D();

    int getX();
    int getY();
    double getScalarValue();

    int setX(int x);
    int setY(int y);
};

#endif