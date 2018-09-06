#pragma once
#include "TPolygon.h"
class TPyramid :
	public TPolygon
{
private:
	int X2, Y2; // point S of pyramid SABC...
	int H;
public:
	TPyramid();
	TPyramid(int n, int r, int x2, int y2, int h);
	~TPyramid();
	void input();
	void output();
	double square();
	double lateralSquare();
	double volume();
	double findLateralSide();
	double perim(); // perimeter of the pyramid (perimeter of the polygon + N*lateralSquare )
	friend ostream& operator<<(ostream& os, const TPyramid& ob);
	friend TPyramid operator++(TPyramid& ob);
	TPyramid operator--();
	bool operator<(TPyramid& ob2);
	bool operator>(TPyramid& ob2);
	bool operator>=(TPyramid& ob2);
	bool operator<=(TPyramid& ob2);
	int findMaxX(); // a function that finds the highest value of X from all vertices
	int findMinX(); // a function that finds the smallest value of X from all vertices
	bool operator*(TPyramid& ob2); // checks if the pyramids are intersecting
};