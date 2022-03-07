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

        friend std::ostream& operator<<(std::ostream& os, const Vec2& v);

};

class Vec3
{
    private:
        float* data;
    public:
        Vec3();
        Vec3(float x, float y, float z);
        Vec3(Vec3&);
        Vec3(Vec3&&);
        ~Vec3();

        Vec3& operator=(Vec3&);
        Vec3& operator=(Vec3&&);

        float& operator[](int);

        friend Vec3 operator+(Vec3& v, Vec3& w);
        friend Vec3 operator+(Vec3& v, Vec3&& w);
        friend Vec3 operator+(Vec3&& v, Vec3& w);
        friend Vec3 operator+(Vec3&& v, Vec3&& w);

        friend Vec3 operator-(Vec3& v, Vec3& w);
        friend Vec3 operator-(Vec3& v, Vec3&& w);
        friend Vec3 operator-(Vec3&& v, Vec3& w);
        friend Vec3 operator-(Vec3&& v, Vec3&& w);
        
        friend float operator*(Vec3& v, Vec3& w);
        friend float operator*(Vec3& v, Vec3&& w);
        friend float operator*(Vec3&& v, Vec3& w);
        friend float operator*(Vec3&& v, Vec3&& w);
       
        friend Vec3 operator%(Vec3& v, Vec3& w);
        friend Vec3 operator%(Vec3& v, Vec3&& w);
        friend Vec3 operator%(Vec3&& v, Vec3& w);
        friend Vec3 operator%(Vec3&& v, Vec3&& w);
        
        friend Vec3 operator*(float, Vec3&);
        friend Vec3 operator*(float, Vec3&&); 

        friend std::ostream& operator<<(std::ostream& os, const Vec3& v);
};

#endif
