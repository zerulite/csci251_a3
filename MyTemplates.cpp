#include <iostream>

template <typename T>
bool equals(const T &a, const T &b)
{
    return a == b;
}

/* int main()
{
    int x = 5, y = 5;
    double a = 3.14, b = 3.14;
    std::string str1 = "hello", str2 = "hello";

    std::cout << std::boolalpha;
    std::cout << "x equals y: " << equals(x, y) << std::endl;
    std::cout << "a equals b: " << equals(a, b) << std::endl;
    std::cout << "str1 equals str2: " << equals(str1, str2) << std::endl;

    return 0;
} */

template <typename T>
T scalar_difference(const T &a, const T &b)
{
    return a - b;
}