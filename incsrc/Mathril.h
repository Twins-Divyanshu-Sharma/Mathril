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

        friend std::ostream& operator<<(std::ostream& os, const Mat2& m);
};

class Mat4
{
    private:
         float** data;
    public:
         Mat4();
         Mat4(
                 float m00, float m01, float m02, float m03,
                 float m10, float m11, float m12, float m13,
                 float m20, float m21, float m22, float m23,
                 float m30, float m31, float m32, float m33
             );

         Mat4(Mat4&);
         Mat4(Mat4&&);
         ~Mat4();

         Mat4& operator=(Mat4&);
         Mat4& operator=(Mat4&&);

         float* operator[](int);

         friend Mat4 operator+(Mat4& m, Mat4& w);
         friend Mat4 operator+(Mat4& m, Mat4&& w);
         friend Mat4 operator+(Mat4&& m, Mat4& w);
         friend Mat4 operator+(Mat4&& m, Mat4&& w);

         friend Mat4 operator-(Mat4& m, Mat4& w);
         friend Mat4 operator-(Mat4& m, Mat4&& w);
         friend Mat4 operator-(Mat4&& m, Mat4& w);
         friend Mat4 operator-(Mat4&& m, Mat4&& w);

         friend Mat4 operator*(Mat4& m, Mat4& w);
         friend Mat4 operator*(Mat4& m, Mat4&& w);
         friend Mat4 operator*(Mat4&& m, Mat4& w);
         friend Mat4 operator*(Mat4&& m, Mat4&& w);

         friend Vec4 operator*(Mat4& m, Vec4& w);
         friend Vec4 operator*(Mat4& m, Vec4&& w);
         friend Vec4 operator*(Mat4&& m, Vec4& w);
         friend Vec4 operator*(Mat4&& m, Vec4&& w);

         friend std::ostream& operator<<(std::ostream& os, const Mat4& m);
};
