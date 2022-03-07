#ifndef H_M4THR1L_H
#define H_M4THR1L_H

#include <iostream>


class Vec2
{
    private:
        float* data;
    public:
        Vec2();
        Vec2(float x, float y);
        ~Vec2();
        Vec2(Vec2&);
        Vec2(Vec2&&);

        Vec2& operator=(Vec2&);
        Vec2& operator=(Vec2&&);
        
        float& operator[](int);

        friend Vec2 operator+(Vec2& v, Vec2& w);
        friend Vec2 operator+(Vec2& v, Vec2&& w);
        friend Vec2 operator+(Vec2&& v, Vec2& w);
        friend Vec2 operator+(Vec2&& v, Vec2&& w);

        friend Vec2 operator-(Vec2& v, Vec2& w);
        friend Vec2 operator-(Vec2& v, Vec2&& w);
        friend Vec2 operator-(Vec2&& v, Vec2& w);
        friend Vec2 operator-(Vec2&& v, Vec2&& w);

        friend Vec2 operator*(float,Vec2&);
        friend Vec2 operator*(float,Vec2&&);
};


class Vec4
{
    private:
        float* data;
    public:
        Vec4();
        Vec4(float r, float x, float y, float z);
        ~Vec4();
        Vec4(Vec4&);
        Vec4(Vec4&&);

        Vec4& operator=(Vec4&);
        Vec4& operator=(Vec4&&);

        float& operator[](int);

        friend Vec4 operator+(Vec4& v, Vec4& w);
        friend Vec4 operator+(Vec4& v, Vec4&& w);
        friend Vec4 operator+(Vec4&& v, Vec4& w);
        friend Vec4 operator+(Vec4&& v, Vec4&& w);
        

        friend Vec4 operator-(Vec4& v, Vec4& w);
        friend Vec4 operator-(Vec4& v, Vec4&& w);
        friend Vec4 operator-(Vec4&& v, Vec4& w);
        friend Vec4 operator-(Vec4&& v, Vec4&& w);
       
        friend Vec4 operator*(float,Vec4&);
        friend Vec4 operator*(float,Vec4&&);
};

#endif
