#include <iostream>
#include <string>
#include "Mathril.h"

int main()
{

    Mat2 mat(0,1,2,3);
    Vec2 yo(3,4);

    Vec2 ans = mat * yo;

    std::cout << ans << std::endl;

    std::cout << (float)ans << std::endl;

    return 0;
}
