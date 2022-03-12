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

Vec4::Vec4()
{
    data = new float[4];
    for(int i=0; i<4; i++)
        data[i] = 0;
}

Vec4::Vec4(float r, float x, float y, float z)
{
    data = new float[4];
    data[0] = r;
    data[1] = x;
    data[2] = y;
    data[3] = z;
}

Vec4::~Vec4()
{
    delete [] data;
}

Vec4::Vec4(Vec4& vec)
{
    data = new float[4];
    for(int i=0; i<4; i++)
        data[i] = vec.data[i];
}

Vec4::Vec4(Vec4&& vec)
{
    data = vec.data;
    vec.data = nullptr;
}

Vec4& Vec4::operator=(Vec4& vec)
{
    if(this == &vec) return *this;
    data[0] = vec.data[0];
    data[1] = vec.data[1];
    return *this;
}

Vec4& Vec4::operator=(Vec4&& vec)
{
    data = vec.data;
    vec.data = nullptr;
    return *this;
}

float& Vec4::operator[](int n)
{
   if(n >= 0 && n < 4)
   {
        return data[n];
   }
   else
   {
       std::cerr << "index of Vec4 is out of bounds" << std::endl;
   }
}

Vec4 operator+(Vec4& v, Vec4& w)
{
    return Vec4(v.data[0]+w.data[0], v.data[1]+w.data[1], v.data[2]+w.data[2], v.data[3]+w.data[3]);
}

Vec4 operator+(Vec4& v, Vec4&& w)
{
    for(int i=0; i<4; i++)
        w.data[i] = v.data[i] + w.data[i];
    return std::move(w);
}

Vec4 operator+(Vec4&& v, Vec4& w)
{
    for(int i=0; i<4; i++)
        v.data[i] = v.data[i] + w.data[i];
    return std::move(v);
}

Vec4 operator+(Vec4&& v, Vec4&& w)
{
    for(int i=0; i<4; i++)
        v.data[i] = v.data[i] + w.data[i];
    return std::move(v);
}


Vec4 operator-(Vec4& v, Vec4& w)
{
    return Vec4(v.data[0]-w.data[0], v.data[1]-w.data[1], v.data[2]-w.data[2], v.data[3]-w.data[3]);
}

Vec4 operator-(Vec4& v, Vec4&& w)
{
    for(int i=0; i<4; i++)
        w.data[i] = v.data[i] - w.data[i];
    return std::move(w);
}

Vec4 operator-(Vec4&& v, Vec4& w)
{
    for(int i=0; i<4; i++)
        v.data[i] = v.data[i] - w.data[i];
    return std::move(v);
}

Vec4 operator-(Vec4&& v, Vec4&& w)
{
    for(int i=0; i<4; i++)
        v.data[i] = v.data[i] - w.data[i];
    return std::move(v);
}

Vec4 operator*(float s, Vec4& v)
{
    return Vec4(s*v.data[0], s*v.data[1], s*v.data[2], s*v.data[3]);
}

Vec4 operator*(float s, Vec4&& v)
{
    for(int i=0; i<4; i++)
        v.data[i] = s*v.data[i];
    return std::move(v);
}

Mat2::Mat2()
{
    data = new float*[2];
    for(int i=0; i<2; i++)
    {
        data[i] = new float[2];
        for(int j=0; j<2; j++)
            data[i][j] = 0;
    }
}

Mat2::~Mat2()
{
    if(data)
    {
        for(int i=0; i<2; i++)
            delete [] data[i];
        delete [] data;
    }
}

Mat2::Mat2(float m00, float m01, float m10, float m11)
{
    data = new float*[2];
    for(int i=0; i<2; i++)
        data[i] = new float[2];

    data[0][0] = m00;
    data[0][1] = m01;
    data[1][0] = m10;
    data[1][1] = m11;
}

Mat2::Mat2(Mat2& m)
{
    data = new float*[2];
    for(int i=0; i<2; i++)
    {
        data[i] = new float[2];
        for(int j=0; j<2; j++)
            data[i][j] = m.data[i][j];
    }
}

Mat2::Mat2(Mat2&& m)
{
    data = m.data;
    m.data = nullptr;
}

Mat2& Mat2::operator=(Mat2& m)
{
    if( this == &m ) return *this;

    for(int i=0; i<2; i++)
        for(int j=0; j<2; j++)
            data[i][j] = m.data[i][j];

    return *this;
}

