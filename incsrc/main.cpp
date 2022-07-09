#include <iostream>
#include <string>
#include <array>
#include "Mathril.h"


int main()
{
    Mat2 a(1,1,1,1);
    Mat2 b(2,2,2,2);
    Mat2 c(3,3,3,3);
    Mat2 d(4,4,4,4);
    std::cout << "---------------" << std::endl;

    Mat2 yo = a + b + c + d;
    
    std::cout << yo << std::endl;
    
    return 0;
}
