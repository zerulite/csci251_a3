#include "Point3D.h"
#include "Line3D.h"

using namespace std;

Line3D::Line3D(Point3D pt1, Point3D pt2) : pt1(pt1), pt2(pt2)
{
    setLength();
}

Line3D::~Line3D()
{
}

void Line3D::setLength()
{
    double length = sqrt(pow(pt1.getX() - pt2.getX(), 2) + pow(pt1.getY() - pt2.getY(), 2) + pow(pt1.getZ() - pt2.getZ(), 2));

    this->length = length;
}

Point3D Line3D::getPt1()
{
    return pt1;
}

Point3D Line3D::getPt2()
{
    return pt2;
}

double Line3D::getScalarValue()
{
    return length;
}

Point3D Line3D::setPt1(Point3D pt1)
{
    this->pt1 = pt1;
    setLength();
    return pt1;
}

Point3D Line3D::setPt2(Point3D pt2)
{
    this->pt2 = pt2;
    setLength();
    return pt2;
}

ostream &operator<<(ostream &os, Line3D &line)
{
    Point3D pt1 = line.getPt1();
    Point3D pt2 = line.getPt2();

    os << "[" << setw(4) << right << pt1.getX() << "," << setw(4) << right << pt1.getY() << "," << setw(4) << right << pt1.getZ() << "]";
    os << setw(3) << "";
    os << "[" << setw(4) << right << pt2.getX() << "," << setw(4) << right << pt2.getY() << "," << setw(4) << right << pt2.getZ() << "]";
    os << setw(3) << "" << line.getScalarValue();

    return os;
}

bool operator==(Line3D &a, Line3D &b)
{
    return a.getPt1() == b.getPt1() && a.getPt2() == b.getPt2();
}