Mat2& Mat2::operator=(Mat2&& m)
{
    float** temp = data;
    data = m.data;
    m.data = temp;
    return *this;
}

float* Mat2::operator[](int n)
{
    return data[n];
}

Mat2 operator+(Mat2& m, Mat2& w)
{
    return Mat2( m.data[0][0] + w.data[0][0],  m.data[0][1] + w.data[0][1],
                 m.data[1][0] + w.data[1][0],  m.data[1][1] + w.data[1][1] );
}

Mat2 operator+(Mat2& m, Mat2&& w)
{
    for(int i=0; i<2; i++)
        for(int j=0; j<2; j++)
            w[i][j] = m[i][j] + w[i][j];
    return std::move(w);
}

Mat2 operator+(Mat2&& m, Mat2& w)
{
    for(int i=0; i<2; i++)
        for(int j=0; j<2; j++)
            m[i][j] = m[i][j] + w[i][j];
    return std::move(m);
}

Mat2 operator+(Mat2&& m, Mat2&& w)
{
    for(int i=0; i<2; i++)
        for(int j=0; j<2; j++)
            m[i][j] = m[i][j] + w[i][j];
    return std::move(m);
}

Mat2 operator-(Mat2& m, Mat2& w)
{
    return Mat2( m.data[0][0] - w.data[0][0],  m.data[0][1] - w.data[0][1],
                 m.data[1][0] - w.data[1][0],  m.data[1][1] - w.data[1][1] );
}

Mat2 operator-(Mat2& m, Mat2&& w)
{
    for(int i=0; i<2; i++)
        for(int j=0; j<2; j++)
            w[i][j] = m[i][j] - w[i][j];
    return std::move(w);
}

Mat2 operator-(Mat2&& m, Mat2& w)
{
    for(int i=0; i<2; i++)
        for(int j=0; j<2; j++)
            m[i][j] = m[i][j] - w[i][j];
    return std::move(m);
}

Mat2 operator-(Mat2&& m, Mat2&& w)
{
    for(int i=0; i<2; i++)
        for(int j=0; j<2; j++)
            m[i][j] = m[i][j] - w[i][j];
    return std::move(m);
}

Mat2 operator*(Mat2& m, Mat2& w)
{    
    return Mat2( m.data[0][0]*w.data[0][0] + m.data[0][1]*w.data[1][0],
                 m.data[0][0]*w.data[0][1] + m.data[0][1]*w.data[1][1],
                 m.data[1][0]*w.data[0][0] + m.data[1][1]*w.data[1][0],
                 m.data[1][0]*w.data[0][1] + m.data[1][1]*w.data[1][1] );
}

Mat2 operator*(Mat2&& m, Mat2& w)
{ 
    for(int i=0; i<2; i++)
    {
       float temp[2] = {0};
       for(int j=0; j<2; j++)
        {
            for(int k=0; k<2; k++)
                temp[j] += m.data[i][k]*w.data[k][j];
        }
        for(int x=0; x<2; x++) 
            m.data[i][x] = temp[x];    
    }

    return std::move(m);
}

Mat2 operator*(Mat2& m, Mat2&& w)
{
    for(int i=0; i<2; i++)
    { 
        float temp[2] = {0};
        for(int j=0; j<2; j++)
        {
            for(int k=0; k<2; k++)
                temp[j] += m.data[j][k]*w.data[k][i];
        }
        for(int x=0; x<2; x++)
            w.data[x][i] = temp[x];
   }

    return std::move(w);
}

Mat2 operator*(Mat2&& m, Mat2&& w)
{ 
    for(int i=0; i<2; i++)
    {
       float temp[2] = {0};
       for(int j=0; j<2; j++)
        {
            for(int k=0; k<2; k++)
            {
                temp[j] += m.data[i][k]*w.data[k][j];
            }
        }
        for(int x=0; x<2; x++) 
            m.data[i][x] = temp[x];    
    }

    return std::move(m);
}

Vec2 operator*(Mat2& m, Vec2& v)
{
    return Vec2(v[0]*m.data[0][0] + v[1]*m.data[0][1],
                v[0]*m.data[1][0] + v[1]*m.data[1][1]);
}

