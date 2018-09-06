#pragma once
#include <iostream>
#include <Windows.h>

using namespace std;

class TPolygon
{
protected:
	int R;
	int N;
	int X1;
	int Y1;
	int num;
	static int QuanObj;
	bool copy;
public:
	static int GetQuanObj() { return QuanObj; }
	void input();
	void output() const;
	TPolygon();
	TPolygon(int n, int r, int x1, int y1);
	TPolygon(const TPolygon& ob2);
	~TPolygon();
	TPolygon operator=(const TPolygon& ob2);
	bool operator==(const TPolygon& ob2);
	bool operator!=(const TPolygon& ob2);
	double fingAngle();
	double square();
	double perim();
	double radiusOfEnteredCircle();
	friend ostream& operator<<(ostream& os, const TPolygon& ob);
	friend void drawPolygon(const TPolygon& ob);
	void drawPolygon(int left);
};
