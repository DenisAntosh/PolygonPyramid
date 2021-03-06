#include "pch.h"
#include "TPolygon.h"
#include "TPyramid.h"
#include <iostream>
#include <cstdlib>
#include <cmath>
#include <conio.h>
#include <Windows.h>
#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable : 4996)

using namespace std;

int main()
{
	TPolygon Pol1, Pol2(3, 2, 4, 1), Pol3(Pol1), Pol4;
	TPyramid Pir1, Pir2;
	TPyramid Pir3(6, 50, 100, 100, 20);
	Pir3.output();
	int flag1, flag2, flag3;
	cout << "1 - to work with polygon\n2 - to work with pyramid" << endl;
	cout << "Enter the number: ";
	cin >> flag1;
	switch (flag1)
	{
	case 1:
		cout << endl;
		cout << "Enter the first polygon: " << endl;
		Pol1.input();
		cout << endl << "The fisrt polygon is: " << endl;
		Pol1.output();
		cout << endl << endl << "The third polygon is: " << endl;
		Pol3.output();
		cout << endl << endl << "The second polygon is: " << endl;
		Pol2.output();
		Pol4 = Pol2;
		cout << endl << endl << "The fourth polygon is: " << endl;
		Pol4.output();
		do
		{
			cout << endl;
			cout << "1 - to find the square\n2 - to find the perimetr\n3 - to fing the radius of the entered circle" << endl;
			cout << "4 - to fing the angle at the top\n5 - to check if Pol1 == Pol2\n6 - to check if Pol1 != Pol2" << endl;
			cout << "7 - to output the multicut\n8 - to check how many objects are created" << endl;
			cout << "9 - to draw the multicut\n10 - to shift the multicut k pixels to the left\n0 - to exit" << endl;
			cout << "Enter the number: ";
			cin >> flag2;
			switch (flag2)
			{
			case 1:
				cout << "The square of multicut is " << Pol1.square() << "." << endl;
				break;
			case 2:
				cout << "The perimetr of multicut is " << Pol1.perim() << "." << endl;
				break;
			case 3:
				cout << "The radius of the entered circle is " << Pol1.radiusOfEnteredCircle() << "." << endl;
				break;
			case 4:
				cout << "The angle at the top is " << Pol1.fingAngle() << "." << endl;
				break;
			case 5:
				if (Pol1 == Pol2)
					cout << "Yes, Pol1 = Pol2." << endl;
				else
					cout << "No, Pol1 != Pol2." << endl;
				break;
			case 6:
				if (Pol1 != Pol2)
					cout << "Yes, Pol1 != Pol2." << endl;
				else
					cout << "No, Pol1 == Pol2." << endl;
				break;
			case 7:
				cout << Pol1;
				break;
			case 8:
				cout << endl << "Is created " << Pol1.GetQuanObj() << " objects." << endl;
				break;
			case 9:
				drawPolygon(Pol1);
				break;
			case 10:
				int k;
				cout << "Enter k: ";
				cin >> k;
				Pol1.drawPolygon(k);
				break;
			case 0:
				cout << "Program ended the work!" << endl;
				break;
			default:
				cout << "You enter the bad number! Please, enter the number again!" << endl << endl;
			}
		} while (flag2 != 0);
		break;
	case 2:
		cout << "Enter the first pyramid: " << endl;
		Pir1.input();
		cout << endl << "Enter the second pyramid: " << endl;
		Pir2.input();
		do
		{
			cout << "1 - to fing the Lateral Square of the pyramid\n2 - to find the square of the pyramid" << endl;
			cout << "3 - to find the volume of the pyramid\n4 - to find the lateral Side of the pyramid" << endl;
			cout << "5 - to find the perimetr of the pyramid\n6 - to output the pyramid\n7 - to check if the pyramids are crossing over\n0 - to exit" << endl << endl;
			cout << "Enter the number: ";
			cin >> flag3;
			switch (flag3)
			{
			case 1:
				cout << "The laterat square of the pyramid is " << Pir1.lateralSquare() << "." << endl;
				break;
			case 2:
				cout << "The square of the pyramid is " << Pir1.square() << "." << endl;
				break;
			case 3:
				cout << "The volume of the pyramid is " << Pir1.volume() << "." << endl;
				break;
			case 4:
				cout << "The lateral side of the pyramis is " << Pir1.findLateralSide() << "." << endl;
				break;
			case 5:
				cout << "The perimetr of the pyramid is " << Pir1.perim() << "." << endl;
				break;
			case 6:
				cout << "The pyramid is:";
				cout << Pir1;
				break;
			case 7:
				if (Pir1 * Pir2)
					cout << "Yes, the pyramids are crossing over." << endl;
				else
					cout << "No, the pyramids aren't crossing over." << endl;
				break;
			case 0:
				cout << "Program ended the work!" << endl;
				break;
			default:
				cout << "You enter the bad number! Please, enter the number again!" << endl << endl;
			}

		} while (flag3 != 0);
		break;
	default:
		cout << "You enter the bad number!" << endl;
	}
	getch();
	return 0;
}