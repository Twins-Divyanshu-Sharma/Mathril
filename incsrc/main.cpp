#include <iostream>
#include <string>
#include "Mathril.h"

int main()
{


    Mat4 m(6,6,6,6,
            6,6,6,6,
            6,6,6,6,
            6,6,6,6);


     Mat4 w(1,0,0,0,
            0,1,0,0,
            0,0,1,0,
            0,0,0,1);


   Mat4 r = m*w*w*w*w*w; 

  //  Vec4 r = m*v + m*v + m*v;

//    std::cout << r[0]<<" "<<r[1]<< " "<<r[2]<<" "<<r[3] << std::endl;

   std::cout <<r;
    return 0;
}
