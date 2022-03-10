#include <iostream>
#include <string>
#include "Mathril.h"

int main()
{
   Mat3 identity(1,2,3,
                 2,1,2,
                 3,2,2);

   Mat3 someShit(2,2,2,
                 5,3,1,
                 1,6,7);

   Mat3 mult = identity * someShit;

    
   std::cout << mult << std::endl;

   Mat3 lolt = Mat3(1,2,3,2,1,2,3,2,2) * someShit;

   std::cout << lolt << std::endl;

   Mat3 rort = identity * Mat3(2,2,2,5,3,1,1,6,7);

   std::cout << rort << std::endl;

   return 0;
}
