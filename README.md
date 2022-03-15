![MathShieldSmall](https://user-images.githubusercontent.com/47611483/158402464-265a51a3-9104-4d19-8c81-6122ea4b5fd1.png)


# ___MATHRIL___
As light as addition, as hard as Calculus\
\
Mathril is a mathematics library for game programming in C++. Calculations are similar to regular mathematics. It heavily uses operator overloading with r-value reference to thoroughly optimize performance and reduce memory consumption. Equiped with this Mathril armor, you are now ready to face any danger lurking in world of game engine programming. Go forth, a new adventure awaits.

# Installation
Just include Mahtril.h and Mathril.cpp from incsrc folder of this project, to your project

# Vectors
## Vec2 (2 dimensional vector)
Its made up of two floats, x and y
### Initialization
```
Vec2 vec; // default constructor, initializes elements with 0
Vec2 vec(10,20); // argument constructor
```
### Access
```
vec[0] = 10; // accessing x element of vector
vec[1] = -5; // accessing y element of vector
```
### Calculations
Use + to add two vectors\
Use - to substract two vectors\
Use * to scale vectors like : scalar * vector. Note: scalar must be Left operand and vector must be right operand
```
Vec2 a(10,10);
Vec2 b(-10,-10);
b = 5*b; // scalar multiplication
Vec2 c = -2*a + b; // addition (substraction is similar)
```
### Magnitude (length) of vector
You can use explicit type casting to float on a Vec2 to obtain it's magnitude (length)
```
Vec2 vec(20,10); // creating a vector
float magnitude = (float)vec; // explicit typecast to float
```
### Output to std::cout
Yes, yes, you can view your vector too in the console, just dont forget std::endl at the end.
```
std::cout << vec << std::endl;
```

## Vec4 ( four dimensional vector )
It is similar to Vec2 just contains four floats.

## Vec3 ( three dimensional vector )
It is similar to Vec2 and Vec4 but it has additional two functions:
### Dot product:
Use * to find dot product of two Vec3
```
Vec3 a(1,2,3);
Vec3 b(4,5,6);

float dotProduct = a * b;
```
### Cross product:
Use % (it looks similar to X, the symbol of cross product) to find cross product of two Vec3
```
Vec3 a(3,0,4);
Vec3 b(1,2,1);

Vec3 crossProduct = a % b;
```

# Matrices
We will use Mat3 do discuss matrix, Mat2 and Mat4 are similar
## Mat3
### Initialization
You can use default constructor, which initializes the matrix to 0\
You can also use arguement constructor, you must fill the matrix row by row
```
Mat3 mat; // default constructor
Mat3 matrix(0,1,2,3,4,5,6,7,8); // arguement constructor
```
### Access
You can access the element of matrix as you access normal 2D array in C, first row then column
```
Mat3 matrix;
for(int row=0; row<3; row++)
{
  for(int col=0; col<3; col++)
  {
     std::cout << matrix[row][col] << ", ";  // accessing the matrix
  }
  std::cout << std::endl;
}
```
### Calculations
Use + to add two matrices\
Use - to subtract two matrices\
Use * to multiply two matrices\
Also use * to multiply Matrix and a Vector of same size. Remember, since Mathril matches regular mathematics, so, Mat3 should be LHS and Vec3 should be RHS
```
Mat3 a,b,c;
Mat3 d = a*b + c; // multiply and add 
Vec3 vec(2,3,4);
Mat3 matrix(1,0,1,-1,2,2,-4,0,-3);
Vec3 vector = matrix * vector; // matrix LHS and vector RHS
```
### Output
You can view your matrix in console too
```
Mat3 matrix;
std::cout << matrix << std::endl;
```

# Quaternion
Use Quat to construct a quaternion
## Quat
### Initialization
You can use default constructor\
Or you can use arguement constructor r, i, j, k
```
Quat q; // default constructor 
Quat quat(1,2,3,4); // r=1, x=2, y=3, z=4
```
### Access
Use [ ] operator to access the elements, [0] for r, [1] for i, [2] for j, [3] for k
```
Quat quat(23,42,11,15);
std::cout << quat[2] << std::endl; // displays 11 in console
```
### Conjugate
Use ~ (unary operator) to get conjugate of quaternion
```
Quat q(1,-2,3,-4);
Quat conjugate = ~q; // becomes 1, 2, -3, 4
```
### Calculations
Use + to add two quaternions\
Use - to substract two quaternions\
Use * to multiply two quaternions\
Use * to scale one quaternion, as usual, scalar must be LHS and quaternion RHS
```
Quat a,b,c;
Quat q = a * b - c; // multiplication and addition
q = 4*q + 6*b; // scale
```
### Magnitude (length)
You can again use explicit type cast to float on Quat in order to get it's magnitude
```
Quat quat(1,2,0,4);
float magnitude = (float)quat;
```
### Normal
You can use normal() to get the normal of a quaternion
```
Quat quat(3,2,5,1);
Quat q = quat.normal(); // q contains normal of quat
```
### Spherical linear interpolation
For animation to work, spherical linear interpolation (slerp) is necessary
```
Quat q,p;
float time = 0.3f;
Quat interpolated = slerp(q, p, time);
```
### Output console
```
Quat q(3,-1,2,4);
std::cout << q << std::endl;
```
It will output :
[3, -1i, 2j , 4k]