Vec2 operator*(Mat2& m, Vec2&& v)
{
    float temp[2] = {0};
    for(int i=0; i<2; i++)
    {
        for(int j=0; j<2; j++)
        {
            temp[i] += v[j]*m.data[i][j];
        }
    }
    for(int i=0; i<2; i++)
        v[i] = temp[i];

    return std::move(v);
}

Vec2 operator*(Mat2&& m, Vec2& v)
{
    return Vec2(v[0]*m.data[0][0] + v[1]*m.data[0][1],
                v[0]*m.data[1][0] + v[1]*m.data[1][1]);
}

Vec2 operator*(Mat2&& m, Vec2&& v)
{
    float temp[2] = {0};
    for(int i=0; i<2; i++)
    {
        for(int j=0; j<2; j++)
        {
            temp[i] += v[j]*m.data[i][j];
        }
    }
    for(int i=0; i<2; i++)
        v[i] = temp[i];

    return std::move(v);
}

std::ostream& operator<<(std::ostream& os, const Mat2& m)
{
    for(int i=0; i<2; i++)
    {
        for(int j=0; j<2; j++)
        {
            os << m.data[i][j] <<", ";
        }
        os << std::endl;
    }

    return os;
}

Mat4::Mat4()
{
    data = new float*[4];
    for(int i=0; i<4; i++)
    {
        data[i] = new float[4];
        for(int j=0; j<4; j++)
            data[i][j] = 0;
    }
}

Mat4::~Mat4()
{
    if(data)
    {
        for(int i=0; i<4; i++)
            delete [] data[i];
        delete [] data;
    }
}

Mat4::Mat4(
     float m00, float m01, float m02, float m03,
     float m10, float m11, float m12, float m13,
     float m20, float m21, float m22, float m23,
     float m30, float m31, float m32, float m33
                                                )
{
    data = new float*[4];
    for(int i=0; i<4; i++)
        data[i] = new float[4];

    data[0][0] = m00;   data[0][1] = m01;   data[0][2] = m02;   data[0][3] = m03;
    data[1][0] = m10;   data[1][1] = m11;   data[1][2] = m12;   data[1][3] = m13;
    data[2][0] = m20;   data[2][1] = m21;   data[2][2] = m22;   data[2][3] = m23;
    data[3][0] = m30;   data[3][1] = m31;   data[3][2] = m32;   data[3][3] = m33;
}

Mat4::Mat4(Mat4& m)
{
    data = new float*[4];
    for(int i=0; i<4; i++)
    {
        data[i] = new float[4];
        for(int j=0; j<4; j++)
            data[i][j] = m.data[i][j];
    }
}

Mat4::Mat4(Mat4&& m)
{
    data = m.data;
    m.data = nullptr;
}

Mat4& Mat4::operator=(Mat4& m)
{
    if( this == &m ) return *this;

    for(int i=0; i<4; i++)
        for(int j=0; j<4; j++)
            data[i][j] = m.data[i][j];

    return *this;
}

Mat4& Mat4::operator=(Mat4&& m)
{
    float** temp = data;
    data = m.data;
    m.data = temp;
    return *this;
}

float* Mat4::operator[](int n)
{
    return data[n];
}

Mat4 operator+(Mat4& m, Mat4& w)
{
    return Mat4(
        m.data[0][0]+w.data[0][0], m.data[0][1]+w.data[0][1], m.data[0][2]+w.data[0][2], m.data[0][3]+w.data[0][3],
        m.data[1][0]+w.data[1][0], m.data[1][1]+w.data[1][1], m.data[1][2]+w.data[1][2], m.data[1][3]+w.data[1][3],
        m.data[2][0]+w.data[2][0], m.data[2][1]+w.data[2][1], m.data[2][2]+w.data[2][2], m.data[2][3]+w.data[2][3],
        m.data[3][0]+w.data[3][0], m.data[3][1]+w.data[3][1], m.data[3][2]+w.data[3][2], m.data[3][3]+w.data[3][3]
    );
} 

Mat4 operator+(Mat4& m, Mat4&& w)
{
    for(int i=0; i<4; i++)
        for(int j=0; j<4; j++)
            w[i][j] = m[i][j] + w[i][j];
    return std::move(w);
}

