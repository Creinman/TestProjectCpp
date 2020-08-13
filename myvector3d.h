#ifndef MYVECTOR3D_H
#define MYVECTOR3D_H

#include <math.h>

class MyVector3D
{
private:
//protected:
    double _x,_y,_z;

public:
    //MyVector3D(){this->_x=this->_y=this->_z=0.;}
    MyVector3D(double x=0.,double y=0.,double z=0.)
        {this->_x=x;this->_y=y;this->_z=z;}
    MyVector3D(const MyVector3D &v)
        {this->_x=v._x;this->_y=v._y;this->_z=v._z;}

    ~MyVector3D(){}

    //Стандартный доступ к внутренним переменным
    double GetX()const{return this->_x;}
    double GetY()const{return this->_y;}
    double GetZ()const{return this->_z;}

    void GetXYZ(double &x,double &y,double &z)const
        {x=this->_x;y=this->_y;z=this->_z;}

    void SetX(double x=0.){this->_x=x;}
    void SetY(double y=0.){this->_y=y;}
    void SetZ(double z=0.){this->_z=z;}
    void SetXYZ(double x=0.,double y=0.,double z=0.)
        {this->_x=x;this->_y=y;this->_z=z;}

    // Альтернативный доступ к внутренним переменным
    double & _GetX(){return this->_x;}
    double & _GetY(){return this->_y;}
    double & _GetZ(){return this->_z;}

    MyVector3D & operator=(const MyVector3D & v);

    friend MyVector3D operator+(const MyVector3D & v1,const MyVector3D & v2);
    friend MyVector3D operator-(const MyVector3D & v1,const MyVector3D & v2);
    friend MyVector3D operator*(const MyVector3D & v1,const MyVector3D & v2);
    friend MyVector3D operator*(const MyVector3D & v1,double d);
    friend MyVector3D operator*(double d,const MyVector3D & v1);
    friend MyVector3D operator/(const MyVector3D & v1,double d);

    MyVector3D & operator+=(const MyVector3D & v1);
    MyVector3D & operator-=(const MyVector3D & v1);
    MyVector3D & operator*=(const MyVector3D & v1);
    MyVector3D & operator*=(double d);
    MyVector3D & operator/=(double d);

    MyVector3D operator-()const;

    double norm()const{return sqrt(_x*_x+_y*_y+_z*_z);}
    double norm2()const{return (_x*_x+_y*_y+_z*_z);}

    friend double scalar(const MyVector3D & v1,const MyVector3D & v2);

};//class MyVector3D

void PrintMyVector3D(const MyVector3D &v);

#endif // MYVECTOR3D_H
