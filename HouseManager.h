#pragma once
#include <iostream>

#include <list>

#include <fstream>

#include "Factory.h"

//using namespace std;

class HouseManager

{

	list <House*> hous;

public:

	void Add();

	void SaveToFile(string fcottage, string fpannel, string fbrick,

		string fbm);

	void Show();
	void ShowType();
	void ChangeColor();
	int Number() { return hous.size(); }

};

void HouseManager::Add()

{

	Cottage_Factory cottage;

	Panel_house_Factory panelHouse;

	Brick_house_Factory brickHouse;

	Brick_monolithic_house_Factory bmHouse;


	bool add = 1;

	do

	{

		bool del = false;

		Factory *factory;

		cout << "Input type of house" << endl

			<< "0-cottage, 1-panel house, 2-brick house, 3-brick-monolithic house" << endl

			<< "-> ";

		int choice_house;

		cin >> choice_house;

		switch (choice_house)

		{

		case house_type_cottage: { factory = &cottage; break; }

		case house_type_panelHouse: { factory = &panelHouse; break; }

		case house_type_brickHouse: { factory = &brickHouse; break; }

		case house_type_bmHouse: { factory = &bmHouse; break; }

		default: { throw ("Incorrect type of house"); break; }

		}

		House *ObjectHouse = CreateHouse(factory);

		cout << "Input type of adding data" << endl

			<< "c - console, f - file" << endl

			<< "-> ";

		char choice_input;

		cin >> choice_input;

		switch (choice_input)

		{

		case 'c':

		{

			ObjectHouse->Read();

			break;

		}

		case 'f':

		{

			string fname;

			cout << "Input file name -> ";

			cin >> fname;

			ifstream fpin(fname + ".txt");

			try

			{

				if (!fpin) throw ("File not found");
				ObjectHouse->Read(fpin);

			}

			catch (char * err)

			{

				cout << err << endl << "Closing file." << endl;

				del = true;

			}

			fpin.close();

			break;

		}

		default:

		{

			cout << "Incorrect symbol." << endl;

			del = true;

		}

		}

		hous.push_back(ObjectHouse);

		if (del)

		{

			cout << "Deleting this house." << endl;

			hous.pop_back();

			del = false;

		}

		cout << "Do you want to add another house? (0/1) -> ";

		cin >> add;

	} while (add);

}

void HouseManager::Show()

{

	for (auto v : hous)

	{

		cout << "--------------------" << endl;
		cout << "ID: ";

		cout << v->getID() << endl;
		v->Print();
		cout << "--------------------" << endl;

	}

}

void HouseManager::ShowType()

{
	cout << "Input type of house" << endl

		<< "0-cottage, 1-panel house, 2-brick house, 3-brick-monolithic house" << endl

		<< "-> ";

	int choice_type;

	cin >> choice_type;

	
	cout << "Top of list." << endl;
	for (auto v : hous)
	{
		if (v->getType() == choice_type)
		{
			cout << "--------------------" << endl;
			cout << "ID: ";

			cout << v->getID() << endl;
			v->Print();
			cout << "--------------------" << endl;
		}

	}
	cout << "End of list." << endl;

}

void HouseManager::ChangeColor()
{
	cout << "Input id" << endl << "-> ";

	int id;

	cin >> id;
	cout << "Input color" << endl << "-> ";

	string color;

	cin >> color;


	for (auto v : hous)
	{
		if (v->getID() == id)
		{
			v->setColor(color);
		}

	}

}

void HouseManager::SaveToFile(string fcottage, string fpannel, string fbrick,

	string fbm)

{

	bool clr;

	cout << "Do you want to clear files first? (0/1) -> ";

	cin >> clr;

	if (clr)

	{

		clrFile(fcottage);

		clrFile(fpannel);

		clrFile(fbrick);

		clrFile(fbm);


	}

	for (auto v : hous)

	{

		if (v->getType() == house_type_cottage)

		{

			ofstream fpout;

			fpout.open(fcottage, ios::app);

			v->Print(fpout);

			fpout.close();

		}

		else if (v->getType() == house_type_panelHouse)

		{

			ofstream fpout;

			fpout.open(fpannel, ios::app);

			v->Print(fpout);

			fpout.close();

		}

		else if (v->getType() == house_type_brickHouse)

		{

			ofstream fpout;

			fpout.open(fbrick, ios::app);

			v->Print(fpout);

			fpout.close();

		}

		else if (v->getType() == house_type_bmHouse)

		{

			ofstream fpout;

			fpout.open(fbm, ios::app);

			v->Print(fpout);

			fpout.close();

		}

	}
}