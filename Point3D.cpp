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

int Point3D::getZ() const
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

// output stream operator
ostream &operator<<(ostream &os, Point3D &point)
{
    os << "[" << setw(4) << right << point.getX() << "," << setw(4) << right << point.getY() << "," << setw(4) << right << point.getZ() << "]";
    os << setw(3) << "" << point.getScalarValue();
    return os;
}

bool Point3D::operator==(const Point3D &other) const
{
    return this->getX() == other.getX() && this->getY() == other.getY() && this->getZ() == other.getZ();
}