#include <iostream>

template <typename T>
bool equals(const T &a, const T &b)
{
    return a == b;
}

template <typename T>
T scalar_difference(const T &a, const T &b)
{
    return a - b;
}