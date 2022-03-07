/*
 * =====================================================================================
 *
 *       Filename:  Mathril.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  03/04/2022 07:31:34 PM
 *       Revision:  none
 *       Compiler:  g++
 *
 *         Author:  YOUR NAME (Twins), 
 *   Organization:  
 *
 * =====================================================================================
 */
#include "Mathril.h"

Vec2::Vec2()
{
    data = new float[2];
    data[0] = 0;
    data[1] = 0;
}

Vec2::Vec2(float x, float y)
{
    data = new float[2];
    data[0] = x;
    data[1] = y;
}

Vec2::~Vec2()
{
    delete [] data;
}

Vec2::Vec2(Vec2& vec)
{
    data = new float[2];
    data[0] = vec.data[0];
    data[1] = vec.data[1];
}

Vec2::Vec2(Vec2&& vec)
{
    data = vec.data;
    vec.data = nullptr;
}

Vec2& Vec2::operator=(Vec2& vec)
{
    if(this == &vec) return *this;
    data[0] = vec.data[0];
    data[1] = vec.data[1];
    return *this;
}

Vec2& Vec2::operator=(Vec2&& vec)
{
   data = vec.data;
   vec.data = nullptr;
   return *this;
}

float& Vec2::operator[](int n)
{
    if(n >= 0 && n < 3)
        return data[n];
    else
        std::cerr << "Vec2 index " << n << " is out of bounds " << std::endl;
}

Vec2 operator+(Vec2& v, Vec2& w)
{
    return Vec2(v.data[0] + w.data[0], v.data[1] + w.data[1]);
}

Vec2 operator+(Vec2& v, Vec2&& w)
{
    w.data[0] = w.data[0]+v.data[0];
    w.data[1] = w.data[1]+v.data[1];
    return std::move(w);
}

Vec2 operator+(Vec2&& v, Vec2& w)
{
    v.data[0] = w.data[0]+v.data[0];
    v.data[1] = w.data[1]+v.data[1];
    return std::move(v);
}

Vec2 operator+(Vec2&& v, Vec2&& w)
{
    v.data[0] = w.data[0]+v.data[0];
    v.data[1] = w.data[1]+v.data[1];
    return std::move(v);
}


Vec2 operator-(Vec2& v, Vec2& w)
{
    return Vec2(v.data[0] - w.data[0], v.data[1] - w.data[1]);
}

Vec2 operator-(Vec2& v, Vec2&& w)
{
    w.data[0] = v.data[0] - w.data[0];
    w.data[1] = v.data[1] - w.data[1];
    return std::move(w);
}

Vec2 operator-(Vec2&& v, Vec2& w)
{
    v.data[0] = v.data[0] - w.data[0];
    v.data[1] = v.data[1] - w.data[1];
    return std::move(v);
}

Vec2 operator-(Vec2&& v, Vec2&& w)
{
    v.data[0] = v.data[0]-w.data[0];
    v.data[1] = v.data[1]-w.data[1];
    return std::move(v);
}

Vec2 operator*(float s, Vec2& vec)
{
    return Vec2(s*vec.data[0], s*vec.data[1]);
}

Vec2 operator*(float s, Vec2&& vec)
{
    vec.data[0] = s*vec.data[0];
    vec.data[1] = s*vec.data[1];
    return std::move(vec);
}

std::ostream& operator<<(std::ostream& os, const Vec2& v)
{
	os << "[" << v.data[0] << ", " << v.data[1] <<  "]";
	return os;
}

Vec3::Vec3()
{
    data = new float[3];
    for(int i=0; i<3; i++)
        data[i] = 0;
}

Vec3::Vec3(float x, float y, float z)
{
    data = new float[3];
    data[0] = x;
    data[1] = y;
    data[2] = z;
}

Vec3::Vec3(Vec3& vec)
{
    data = new float[3];
    for(int i=0; i<3; i++)
        data[i] = vec.data[i];
} 

Vec3::Vec3(Vec3&& vec)
{
    data = vec.data;
    vec.data = nullptr;
}

Vec3::~Vec3()
{
    delete[] data;
}

Vec3& Vec3::operator=(Vec3& vec)
{
    if(this== &vec) return *this;
    for(int i=0; i<3; i++)
        data[i] = vec.data[i];
     return *this; 
}

Vec3& Vec3::operator=(Vec3&& vec)
{
    data = vec.data;
    vec.data = nullptr;
    return *this;
}

