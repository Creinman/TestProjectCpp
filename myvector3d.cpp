#include "myvector3d.h"
#include <stdio.h>

MyVector3D & MyVector3D::operator=(const MyVector3D & v)
{
    this->_x=v._x;
    this->_y=v._y;
    this->_z=v._z;

    return *this;
}//MyVector3D & MyVector3D::operator=(const MyVector3D & v)

MyVector3D operator+(const MyVector3D & v1,const MyVector3D & v2)
{
    MyVector3D v;

    v._x=v1._x+v2._x;
    v._y=v1._y+v2._y;
    v._z=v1._z+v2._z;

    return v;
}//MyVector3D operator+(const MyVector3D & v1,const MyVector3D & v2)

MyVector3D operator-(const MyVector3D & v1,const MyVector3D & v2)
{
    MyVector3D v;

    v._x=v1._x-v2._x;
    v._y=v1._y-v2._y;
    v._z=v1._z-v2._z;

    return v;
}//MyVector3D operator-(const MyVector3D & v1,const MyVector3D & v2)

MyVector3D operator*(const MyVector3D & v1,const MyVector3D & v2)
{
    MyVector3D v;

    v._x=v1._y*v2._z-v1._z*v2._y;
    v._y=v1._z*v2._x-v1._x*v2._z;
    v._z=v1._x*v2._y-v1._y*v2._x;

    return v;
}//MyVector3D operator*(const MyVector3D & v1,const MyVector3D & v2)

MyVector3D operator*(const MyVector3D & v1,double d)
{
    MyVector3D v;

    v._x=v1._x*d;
    v._y=v1._y*d;
    v._z=v1._z*d;

    return v;
}//MyVector3D operator*(const MyVector3D & v1,double d)

MyVector3D operator*(double d,const MyVector3D & v1)
{
    MyVector3D v;

    v._x=v1._x*d;
    v._y=v1._y*d;
    v._z=v1._z*d;

    return v;
}//MyVector3D operator*(double d,const MyVector3D & v1)

MyVector3D operator/(const MyVector3D & v1,double d)
{
    MyVector3D v;

    v._x=v1._x/d;
    v._y=v1._y/d;
    v._z=v1._z/d;

    return v;
}//MyVector3D operator/(const MyVector3D & v1,double d)

MyVector3D & MyVector3D::operator+=(const MyVector3D & v1)
{
    this->_x+=v1._x;
    this->_y+=v1._y;
    this->_z+=v1._z;

    return *this;
}//MyVector3D & MyVector3D::operator+=(const MyVector3D & v1)

MyVector3D & MyVector3D::operator-=(const MyVector3D & v1)
{
    this->_x-=v1._x;
    this->_y-=v1._y;
    this->_z-=v1._z;

    return *this;
}//MyVector3D & MyVector3D::operator-=(const MyVector3D & v1)

MyVector3D & MyVector3D::operator*=(const MyVector3D & v1)
{
    double x,y,z;

    x=this->_y*v1._z-this->_z*v1._y;
    y=this->_z*v1._x-this->_x*v1._z;
    z=this->_x*v1._y-this->_y*v1._x;

    this->SetXYZ(x,y,z);
    return *this;
}//MyVector3D & MyVector3D::operator*=(const MyVector3D & v1)

MyVector3D & MyVector3D::operator*=(double d)
{
    this->_x*=d;
    this->_y*=d;
    this->_z*=d;

    return *this;
}//MyVector3D & MyVector3D::operator*=(double d)

MyVector3D & MyVector3D::operator/=(double d)
{
    this->_x/=d;
    this->_y/=d;
    this->_z/=d;

    return *this;
}//MyVector3D & MyVector3D::operator/=(double d)

MyVector3D MyVector3D::operator-()const
{
    MyVector3D v;

    v._x=-this->_x;
    v._y=-this->_y;
    v._z=-this->_z;

    return v;
}//MyVector3D MyVector3D::operator-()const

double scalar(const MyVector3D & v1,const MyVector3D & v2)
{
    return v1._x*v2._x+v1._y*v2._y+v1._z*v2._z;
}//double scalar(const MyVector3D & v1,const MyVector3D & v2)

void PrintMyVector3D(const MyVector3D &v)
{
    printf("(%lg,%lg,%lg)",v.GetX(),v.GetY(),v.GetZ());

}//void PrintMyVector3D(const MyVector3D &v)
