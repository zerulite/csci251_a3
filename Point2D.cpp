#include "Point2D.h"

using namespace std;

Point2D::Point2D(int x, int y) : x(x), y(y)
{
    setDistFrOrigin();
}

Point2D::~Point2D()
{
}

void Point2D::setDistFrOrigin()
{
    double distFrOrigin = sqrt(pow(getX(), 2) + pow(getY(), 2));

    this->distFrOrigin = distFrOrigin;
}

int Point2D::getX()
{
    return x;
}

int Point2D::getY()
{
    return y;
}

double Point2D::getScalarValue()
{
    return distFrOrigin;
}

int Point2D::setX(int x)
{
    this->x = x;
    setDistFrOrigin();
    return x;
}

int Point2D::setY(int y)
{
    this->y = y;
    setDistFrOrigin();
    return y;
}

ostream &operator<<(ostream &os, Point2D &point)
{
    os << "[" << setw(4) << right << point.getX() << "," << setw(4) << right << point.getY() << "]";
    os << setw(3) << "" << point.getScalarValue();
    return os;
}

bool operator==(Point2D &a, Point2D &b)
{
    return a.getX() == b.getX() && a.getY() == b.getY();
}