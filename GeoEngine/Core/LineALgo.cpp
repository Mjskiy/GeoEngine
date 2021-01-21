#pragma once
#include "LineAlgo.h"

#pragma region onSegement 

// Given three colinear points p, q, r, the function checks if 
// point q lies on line segment 'pr' 

bool onSegement(Point p, Point q, Point r)
{
	if (q.x <= std::max(p.x, r.x) && q.x >= std::min(p.x, r.x) &&
		q.y <= std::max(p.y, r.y) && q.y >= std::min(p.y, r.y))
		return true;
	return false;
}

#pragma endregion


#pragma region orientation Anno

// To find orientation of ordered triplet (p, q, r). 
// The function returns following values 
// 0 --> p, q and r are colinear 
// 1 --> Clockwise 
// 2 --> Counterclockwise 

// See https://www.geeksforgeeks.org/orientation-3-ordered-points/ 
// for details of below formula. 

int orientation(Point p, Point q, Point r)
{
	// 에러 발생 연산정의 안된 이유이거나  반환값이 안맞는거 뭐지? 
	//항은 N개의 인수를 받아들이는 함수로 계산되지 않습니다. - 참조문제인가?
	int val = (q.y - p.y)*(r.x - q.x) - (q.x - p.x)*(r.y - q.y);

	// colinear 
	if (val == 0) return 0;

	// clock or counterclock wise 
	return (val > 0) ? 1 : 2;
}

#pragma endregion


#pragma region doIntersect Anno
// The main function that returns true if line segment 'p1q1' 
// and 'p2q2' intersect. 

// Find the four orientations needed for general and 
// special cases 

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

#pragma endregion



#pragma region Count maximum points on same line

int maxPointOnSameLine(std::vector <std::pair<int, int>> points)
{
	int N = points.size();
	if (N < 2)
		return N;

	int maxPoint = 0;
	int curMax, overlapPoints, verticalPoints;

	std::unordered_map <std::pair<int,int>, int, boost::hash<std::pair<int, int>>> slopeMap;

	for (int i = 0; i< N; i++)
	{
		curMax = overlapPoints = verticalPoints = 0;

		for (int j = 0; j < N; j++)
		{
			if (points[i] == points[j])
				overlapPoints++;
			else if (points[i].first == points[j].first)
				verticalPoints++;
			else
			{
				int yDif = points[j].second - points[i].second;
				int xDif = points[j].first - points[i].first;
				
				//GCD 정의 파일 정리할것 
				int g = gcd(xDif, yDif);

				yDif /= g;
				xDif /= g;

				slopeMap[std::make_pair(yDif, xDif)]++;
				curMax = std::max(curMax, slopeMap[std::make_pair(yDif, xDif)]);			
			}

			curMax = std::max(curMax, verticalPoints);
		}
		maxPoint = std::max(maxPoint, curMax, curMax + overlapPoints + 1);

		slopeMap.clear();
	}
	
	return maxPoint;
}


#pragma endregion