Mat4 operator+(Mat4&& m, Mat4& w)
{
    for(int i=0; i<4; i++)
        for(int j=0; j<4; j++)
            m[i][j] = m[i][j] + w[i][j];
    return std::move(m);
}

Mat4 operator+(Mat4&& m, Mat4&& w)
{
    for(int i=0; i<4; i++)
        for(int j=0; j<4; j++)
            m[i][j] = m[i][j] + w[i][j];
    return std::move(m);
}

Mat4 operator-(Mat4& m, Mat4& w)
{
    return Mat4(
            m.data[0][0]-w.data[0][0], m.data[0][1]-w.data[0][1], m.data[0][2]-w.data[0][2], m.data[0][3]-w.data[0][3],
            m.data[1][0]-w.data[1][0], m.data[1][1]-w.data[1][1], m.data[1][2]-w.data[1][2], m.data[1][3]-w.data[1][3],
            m.data[2][0]-w.data[2][0], m.data[2][1]-w.data[2][1], m.data[2][2]-w.data[2][2], m.data[2][3]-w.data[2][3],
            m.data[3][0]-w.data[3][0], m.data[3][1]-w.data[3][1], m.data[3][2]-w.data[3][2], m.data[3][3]-w.data[3][3]
        );
}

Mat4 operator-(Mat4& m, Mat4&& w)
{
    for(int i=0; i<4; i++)
        for(int j=0; j<4; j++)
            w[i][j] = m[i][j] - w[i][j];
    return std::move(w);
}

Mat4 operator-(Mat4&& m, Mat4& w)
{
    for(int i=0; i<4; i++)
        for(int j=0; j<4; j++)
            m[i][j] = m[i][j] - w[i][j];
    return std::move(m);
}

Mat4 operator-(Mat4&& m, Mat4&& w)
{
    for(int i=0; i<4; i++)
        for(int j=0; j<4; j++)
            m[i][j] = m[i][j] - w[i][j];
    return std::move(m);
}

Mat4 operator*(Mat4& m, Mat4& w)
{    
    return Mat4(
                 m.data[0][0]*w.data[0][0] + m.data[0][1]*w.data[1][0] + m.data[0][2]*w.data[2][0] + m.data[0][3]*w.data[3][0],
                 m.data[0][0]*w.data[0][1] + m.data[0][1]*w.data[1][1] + m.data[0][2]*w.data[2][1] + m.data[0][3]*w.data[3][1],
                 m.data[0][0]*w.data[0][2] + m.data[0][1]*w.data[1][2] + m.data[0][2]*w.data[2][2] + m.data[0][3]*w.data[3][2],
                 m.data[0][0]*w.data[0][3] + m.data[0][1]*w.data[1][3] + m.data[0][2]*w.data[2][3] + m.data[0][3]*w.data[3][3],

                 m.data[1][0]*w.data[0][0] + m.data[1][1]*w.data[1][0] + m.data[1][2]*w.data[2][0] + m.data[1][3]*w.data[3][0],
                 m.data[1][0]*w.data[0][1] + m.data[1][1]*w.data[1][1] + m.data[1][2]*w.data[2][1] + m.data[1][3]*w.data[3][1],
                 m.data[1][0]*w.data[0][2] + m.data[1][1]*w.data[1][2] + m.data[1][2]*w.data[2][2] + m.data[1][3]*w.data[3][2],
                 m.data[1][0]*w.data[0][3] + m.data[1][1]*w.data[1][3] + m.data[1][2]*w.data[2][3] + m.data[1][3]*w.data[3][3],

                 m.data[2][0]*w.data[0][0] + m.data[2][1]*w.data[1][0] + m.data[2][2]*w.data[2][0] + m.data[2][3]*w.data[3][0],
                 m.data[2][0]*w.data[0][1] + m.data[2][1]*w.data[1][1] + m.data[2][2]*w.data[2][1] + m.data[2][3]*w.data[3][1],
                 m.data[2][0]*w.data[0][2] + m.data[2][1]*w.data[1][2] + m.data[2][2]*w.data[2][2] + m.data[2][3]*w.data[3][2],
                 m.data[2][0]*w.data[0][3] + m.data[2][1]*w.data[1][3] + m.data[2][2]*w.data[2][3] + m.data[2][3]*w.data[3][3],

                 m.data[3][0]*w.data[0][0] + m.data[3][1]*w.data[1][0] + m.data[3][2]*w.data[2][0] + m.data[3][3]*w.data[3][0],
                 m.data[3][0]*w.data[0][1] + m.data[3][1]*w.data[1][1] + m.data[3][2]*w.data[2][1] + m.data[3][3]*w.data[3][1],
                 m.data[3][0]*w.data[0][2] + m.data[3][1]*w.data[1][2] + m.data[3][2]*w.data[2][2] + m.data[3][3]*w.data[3][2],
                 m.data[3][0]*w.data[0][3] + m.data[3][1]*w.data[1][3] + m.data[3][2]*w.data[2][3] + m.data[3][3]*w.data[3][3]

            );
}

