#include "pch.h"
#include "TPolygon.h"
#include <iostream>
#include <cstdlib>
#include <cmath>
#include <conio.h>
#include <Windows.h>
#define M_PI 3.14159265358979323846
#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable : 4996)

using namespace std;

int TPolygon::QuanObj = 0;

void TPolygon::input()
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
}

void TPolygon::output() const
{
	cout << "The number of sides of the multicut is " << N << "." << endl;
	cout << "The the radius of described circle is " << R << "." << endl;
	cout << "The centre of polygon is (" << X1 << "," << Y1 << ")." << endl;
	cout << "The coordinate of first vertex of polygon is (" << X1 - R << "," << Y1 << ").";
	cout << " Copy - " << copy << "." << endl;
}

TPolygon::TPolygon()
{
	N = 0;
	R = 0;
	X1 = 0;
	Y1 = 0;
	num = ++QuanObj;
	copy = false;
	cout << "The object number " << num << " is created and initialized by 0!" << " Copy - " << copy << "." << endl;
}

TPolygon::TPolygon(int n, int r, int x1, int y1)
{
	N = n;
	R = r;
	X1 = x1;
	Y1 = y1;
	num = ++QuanObj;
	copy = false;
	if (n <= 2)
	{
		cout << "N must be bigger then 2! Please, enter N again: ";
		cin >> N;
	}
	if (r <= 0)
	{
		cout << "R must be bigger then 0! Please, enter R again: ";
		cin >> R;
	}
	cout << endl << "The object number " << num << " is set to " << n << " " << r << " " << x1 << " " << y1 << ". " << "Copy - " << copy << "." << endl;
}

TPolygon::~TPolygon()
{
	cout << endl << "The object number " << num << " is destroyed!" << " Copy - " << copy << "." << endl;
	getch();
}

TPolygon::TPolygon(const TPolygon& Pol2)
{
	num = ++QuanObj;
	N = Pol2.N;
	R = Pol2.R;
	X1 = Pol2.X1;
	Y1 = Pol2.Y1;
	copy = true;
	cout << endl << "Is created object number " << num << ". It is a copy!" << " Copy - " << copy << " to a object " << Pol2.num << "." << endl;
}

TPolygon TPolygon::operator=(const TPolygon& Pol2)
{
	if (this == &Pol2)
	{
		cerr << "Eror! " << endl;
		return *this;
	}
	this->N = Pol2.N;
	this->R = Pol2.R;
	this->X1 = Pol2.X1;
	this->Y1 = Pol2.Y1;
	this->copy = true;
	return *this;
}

bool TPolygon::operator==(const TPolygon& ob2)
{
	if ((this->N == ob2.N) && (this->R == ob2.R) && (this->X1 == ob2.X1) && (this->Y1 == ob2.Y1))
		return true;
	return false;
}

bool TPolygon::operator!=(const TPolygon& ob2)
{
	if ((this->N != ob2.N) || (this->R != ob2.R) || (this->X1 != ob2.X1) || (this->Y1 != ob2.Y1))
		return true;
	return false;
}

ostream& operator<<(ostream& os, const TPolygon& ob)
{
	os << endl << "The number of sides of the multicut is " << ob.N << "." << endl;
	os << "The the radius of described circle is " << ob.R << "." << endl;
	os << "The centre of polygon is (" << ob.X1 << "," << ob.Y1 << ")." << endl;
	os << "The coordinate of first vertex of polygon is (" << ob.X1 - ob.R << "," << ob.Y1 << ")." << endl;
	return os;
}

double TPolygon::fingAngle()
{
	return double(180 * (this->N - 2) / (this->N));
}

double TPolygon::radiusOfEnteredCircle()
{
	return double(this->R * cos(180 / this->N * M_PI / 180));
}

double TPolygon::perim()
{
	double a = double(sin(180 / this->N * M_PI / 180) * 2 * this->radiusOfEnteredCircle());
	return this->N * a;
}

double TPolygon::square()
{
	return double(0.5 * this->perim() * this->radiusOfEnteredCircle());
}

void drawPolygon(const TPolygon& ob)
{
	HWND hwnd = GetConsoleWindow();;
	HDC hdc = GetDC(hwnd);
	HPEN p1, p2 = CreatePen(PS_SOLID, 5, RGB(255, 255, 0));

	p1 = (HPEN)SelectObject(hdc, p2);
	SelectObject(hdc, p1);
	Rectangle(hdc, 0, 0, 1500, 1500);
	MoveToEx(hdc, ob.X1 - ob.R, ob.Y1, NULL);
	for (int i = 0; i < ob.N + 1; i++)
		LineTo(hdc, ob.X1 - ob.R*cos(i * 360 / ob.N * M_PI / 180), ob.Y1 + ob.R*sin(i * 360 / ob.N * M_PI / 180));
	DeleteObject(p2);
	ReleaseDC(hwnd, hdc);
}

void TPolygon::drawPolygon(int left)
{
	HWND hwnd = GetConsoleWindow();;
	HDC hdc = GetDC(hwnd);
	HPEN p1, p2 = CreatePen(PS_SOLID, 5, RGB(255, 255, 0));

	p1 = (HPEN)SelectObject(hdc, p2);
	SelectObject(hdc, p1);
	Rectangle(hdc, 0, 0, 1500, 1500);
	X1 -= left;
	MoveToEx(hdc, this->X1 - this->R - left, this->Y1, NULL);
	for (int i = 0; i < this->N + 1; i++)
		LineTo(hdc, X1 - this->R*cos(i * 360 / N * M_PI / 180) - left, Y1 + this->R*sin(i * 360 / this->N * M_PI / 180));
	DeleteObject(p2);
	ReleaseDC(hwnd, hdc);
}