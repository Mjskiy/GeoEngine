#pragma once

#include <iostream>

#pragma region Coding_Ref
//https://github.com/BSVino/MathForGameDevelopers
//https://github.com/planetchili/3D_Fundamentals
//https://github.com/mmp/pbrt-v3

#pragma endregion

class Vector3
{
public:
	Vector3()
	{
		x = y = z = 0;
	}

	Vector3(float X, float Y, float Z)
	{
		x = X;
		y = Y;
		z = Z;
	}

	Vector3(float XYZ[3])
	{
		x = XYZ[0];
		y = XYZ[1];
		z = XYZ[2];
	}

	Vector3(const class Point& p);

public:

	float Length() const;
	float LengthSqr() const;

	Vector3 operator-() const;

	Vector3 operator+(const Vector3& v) const;
	Vector3 operator-(const Vector3& v) const;

	Vector3 operator*(float s) const;
	Vector3 operator/(float s) const;

	Vector3 Normalized() const;
	void Normalize();

	float  Dot(const Vector3& v) const;
	Vector3 Cross(const Vector3& v) const;	

public:
	union
	{
		struct
		{
			float x, y, z;
		};
		float v[3];
	};

};

inline const Vector3 operator*(float s, const Vector3& v)
{
	return Vector3(s * v.x, s * v.y, s * v.z);
}

inline const Vector3 operator/(float s, const Vector3& v)
{
	return Vector3(s / v.x, s / v.y, s / v.z);
}


class Point
{
public: 
	Point() 
	{
		x = y = z = 0;
	}

	Point(float X, float Y, float Z)	
	{
		x = X;
		y = Y;
		z = Z;
	}

	Point(const Vector3& v)
	{
		x = v.x;
		y = v.y;
		z = v.z;
	}

	Point operator+(const Vector3& v) const;
	Point operator-(const Vector3& v) const;

	float x, y, z;
};

