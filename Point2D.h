#ifndef POINTTWOD_H
#define POINTTWOD_H

#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
#include <cmath>
#include <iomanip>

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

    int getX() const;
    int getY() const;
    double getScalarValue() const;

    int setX(int x);
    int setY(int y);

    friend ostream &operator<<(ostream &os, Point2D &point);
    bool operator==(const Point2D &other) const;
};

#endif