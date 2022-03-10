#include <iostream>
#include <string>
#include "Mathril.h"

int main()
{
    Mat2 m(1,2,3,4);
    Mat2 w(1,1,1,1);

    Mat2 r = m*w;

    std::cout<<r[0][0]<<" "<<r[0][1]<<std::endl<<r[1][0]<<" "<<r[1][1]<<std::endl;
    return 0;
}