float& Vec3::operator[](int n)
{
   if(n>=0 && n<3)
       return data[n];
   else
       std::cerr << " Vec3 index"<<n<<" out of bounds "<<std::endl;
}

Vec3 operator+(Vec3& v, Vec3& w)
{
    return Vec3(v.data[0]+w.data[0], v.data[1]+w.data[1], v.data[2]+w.data[2]);
}

Vec3 operator+(Vec3& v, Vec3&& w)
{
    for(int i=0; i<3; i++)
        w.data[i] = w.data[i] + v.data[i];
    return std::move(w);
}

Vec3 operator+(Vec3&& v, Vec3& w)
{
    for(int i=0; i<3; i++)
        v.data[i] = w.data[i] + v.data[i];
    return std::move(v);
}

Vec3 operator+(Vec3&& v, Vec3&& w)
{
    for(int i=0; i<3; i++)
        v.data[i] = w.data[i] + v.data[i];
    return std::move(v);
}

Vec3 operator-(Vec3& v, Vec3& w)
{
    return Vec3(v.data[0]-w.data[0], v.data[1]-w.data[1], v.data[2]-w.data[2]);
}

Vec3 operator-(Vec3& v, Vec3&& w)
{
    for(int i=0; i<3; i++)
        w.data[i] = v.data[i] - w.data[i];
    return std::move(w);
}

Vec3 operator-(Vec3&& v, Vec3& w)
{
    for(int i=0; i<3; i++)
        v.data[i] = v.data[i] - w.data[i];
    return std::move(v);
}

Vec3 operator-(Vec3&& v, Vec3&& w)
{
    for(int i=0; i<3; i++)
        v.data[i] = v.data[i] + w.data[i];
    return std::move(v);
}

float operator*(Vec3& v, Vec3& w)
{
    return (v.data[0]*w.data[0] + v.data[1]*w.data[1] + v.data[2]*w.data[2]); 
}

float operator*(Vec3& v, Vec3&& w)
{
    return (v.data[0]*w.data[0] + v.data[1]*w.data[1] + v.data[2]*w.data[2]); 
}


float operator*(Vec3&& v, Vec3& w)
{
    return (v.data[0]*w.data[0] + v.data[1]*w.data[1] + v.data[2]*w.data[2]); 
}


float operator*(Vec3&& v, Vec3&& w)
{
    return (v.data[0]*w.data[0] + v.data[1]*w.data[1] + v.data[2]*w.data[2]); 
}

Vec3 operator%(Vec3& a, Vec3& b)
{
	return Vec3(a.data[1]*b.data[2] -a.data[2]*b.data[1], a.data[2]*b.data[0] - a.data[0]*b.data[2], a.data[0]*b.data[1]-a.data[1]*b.data[0]);
}

Vec3 operator%(Vec3& a, Vec3&& b)
{
	float x = a.data[1] * b.data[2] - a.data[2] * b.data[1];
	float y = a.data[2] * b.data[0] - a.data[0] * b.data[2];
	float z = a.data[0] * b.data[1] - a.data[1] * b.data[0];
	b[0] = x;	b[1] = y;	b[2] = z;
	return std::move(b);
}

Vec3 operator%(Vec3&& a, Vec3& b)
{
	float x = a.data[1] * b.data[2] - a.data[2] * b.data[1];
	float y = a.data[2] * b.data[0] - a.data[0] * b.data[2];
	float z = a.data[0] * b.data[1] - a.data[1] * b.data[0];
	a[0] = x;	a[1] = y;	a[2] = z;
	return std::move(a);
}

Vec3 operator%(Vec3&& a, Vec3&& b)
{
	float x = a.data[1] * b.data[2] - a.data[2] * b.data[1];
	float y = a.data[2] * b.data[0] - a.data[0] * b.data[2];
	float z = a.data[0] * b.data[1] - a.data[1] * b.data[0];
	b[0] = x;	b[1] = y;	b[2] = z;
	return std::move(b);
}

Vec3 operator*(float s, Vec3& v)
{
    return Vec3(s*v.data[0], s*v.data[1], s*v.data[2]);
}

Vec3 operator*(float s, Vec3&& v)
{
    for(int i=0; i<3; i++)
        v.data[i] = s*v.data[i];
    return std::move(v);
}

std::ostream& operator<<(std::ostream& os, const Vec3& v)
{
	os << "[" << v.data[0] << ", " << v.data[1] << ", " << v.data[2] << "]";
	return os;
}

