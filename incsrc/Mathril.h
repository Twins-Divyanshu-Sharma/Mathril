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

class Mat2
{
    private:
        float** data;
    public:
        Mat2();
        Mat2(float m00, float m01, float m10, float m11);
        Mat2(Mat2&);
        Mat2(Mat2&&);
        ~Mat2();

        Mat2& operator=(Mat2&);
        Mat2& operator=(Mat2&&);

        float* operator[](int); 

        friend Mat2 operator+(Mat2& m, Mat2& w);
        friend Mat2 operator+(Mat2& m, Mat2&& w);
        friend Mat2 operator+(Mat2&& m, Mat2& w);
        friend Mat2 operator+(Mat2&& m, Mat2&& w);

        friend Mat2 operator-(Mat2& m, Mat2& w);
        friend Mat2 operator-(Mat2& m, Mat2&& w);
        friend Mat2 operator-(Mat2&& m, Mat2& w);
        friend Mat2 operator-(Mat2&& m, Mat2&& w);

        friend Mat2 operator*(Mat2& m, Mat2& w);
        friend Mat2 operator*(Mat2& m, Mat2&& w);
        friend Mat2 operator*(Mat2&& m, Mat2& w);
        friend Mat2 operator*(Mat2&& m, Mat2&& w);

        friend Vec2 operator*(Mat2& m, Vec2& v);
        friend Vec2 operator*(Mat2& m, Vec2&& v);
        friend Vec2 operator*(Mat2&& m, Vec2& v);
        friend Vec2 operator*(Mat2&& m, Vec2&& v);

        friend std::ostream& operator<<(std::ostream& os, const Mat2& v);
};
