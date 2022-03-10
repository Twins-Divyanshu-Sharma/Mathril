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

        friend std::ostream& operator<<(std::ostream& os, const Vec4& v);
};


class Mat3
{
    private:
        float **data;
    public:
        Mat3();
        Mat3(float m00, float m01, float m02,
             float m10, float m11, float m12,
             float m20, float m21, float m22);
        Mat3(Mat3&);
        Mat3(Mat3&&);
        ~Mat3();

        Mat3& operator=(Mat3&);
        Mat3& operator=(Mat3&&);

        float* operator[](int);

        friend Mat3 operator+(Mat3& m, Mat3& n);
        friend Mat3 operator+(Mat3& m, Mat3&& n);
        friend Mat3 operator+(Mat3&& m, Mat3& n);
        friend Mat3 operator+(Mat3&& m, Mat3&& n);

        friend Mat3 operator-(Mat3& m, Mat3& n);
        friend Mat3 operator-(Mat3& m, Mat3&& n);
        friend Mat3 operator-(Mat3&& m, Mat3& n);
        friend Mat3 operator-(Mat3&& m, Mat3&& n);

        friend Mat3 operator*(Mat3& m, Mat3& n); 
        friend Mat3 operator*(Mat3& m, Mat3&& n);
        friend Mat3 operator*(Mat3&& m, Mat3& n);
        friend Mat3 operator*(Mat3&& m, Mat3&& n);
  
        friend Vec3 operator*(Mat3& m, Vec3& v);
        friend Vec3 operator*(Mat3& m, Vec3&& v);
        friend Vec3 operator*(Mat3&& m, Vec3& v);
        friend Vec3 operator*(Mat3&& m, Vec3&& v);


        friend std::ostream& operator<<(std::ostream& os, const Mat3& v);

};



#endif
