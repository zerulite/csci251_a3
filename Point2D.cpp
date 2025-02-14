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

int Point2D::getX() const
{
    return x;
}

int Point2D::getY() const
{
    return y;
}

double Point2D::getScalarValue() const
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

bool Point2D::operator==(const Point2D &other) const
{
    return this->getX() == other.getX() && this->getY() == other.getY();
}