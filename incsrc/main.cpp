#include <iostream>
#include <string>
#include <array>
#include "Mathril.h"


int main()
{
    Mat2 a(1,2,3,4);
    Mat2 b(0,1,2,3);
    Mat2 c(-1,0,1,2);

    Mat2 yo = a + b + c;
    
    std::cout << yo << std::endl;
    
    Quat yolo;

    std::cout << yolo << std::endl;

    int arr[] = {1,2,3,4};

    int marr[] = {-1,-2,-3,-4};

    std::cout << "address : " << arr << " & " << marr << std::endl;

    std::move(arr, arr+4, marr);


    std::cout << "address : " << arr << " & " << marr << std::endl;


    return 0;
}
