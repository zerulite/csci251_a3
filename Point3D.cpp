#include "Point2D.h"
#include "Point3D.h"

using namespace std;

Point3D::Point3D(int x, int y, int z) : Point2D(x, y), z(z)
{
    setDistFrOrigin();
}

Point3D::~Point3D()
{
}

int Point3D::getZ()
{
    return z;
}

void Point3D::setDistFrOrigin()
{
    double distFrOrigin = sqrt(pow(getX(), 2) + pow(getY(), 2) + pow(getZ(), 2));

    this->distFrOrigin = distFrOrigin;
}

int Point3D::setZ(int z)
{
    this->z = z;
    setDistFrOrigin();
    return z;
}

ostream &operator<<(ostream &os, Point3D &point)
{
    os << "[" << setw(4) << right << point.getX() << "," << setw(4) << right << point.getY() << "," << setw(4) << right << point.getZ() << "]";
    os << setw(3) << "" << point.getScalarValue();
    return os;
}

bool operator==(Point3D &a, Point3D &b)
{
    return a.getX() == b.getX() && a.getY() == b.getY() && a.getZ() == b.getZ();
}