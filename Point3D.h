#ifndef POINTTHREED_H
#define POINTTHREED_H

#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
#include <cmath>
#include <iomanip>

#include "Point2D.h"

using namespace std;

class Point3D : public Point2D
{
protected:
    int z;
    void setDistFrOrigin();

public:
    Point3D(int x, int y, int z);
    ~Point3D();

    int getZ();
    int setZ(int z);
    friend ostream &operator<<(ostream &os, Point3D &point);
};

#endif