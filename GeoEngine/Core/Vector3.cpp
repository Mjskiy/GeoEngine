#include <cmath>

#include "Vector3.h"

Vector3::Vector3(const Point& p)
	:x(p.x), y(p.y), z(p.z)
{
}

float Vector3::Length() const
{
	return sqrt(x * x + y * y + z * z);
}

float Vector3::LengthSqr() const
{
	return (x * x + y * y + z * z);
}

Vector3 Vector3::operator-() const
{
	return Vector3();
}

Vector3 Vector3::operator+(const Vector3& v) const
{
	return Vector3(x + v.x, y + v.y, z + v.z);
}

Vector3 Vector3::operator-(const Vector3& v) const
{
	return Vector3(x - v.x, y - v.y, z - v.z);
}

Vector3 Vector3::operator*(float s) const
{
	return Vector3(x * s, y * s, z * s);
}

Vector3 Vector3::operator/(float s) const
{
	return Vector3(x / s, y / s, z / s);
}

Vector3 Vector3::Normalized() const
{
	return (*this) / Length();
}

void Vector3::Normalize()
{
	(*this) = (*this) / Length();
}

float Vector3::Dot(const Vector3& v) const
{
	return x * v.x + y * v.y + z * v.z;
}

// Cross-product http://www.youtube.com/watch?v=FT7MShdqK6w
Vector3 Vector3::Cross(const Vector3& v) const
{
	Vector3 c;

	c.x = y * v.z - z * v.y;
	c.y = z * v.x - x * v.z;
	c.z = x * v.y - y * v.x;

	return c ;
}

Vector3 operator-(Point a, Point b)
{
	Vector3 v;

	v.x = a.x - b.x;
	v.y = a.y - b.y;
	v.z = a.z - b.z;

	return v;
}


Point Point::operator+(const Vector3& v) const
{
	return Point(x + v.x, y + v.y, z + v.z);
}


Point Point::operator-(const Vector3& v) const
{
	return Point(x - v.x, y - v.y, z - v.z);
}