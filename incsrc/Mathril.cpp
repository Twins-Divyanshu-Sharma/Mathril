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
    if(data)
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
   float* temp = data;
   data = vec.data;
   vec.data = temp;
   return *this;
}

float& Vec2::operator[](int n)
{
    if(n >= 0 && n < 2)
        return data[n];
    else
    {
        std::cerr << "Vec2 index " << n << " is out of bounds " << std::endl;
        n>0 ? n=n : n=-n;
        return data[n%2];
    }
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
    if(data)
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
    float* temp = data;
    data = vec.data;
    vec.data = temp;
    return *this;
}

float& Vec3::operator[](int n)
{
   if(n>=0 && n<3)
       return data[n];
   else
   {
       std::cerr << " Vec3 index "<<n<<" out of bounds "<<std::endl;
       n>0 ? n=n : n=-n;
       return data[n%3];
   }
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
        v.data[i] = v.data[i] - w.data[i];
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
    if(data)
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
    float* temp = data;
    data = vec.data;
    vec.data = temp;
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
       n>0 ? n=n : n=-n;
       return data[n%4];
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


std::ostream& operator<<(std::ostream& os, const Vec4& v)
{
	os << "[" << v.data[0] << ", " << v.data[1] << ", " << v.data[2] << ", " << v.data[3] << "]";
	return os;
}

Mat3::Mat3()
{
    data = new float*[3];
    for(int i=0; i<3; i++)
    {
        data[i] = new float[3];
        for(int j=0; j<3; j++)
        {
            data[i][j] = 0;
        }
    }
}

Mat3::Mat3(float m00, float m01, float m02,
           float m10, float m11, float m12,
           float m20, float m21, float m22)
{

    data = new float*[3];
    for(int i=0; i<3; i++)
    {
        data[i] = new float[3];
    }

    data[0][0] = m00; data[0][1] = m01; data[0][2] = m02;
    data[1][0] = m10; data[1][1] = m11; data[1][2] = m12;
    data[2][0] = m20; data[2][1] = m21; data[2][2] = m22;
}

Mat3::Mat3(Mat3& mat)
{
    data = new float*[3];
    for(int i=0; i<3; i++)
    {
        data[i] = new float[3];
        for(int j=0; j<3; j++)
        {
            data[i][j] = mat.data[i][j];
        }
    }
}

Mat3::Mat3(Mat3&& mat)
{
    data = mat.data;
    mat.data = nullptr;
}

Mat3::~Mat3()
{
    if(!data)
    {
        for(int i=0; i<3; i++)
        {
            delete [] data[i];
        }
        delete [] data;
    }
}

Mat3& Mat3::operator=(Mat3& mat)
{
    if(this == &mat) return *this;

    for(int i=0; i<3; i++)
        for(int j=0; j<3; j++)
            data[i][j] = mat.data[i][j];

    return *this;
}

Mat3& Mat3::operator=(Mat3&& mat)
{
    float** temp = data;
    data = mat.data;
    mat.data = temp;
    return *this;
}

float* Mat3::operator[](int n)
{
    return data[n];
}

Mat3 operator+(Mat3& m, Mat3& n)
{
    return Mat3(m.data[0][0]+n.data[0][0], m.data[0][1]+n.data[0][1], m.data[0][2]+n.data[0][2],
                m.data[1][0]+n.data[1][0], m.data[1][1]+n.data[1][1], m.data[1][2]+n.data[1][2],
                m.data[2][0]+n.data[2][0], m.data[2][1]+n.data[2][1], m.data[2][2]+n.data[2][2]);
}

Mat3 operator+(Mat3& m, Mat3&& n)
{
    for(int i=0; i<3; i++)
        for(int j=0; j<3; j++)
            n[i][j] = m[i][j] + n[i][j];
    return std::move(n);
}

Mat3 operator+(Mat3&& m, Mat3& n)
{
    for(int i=0; i<3; i++)
        for(int j=0; j<3; j++)
            m[i][j] = m[i][j] + n[i][j];
    return std::move(m);
}

Mat3 operator+(Mat3&& m, Mat3&& n)
{
    for(int i=0; i<3; i++)
        for(int j=0; j<3; j++)
            m[i][j] = m[i][j] + n[i][j];
    return std::move(m);
}


Mat3 operator-(Mat3& m, Mat3& n)
{
    return Mat3(m.data[0][0]-n.data[0][0], m.data[0][1]-n.data[0][1], m.data[0][2]-n.data[0][2],
                m.data[1][0]-n.data[1][0], m.data[1][1]-n.data[1][1], m.data[1][2]-n.data[1][2],
                m.data[2][0]-n.data[2][0], m.data[2][1]-n.data[2][1], m.data[2][2]-n.data[2][2]);
}

Mat3 operator-(Mat3& m, Mat3&& n)
{
    for(int i=0; i<3; i++)
        for(int j=0; j<3; j++)
            n[i][j] = m[i][j] - n[i][j];
    return std::move(n);
}

Mat3 operator-(Mat3&& m, Mat3& n)
{
    for(int i=0; i<3; i++)
        for(int j=0; j<3; j++)
            m[i][j] = m[i][j] - n[i][j];
    return std::move(m);
}

Mat3 operator-(Mat3&& m, Mat3&& n)
{
    for(int i=0; i<3; i++)
        for(int j=0; j<3; j++)
            m[i][j] = m[i][j] - n[i][j];
    return std::move(m);
}

Mat3 operator*(Mat3& m, Mat3& n)
{
   return Mat3(m.data[0][0]*n.data[0][0] + m.data[0][1]*n.data[1][0] + m.data[0][2]*n.data[2][0],
               m.data[0][0]*n.data[0][1] + m.data[0][1]*n.data[1][1] + m.data[0][2]*n.data[2][1],
               m.data[0][0]*n.data[0][2] + m.data[0][1]*n.data[1][2] + m.data[0][2]*n.data[2][2],
               m.data[1][0]*n.data[0][0] + m.data[1][1]*n.data[1][0] + m.data[1][2]*n.data[2][0],
               m.data[1][0]*n.data[0][1] + m.data[1][1]*n.data[1][1] + m.data[1][2]*n.data[2][1],
               m.data[1][0]*n.data[0][2] + m.data[1][1]*n.data[1][2] + m.data[1][2]*n.data[2][2],
               m.data[2][0]*n.data[0][0] + m.data[2][1]*n.data[1][0] + m.data[2][2]*n.data[2][0],
               m.data[2][0]*n.data[0][1] + m.data[2][1]*n.data[1][1] + m.data[2][2]*n.data[2][1],
               m.data[2][0]*n.data[0][2] + m.data[2][1]*n.data[1][2] + m.data[2][2]*n.data[2][2] 
              );
}

Mat3 operator*(Mat3&& m, Mat3& n)
{
    for(int i=0; i<3; i++)
    {
        float temp[3] = {0};
        for(int j=0; j<3; j++)
        {
            for(int k=0; k<3; k++)
            {
                temp[j] += m.data[i][k] * n.data[k][j];
            }
        }
        for(int x=0; x<3; x++)
            m.data[i][x] = temp[x];
    }

    return std::move(m);
}

Mat3 operator*(Mat3& m, Mat3&& n)
{
    for(int i=0; i<3; i++)
    {
        float temp[3] = {0};
        for(int j=0; j<3; j++)
        {
            for(int k=0; k<3; k++)
            {
                temp[j] += m.data[j][k] * n.data[k][i];
            }
        }
        for(int x=0; x<3; x++)
            n.data[x][i] = temp[x];
    }

    return std::move(n);
}


Mat3 operator*(Mat3&& m, Mat3&& n)
{
    for(int i=0; i<3; i++)
    {
        float temp[3] = {0};
        for(int j=0; j<3; j++)
        {
            for(int k=0; k<3; k++)
            {
                temp[j] += m.data[i][k] * n.data[k][j];
            }
        }
        for(int x=0; x<3; x++)
            m.data[i][x] = temp[x];
    }

    return std::move(m);
}

Vec3 operator*(Mat3& m, Vec3& v)
{
    return Vec3(v[0]*m.data[0][0] + v[1]*m.data[0][1] + v[2]*m.data[0][2],
                v[0]*m.data[1][0] + v[1]*m.data[1][1] + v[2]*m.data[1][2],
                v[0]*m.data[2][0] + v[1]*m.data[2][1] + v[2]*m.data[2][2]);
}

Vec3 operator*(Mat3& m, Vec3&& v)
{
    float temp[3] = {0};
    for(int i=0; i<3; i++)
    {
        for(int j=0; j<3; j++)
        {
            temp[i] += v[j]*m.data[i][j];
        }
    }
    for(int i=0; i<3; i++)
        v[i] = temp[i];

    return std::move(v);
}

Vec3 operator*(Mat3&& m, Vec3& v)
{
    return Vec3(v[0]*m.data[0][0] + v[1]*m.data[0][1] + v[2]*m.data[0][2],
                v[0]*m.data[1][0] + v[1]*m.data[1][1] + v[2]*m.data[1][2],
                v[0]*m.data[2][0] + v[1]*m.data[2][1] + v[2]*m.data[2][2]);
}


Vec3 operator*(Mat3&& m, Vec3&& v)
{
    float temp[3] = {0};
    for(int i=0; i<3; i++)
    {
        for(int j=0; j<3; j++)
        {
            temp[i] += v[j]*m.data[i][j];
        }
    }
    for(int i=0; i<3; i++)
        v[i] = temp[i];

    return std::move(v);
}



std::ostream& operator<<(std::ostream& os, const Mat3& m)
{
    for(int i=0; i<3; i++)
    {
        for(int j=0; j<3; j++)
        {
            os << m.data[i][j] << ", ";
        }
        os << std::endl;
    }

	return os;
}

