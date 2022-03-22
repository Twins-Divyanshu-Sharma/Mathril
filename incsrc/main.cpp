#include <iostream>
#include <string>
#include "Mathril.h"

int main()
{

    Mat3 mat(2,1,4, 3,2,7, 8,9,0);
    Vec3 yo(1,1,1);
    Mat3 id(1,0,0, 0,1,0, 0,0,1);

    Mat3 t = mat * id * id * id;

    std::cout << t<<std::endl;



   // std::cout << (float)ans << std::endl;
   //

    for(int i=0; i<9; i++)
        std::cout << t[0][i] << std::endl;

    return 0;
}
