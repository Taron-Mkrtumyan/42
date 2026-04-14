#include <iostream>
#include "Fixed.hpp"
#include "Point.hpp"

bool bsp( Point const a, Point const b, Point const c, Point const point);

void test_bsp(std::string name, Point const a, Point const b, Point const c, Point const p, bool expected)
{
    bool result = bsp(a, b, c, p);
    std::cout << "Test: " << name << " -> ";
    if (result == expected)
        std::cout << "✅ PASS" << std::endl;
    else
        std::cout << "❌ FAIL (Expected " << (expected ? "True" : "False") 
                  << ", got " << (result ? "True" : "False") << ")" << std::endl;
}

int main()
{
    // Define a simple triangle: A(0,0), B(10,0), C(5,10)
    Point const a(0, 0);
    Point const b(10, 0);
    Point const c(5, 10);

    // std::cout << a.getX() << ", " << a.getY() << std::endl;
    // std::cout << b.getX() << ", " << b.getY() << std::endl;
    // std::cout << c.getX() << ", " << c.getY() << std::endl;

    // std::cout << "--- Triangle: A(0,0), B(10,0), C(5,10) ---" << std::endl;

    // 1. Point clearly inside
    test_bsp("Point Inside", a, b, c, Point(5.0f, 5.0f), true);

    // 2. Point clearly outside
    test_bsp("Point Outside", a, b, c, Point(12.0f, 5.0f), false);
    test_bsp("Point Far Away", a, b, c, Point(-10.0f, -10.0f), false);

    // 3. Point exactly on an edge (Usually should be false in BSP)
    test_bsp("Point on Edge (AB)", a, b, c, Point(5.0f, 0.0f), false);

    // 4. Point exactly on a vertex (Usually should be false in BSP)
    test_bsp("Point on Vertex (C)", a, b, c, Point(5.0f, 10.0f), false);

    // 5. Point just barely inside (Testing precision)
    test_bsp("Point Barely Inside", a, b, c, Point(5.0f, 0.1f), true);

    // 6. Point just barely outside
    test_bsp("Point Barely Outside", a, b, c, Point(5.0f, -0.1f), false);

    return 0;
}