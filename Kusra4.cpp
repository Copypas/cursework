#include "stdafx.h"
#include <iostream>
#include "HouseManager.h"

using namespace std;

void showMainMenu()

{

	cout << "--- House Manager ---" << endl

		<< "0 - Exit" << endl

		<< "1 - Add houses to list" << endl

		<< "2 - Show houses list" << endl

		<< "3 - Show number of houses in list" << endl

		<< "4 - Save list into separate files" << endl

		<< "5 - Find by type" << endl

		<< "6 - Change house color" << endl

		<< "-> ";

}

int main()

{

	setlocale(LC_ALL, "Russian");

	HouseManager Houses;

	showMainMenu();

	int c;

	do

	{

		cin >> c;

		switch (c)

		{

		case 1: { Houses.Add(); cout << "house added." << endl; break; }

		case 2: { cout << "Top of list." << endl; Houses.Show(); cout << "End of list." << endl; break; }

		case 3: { cout << "Number of houses in list: " << Houses.Number() << endl; break; }

		case 4: { Houses.SaveToFile("cottage.txt", "panelhouse.txt", "brickhouse.txt", "brick-monolithichouse.txt"); cout << "Saved." << endl; break; }

		case 5: { Houses.ShowType(); break; }

		case 6: { Houses.ChangeColor(); break; }

		case 0: { cout << "Exiting program." << endl; return 0; }

		}

		system("pause");

		system("cls");

		showMainMenu();

	} while (1);

	return 0;

}