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
