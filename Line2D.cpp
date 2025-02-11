#include "Point2D.h"
#include "Line2D.h"

using namespace std;

Line2D::Line2D(Point2D pt1, Point2D pt2) : pt1(pt1), pt2(pt2)
{
    setLength();
}

Line2D::~Line2D()
{
}

void Line2D::setLength()
{
    double length = sqrt(pow(pt1.getX() - pt2.getX(), 2) + pow(pt1.getY() - pt2.getY(), 2));

    this->length = length;
}

Point2D Line2D::getPt1()
{
    return pt1;
}

Point2D Line2D::getPt2()
{
    return pt2;
}

double Line2D::getScalarValue()
{
    return length;
}

Point2D Line2D::setPt1(Point2D pt1)
{
    this->pt1 = pt1;
    setLength();
    return pt1;
}

Point2D Line2D::setPt2(Point2D pt2)
{
    this->pt2 = pt2;
    setLength();
    return pt2;
}

ostream &operator<<(ostream &os, Line2D &line)
{
    Point2D pt1 = line.getPt1();
    Point2D pt2 = line.getPt2();

    os << "[" << setw(4) << right << pt1.getX() << "," << setw(4) << right << pt1.getY() << "]";
    os << setw(3) << "";
    os << "[" << setw(4) << right << pt2.getX() << "," << setw(4) << right << pt2.getY() << "]";
    os << setw(3) << "" << line.getScalarValue();

    return os;
}