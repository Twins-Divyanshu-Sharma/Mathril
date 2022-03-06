#include <iostream>
#include <string>
#include "Mathril.h"

int main()
{
    std::cout << "-----Init" << std::endl;

    Vec2 a(2,2);
    Vec2 b(3,5);
    Vec2 c(1,4);
    
    std::cout << "------Close " << std::endl;

    Vec2 d = a + b + c;

    std::cout << "(" << d[0] << "," << d[1] << ")" << std::endl;
    return 0;
}
