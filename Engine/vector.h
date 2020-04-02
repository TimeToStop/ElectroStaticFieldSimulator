#ifndef VECTOR_H
#define VECTOR_H

#include <math.h>
#include <QPointF>
#include <QSize>

class Vector
{
    float m_x;
    float m_y;

public:
    Vector();
    Vector(float);
    Vector(float, float);
    Vector(const Vector&);
    Vector(const QPoint&);
    Vector(const QPointF&);
    Vector(const QSize&);
    Vector(Vector&&);
    ~Vector();

    void setX(float);
    void setY(float);

    float x() const;
    float y() const;

    float module() const;
    QPointF toPointF() const;

    Vector& operator=(const Vector&);
    Vector& operator=(const Vector&&);

    Vector operator+() const;
    Vector operator-() const;

    Vector operator+(const Vector&) const;
    Vector operator-(const Vector&) const;

    float operator*(const Vector&) const;

    Vector operator*(float) const;
    Vector operator/(float) const;

    Vector& operator+=(const Vector&);
    Vector& operator-=(const Vector&);

    Vector& operator*=(float);
    Vector& operator/=(float);
};



#endif // VECTOR_H