Mat4 operator*(Mat4&& m, Mat4& w)
{ 
    for(int i=0; i<4; i++)
    {
       float temp[4] = {0};
       for(int j=0; j<4; j++)
        {
            for(int k=0; k<4; k++)
                temp[j] += m.data[i][k]*w.data[k][j];
        }
        for(int x=0; x<4; x++) 
            m.data[i][x] = temp[x];    
    }

    return std::move(m);
}

Mat4 operator*(Mat4& m, Mat4&& w)
{
    for(int i=0; i<4; i++)
    { 
        float temp[4] = {0};
        for(int j=0; j<4; j++)
        {
            for(int k=0; k<4; k++)
                temp[j] += m.data[j][k]*w.data[k][i];
        }
        for(int x=0; x<4; x++)
            w.data[x][i] = temp[x];
   }

    return std::move(w);
}

Mat4 operator*(Mat4&& m, Mat4&& w)
{ 
    for(int i=0; i<4; i++)
    {
       float temp[4] = {0};
       for(int j=0; j<4; j++)
        {
            for(int k=0; k<4; k++)
            {
                temp[j] += m.data[i][k]*w.data[k][j];
            }
        }
        for(int x=0; x<4; x++) 
            m.data[i][x] = temp[x];    
    }

    return std::move(m);
}

Vec4 operator*(Mat4& m, Vec4& v)
{
    return Vec4(
                v[0]*m.data[0][0] + v[1]*m.data[0][1] + v[2]*m.data[0][2] + v[3]*m.data[0][3],
                v[0]*m.data[1][0] + v[1]*m.data[1][1] + v[2]*m.data[1][2] + v[3]*m.data[1][3],
                v[0]*m.data[2][0] + v[1]*m.data[2][1] + v[2]*m.data[2][2] + v[3]*m.data[2][3],
                v[0]*m.data[3][0] + v[1]*m.data[3][1] + v[2]*m.data[3][2] + v[3]*m.data[3][3]
            );
}

Vec4 operator*(Mat4& m, Vec4&& v)
{
    float temp[4] = {0};
    for(int i=0; i<4; i++)
    {
        for(int j=0; j<4; j++)
        {
            temp[i] += v[j]*m.data[i][j];
        }
    }
    for(int i=0; i<4; i++)
        v[i] = temp[i];

    return std::move(v);
}

Vec4 operator*(Mat4&& m, Vec4& v)
{
  
    return Vec4(
                v[0]*m.data[0][0] + v[1]*m.data[0][1] + v[2]*m.data[0][2] + v[3]*m.data[0][3],
                v[0]*m.data[1][0] + v[1]*m.data[1][1] + v[2]*m.data[1][2] + v[3]*m.data[1][3],
                v[0]*m.data[2][0] + v[1]*m.data[2][1] + v[2]*m.data[2][2] + v[3]*m.data[2][3],
                v[0]*m.data[3][0] + v[1]*m.data[3][1] + v[2]*m.data[3][2] + v[3]*m.data[3][3]
            );
}

Vec4 operator*(Mat4&& m, Vec4&& v)
{
    float temp[4] = {0};
    for(int i=0; i<4; i++)
    {
        for(int j=0; j<4; j++)
        {
            temp[i] += v[j]*m.data[i][j];
        }
    }
    for(int i=0; i<4; i++)
        v[i] = temp[i];

    return std::move(v);
}

std::ostream& operator<<(std::ostream& os, const Mat4& m)
{
    for(int i=0; i<4; i++)
    {
        for(int j=0; j<4; j++)
        {
            os << m.data[i][j] <<", ";
        }
        os << std::endl;
    }

    return os;
}
