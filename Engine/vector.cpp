#include "vector.h"

Vector::Vector():
    m_x(0.f),
    m_y(0.f)
{
}

Vector::Vector(float val):
    m_x(val),
    m_y(val)
{
}

Vector::Vector(float x, float y):
    m_x(x),
    m_y(y)
{
}

Vector::Vector(const Vector& vector):
    m_x(vector.m_x),
    m_y(vector.m_y)
{
}

Vector::Vector(const QPoint& pos):
    m_x(pos.x()),
    m_y(pos.y())
{
}

Vector::Vector(const QPointF& pos):
    m_x(pos.x()),
    m_y(pos.y())
{
}

Vector::Vector(const QSize& size):
    m_x(size.width()),
    m_y(size.height())
{
}

Vector::Vector(Vector&& vector):
    m_x(vector.m_x),
    m_y(vector.m_y)
{
}

Vector::~Vector()
{
}

void Vector::setX(float x)
{
    m_x = x;
}

void Vector::setY(float y)
{
    m_y = y;
}

float Vector::x() const
{
    return m_x;
}

float Vector::y() const
{
    return m_y;
}

float Vector::module() const
{
    return sqrt(m_x*m_x+m_y*m_y);
}

QPointF Vector::toPointF() const
{
    return QPointF(m_x, m_y);
}

Vector& Vector::operator=(const Vector& vector)
{
    m_x = vector.m_x;
    m_y = vector.m_y;
    return *this;
}

Vector& Vector::operator=(const Vector&& vector)
{
    m_x = vector.m_x;
    m_y = vector.m_y;
    return *this;
}

Vector Vector::operator+() const
{
    return *this;
}

Vector Vector::operator-() const
{
    return Vector(-m_x, -m_y);
}

Vector Vector::operator+(const Vector& vector) const
{
    return Vector(m_x + vector.m_x, m_y + vector.m_y);
}

Vector Vector::operator-(const Vector& vector) const
{
    return Vector(m_x - vector.m_x, m_y - vector.m_y);
}

float Vector::operator*(const Vector& vector) const
{
    return m_x * vector.m_x + m_y * vector.m_y;
}

Vector Vector::operator*(float d) const
{
    return Vector(m_x * d, m_y * d);
}

Vector Vector::operator/(float d) const
{
    return Vector(m_x / d, m_y / d);
}

Vector& Vector::operator+=(const Vector& vector)
{
    *this = *this + vector;
    return *this;
}

Vector &Vector::operator-=(const Vector& vector)
{
    *this = *this - vector;
    return *this;
}

Vector &Vector::operator*=(float d)
{
    *this = *this * d;
    return *this;
}

Vector &Vector::operator/=(float d)
{
    *this = *this / d;
    return *this;
}
