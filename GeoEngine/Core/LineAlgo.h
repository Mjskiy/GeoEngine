#pragma once

#include "Vector3.h"
#include <vector>
#include <unordered_map>


//  Count maximum points on same line
#include <boost/functional/hash.hpp>
//#include <bits/stdc++.h>

//#include <boost/lambda/lambda.hpp>
#include <iterator>
#include <algorithm>

// 임시 정의 GCD 
int gcd(int a, int b)
{
	if (a == 0)
		return b;
	return gcd(b % a, a);
}

#pragma region LineSegmentIntersect

bool onSegement(Point p, Point q, Point r);

int orientation(Point p, Point q, Point r);

bool doIntersect(Point p1, Point q1, Point p2, Point q2);

#pragma endregion

#pragma region Count maximum points on same line

int maxPointOnSameLine(std::vector<std::pair<int, int>> points);

#pragma endregion









