#include "pch.h"
#include "TPyramid.h"
#include <conio.h>
#define M_PI 3.14159265358979323846
#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable : 4996)

using namespace std;

TPyramid::TPyramid()
{
	cout << "The pyramid is created! " << endl;
	X2 = X1;
	Y2 = Y1;
	H = 0;
}

TPyramid::TPyramid(int n, int r, int x2, int y2, int h) : TPolygon(n, r, x2, y2)
{
	H = h;
	X2 = x2;
	Y2 = y2 + h;
}

TPyramid::~TPyramid()
{
	cout << endl << "The Pyramid is destroyed!" << endl;
	getch();
}

void TPyramid::input()
{
	cout << "Enter the number of sides of the multicut: ";
	cin >> N;
	cout << "Enter the the radius of described circle: ";
	cin >> R;
	cout << "Enter the point X1 ( (X1,Y1)  - centre of multucut) : ";
	cin >> X1;
	cout << "Enter the point Y1 ( (X1,Y1)  - centre of multucut) : ";
	cin >> Y1;
	if (N <= 2)
	{
		cout << "N must be bigger then 2! Please, enter N again: ";
		cin >> N;
	}
	if (R <= 0)
	{
		cout << "R must be bigger then 0! Please, enter R again: ";
		cin >> R;
	}
	cout << "Enter the hight of the pyramid: ";
	cin >> H;
	if (H <= 0)
	{
		cout << "The hight must be bigger then 0! Please, enter R again: ";
		cin >> R;
	}
	X2 = X1;
	Y2 = Y1 + H;
}

void TPyramid::output()
{
	cout << "The number of sides of the multicut is " << N << "." << endl;
	cout << "The the radius of described circle is " << R << "." << endl;
	cout << "The centre of polygon is (" << X1 << "," << Y1 << ")." << endl;
	cout << "The coordinate of first vertex of polygon is (" << X1 - R << "," << Y1 << ").";
	cout << " Copy - " << copy << "." << endl;
	cout << "The hight of the pyramid is " << H << "." << endl;
	cout << "The apex of the pyramid is (" << X2 << "," << Y1 + H << ")." << endl;
}

double TPyramid::lateralSquare()
{
	double apof = sqrt(H*H + this->radiusOfEnteredCircle() * this->radiusOfEnteredCircle());
	return 0.5*this->perim()*apof;
}

double TPyramid::square()
{
	return this->lateralSquare() + this->TPolygon::square();
}

double TPyramid::volume()
{
	return 1.0 / 3 * this->TPolygon::square() * H;
}

double TPyramid::findLateralSide()
{
	return sqrt(H*H + R * R);
}

double TPyramid::perim()
{
	return (this->TPolygon::perim() + this->N*this->findLateralSide());
}

ostream& operator<<(ostream& os, const TPyramid& ob)
{
	os << endl << "The number of sides of the multicut is " << ob.N << "." << endl;
	os << "The the radius of described circle is " << ob.R << "." << endl;
	os << "The centre of polygon is (" << ob.X1 << "," << ob.Y1 << ")." << endl;
	os << "The coordinate of first vertex of polygon is (" << ob.X1 - ob.R << "," << ob.Y1 << ")." << endl;
	os << "The hight of the pyramid is " << ob.H << endl;
	os << "The apex of the pyramid is (" << ob.X2 << "," << ob.Y2 << ")." << endl;
	return os;
}

TPyramid operator++(TPyramid& ob)
{
	ob.H++;
	return ob;
}

TPyramid TPyramid::operator--()
{
	this->H--;
	return *this;
}

bool TPyramid::operator<(TPyramid& ob2)
{
	return this->volume() < ob2.volume();
}

bool TPyramid::operator>(TPyramid& ob2)
{
	return this->volume() > ob2.volume();
}

bool TPyramid::operator<=(TPyramid& ob2)
{
	return this->volume() <= ob2.volume();
}

bool TPyramid::operator>=(TPyramid& ob2)
{
	return this->volume() >= ob2.volume();
}

int TPyramid::findMaxX()
{
	int max = -100000;
	for (int i = 0; i < this->N; i++)
	{
		if ((this->X1 - this->R*cos(i * 360 / this->N * M_PI / 180) > max))
			max = (this->X1 - this->R*cos(i * 360 / this->N * M_PI / 180));
	}
	return max;
}

int TPyramid::findMinX()
{
	int min = 100000;
	for (int i = 0; i < this->N; i++)
	{
		if ((this->X1 - this->R*cos(i * 360 / this->N * M_PI / 180) < min))
			min = (this->X1 - this->R*cos(i * 360 / this->N * M_PI / 180));
	}
	return min;
}

bool TPyramid::operator*(TPyramid& ob2)
{
	return (this->findMaxX() > ob2.findMinX());
}