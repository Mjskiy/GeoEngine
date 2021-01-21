#pragma once
#include "Vector3.h"

#pragma region onSegement Anno

// Given three colinear points p, q, r, the function checks if 
// point q lies on line segment 'pr' 

#pragma endregion

bool onSegement(Point p, Point q, Point r)
{
	if (q.x <= std::max(p.x, r.x) && q.x >= std::min(p.x, r.x) &&
		q.y <= std::max(p.y, r.y) && q.y >= std::min(p.y, r.y))
		return true;
	return false;
}

#pragma region orientation Anno

// To find orientation of ordered triplet (p, q, r). 
// The function returns following values 
// 0 --> p, q and r are colinear 
// 1 --> Clockwise 
// 2 --> Counterclockwise 

// See https://www.geeksforgeeks.org/orientation-3-ordered-points/ 
// for details of below formula. 
#pragma endregion

int orientation(Point p, Point q, Point r)
{
	int val = (q.y - p.y) * (r.x - q.x) -
		(q.x - p.x) * (r.y - q.y);

	// colinear 
	if (val == 0) return 0;

	// clock or counterclock wise 
	return (val > 0) ? 1 : 2;
}

#pragma region doIntersect Anno
// The main function that returns true if line segment 'p1q1' 
// and 'p2q2' intersect. 

// Find the four orientations needed for general and 
// special cases 
#pragma endregion

bool doIntersect(Point p1, Point q1, Point p2, Point q2) 
{
	int o1 = orientation(p1, q1, p2);
	int o2 = orientation(p1, q1, q2);
	int o3 = orientation(p2, q2, p1);
	int o4 = orientation(p2, q2, q1);

	// General case
	if (o1 != o2 && o3 != o4)
	{
		return true;
	}

	// Special Cases 
	// p1, q1 and p2 are colinear and p2 lies on segment p1q1
	if (o1 == 0 && onSegement(p1, p2, q1)) return true;

	// p1, q1 and q2 are colinear and q2 lies on segment p1q1 
	if (o1 == 0 && onSegement(p1, q2, q1)) return true;

	// p2, q2 and p1 are colinear and p1 lies on segment p2q2
	if (o1 == 0 && onSegement(p2, p1, q2)) return true;

	// p2, q2 and q1 are colinear and q1 lies on segment p2q2 
	if (o1 == 0 && onSegement(p2, q1, q2)) return true;

	// Doesn't fall in any of the above cases 
	return false;
}


