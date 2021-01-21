#include "Core/Vector3.h"

#pragma region Test Core 

//int main(int argc, char** args) 
//{
//	Point p;
//	p.x = 1;
//	p.y = 0;
//
//	Vector v;
//	v.x = 2;
//	v.y = 3;
//
//	Point p2 = p.AddVector(v);
//
//	std::cout << "Result : (" << p2.x << ", " << p2.y << ")\n";
//	
//	return 0;
//}

#pragma endregion

#include "Core/LineSegmentIntersect.h"

#pragma region TestLineSegmentIntersect

int main()
{
	struct Point p1 = { 1, 1 ,0 }, q1 = { 10, 1, 0 };
	struct Point p2 = { 1, 2, 0 }, q2 = { 10, 2 , 0 };

	doIntersect(p1, q1, p2, q2) ? std::cout << "Yes\n" : std::cout << "No\n";

	p1 = { 10, 0,0 }, q1 = { 0, 10,0 };
	p2 = { 0, 0,0 }, q2 = { 10, 10,0 };
	doIntersect(p1, q1, p2, q2) ? std::cout << "Yes\n" : std::cout << "No\n";

	p1 = { -5, -5,0 }, q1 = { 0, 0,0 };
	p2 = { 1, 1,0 }, q2 = { 10, 10,0 };
	doIntersect(p1, q1, p2, q2) ? std::cout << "Yes\n" : std::cout << "No\n";

	return 0;
}

#pragma endregion


