#ifndef MATH_VECTOR2D_HPP
#define MATH_VECTOR2D_HPP
//#pragma once ~ implentacao C

namespace math {

class Vector2D {
public:
    Vector2D(double x, double y):  // lista de inicialização
      x_{x},
      y_{y}
    {}      //Corpo dos membros

    Vector2D() = default;
    Vector2D(const Vector2D &) = default; //Copia de objeto

    double x() const
    {
        // this: Vector2D const
        return this->x_;
    }
    double y() const
    { 
        return y_;
    }

    Vector2D& invert();
    Vector2D& operator *=(double);
    Vector2D& operator +=(Vector2D const&);

private:
    double x_{0}, y_{0};
};

Vector2D operator -(Vector2D);
Vector2D operator +(Vector2D, const Vector2D &);
Vector2D operator *(Vector2D, double);
}

#endif