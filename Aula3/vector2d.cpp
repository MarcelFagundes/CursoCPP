#include "vector2d.hpp"

namespace math {

    


Vector2D& Vector2D::invert()
{
    x_ = -x_;
    y_ = -y_;

    return *this;
}

Vector2D& Vector2D::operator *=(double s)
{
    x_  *= s;
    y_ *= s;

    return *this;
}

Vector2D& Vector2D::operator +=(Vector2D const& outher)
{
   x_ += outher.x_;
   y_ += outher.y_;

    return *this;
}

Vector2D operator -(Vector2D v)
{
    v.invert();

    return v;
}
Vector2D operator +(Vector2D v, const Vector2D const& u)
{
    v += u;

    return v;
}

Vector2D operator *(Vector2D v, double s)
{
    v *= s;

    return v;
}

} // namespace math