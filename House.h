#pragma once
#include <iostream>

#include <string>

#include "Add.h"

using namespace std;

#define gen_fem 0

#define gen_male 1

#define house_type_cottage 0

#define house_type_panelHouse 1

#define house_type_brickHouse 2

#define house_type_bmHouse 3
static int indentificator=0;

class House

{

protected:

	int type;

private:
	int id = indentificator++;

	string Description;

	string colour;

	string address;

	int level;

	Date builtDate;

	int size;

	int apartments;

	string type2str();

public:

	virtual ~House() {}

	virtual void Read(istream &is = cin);

	virtual void Print(ostream &os = cout);

	int getType() { return type; }
	int getID() { return id; }

	void setColor(string color) { colour = color; }

};

string House::type2str()

{

	switch (type)

	{

	case house_type_cottage: return "cottage";

	case house_type_panelHouse: return "panel house";

	case house_type_brickHouse: return "brick house";

	case house_type_bmHouse: return "Brick-monolithic house";


	}

}

void House::Read(istream &is)

{
	if (&is == &cin) is.ignore(std::numeric_limits<size_t>::max(), '\n');

	is.clear();


	if (&is == &cin) cout << "Input Description -> ";

	getline(is, Description);

	is.clear();

	if (&is == &cin) cout << "Input colour -> ";

	getline(is, colour);

	is.clear();

	if (&is == &cin) cout << "Input address -> ";

	getline(is, address);

	is.clear();

	for (int i = 0; i<1; ++i)
		try
		{

			if (&is == &cin) cout << "Input level's count -> ";

			string c;
			getline(is, c);

			is.clear();

			level = stoi(c);

		}

		catch (char * err)

		{

			if (&is == &cin)

			{

				system("cls");

				cout << err << " Try again." << endl;

				i--;

			}

			else throw ("Error reading file. Level's count.");

		}

		for (int i = 0; i<1; ++i)
			try
		{
			is.clear();
			if (&is == &cin) cout << "Input house size -> ";

			string c;
			getline(is, c);

			if (c != "")
				size = stoi(c);
			is.clear();
		}

		catch (char * err)

		{

			if (&is == &cin)

			{

				system("cls");

				cout << err << " Try again." << endl;

				i--;

			}

			else throw ("Error reading file. House size.");

		}


		for (int i = 0; i<1; ++i)
			try
		{

			if (&is == &cin) cout << "Input apartments number -> ";

			string c;
			getline(is, c);

			is.clear();

			apartments = stoi(c);

		}

		catch (char * err)

		{

			if (&is == &cin)

			{

				system("cls");

				cout << err << " Try again." << endl;

				i--;

			}

			else throw ("Error reading file. Apartments number.");

		}

	for (int i = 0; i<1; ++i)
		try
		{

			if (&is == &cin) cout << "Input built date (dd.mm.yyyy) -> ";

			is >> builtDate;
			is.clear();

		}

		catch (char * err)

		{

			if (&is == &cin)

			{

				system("cls");

				cout << err << " Try again." << endl;

				i--;

			}

			else throw ("Error reading file. Incorrect date.");

		}

		


}

void House::Print(ostream &os)

{

	if (&os == &cout) { cout << "Type: "; cout << type2str() << endl; }

	if (&os == &cout) cout << "Description: ";

	os << Description << endl;

	if (&os == &cout) cout << "Colour: ";

	os << colour << endl;

	if (&os == &cout) cout << "Adress: ";

	os << address << endl;

	if (&os == &cout) cout << "Levels: ";

	os << level << endl;


	if (&os == &cout) cout << "size: ";

	os << size << endl;

	if (&os == &cout) cout << "apartments number: ";

	os << apartments << endl;

	if (&os == &cout) cout << "Built date: ";

	os << builtDate << endl;

}

//-----------------------------------------------------------------------------

class Cottage : public House

{

public:

	void Read(istream &is = cin) { type = house_type_cottage; House::Read(is); }

};

class Panel_house : public House

{

public:

	void Read(istream &is = cin) { type = house_type_panelHouse; House::Read(is); }

};

class Brick_house : public House

{

public:

	void Read(istream &is = cin) { House::Read(is); type = house_type_brickHouse; }

};

class Brick_monolithic_house : public House

{

public:

	void Read(istream &is = cin) { House::Read(is); type = house_type_bmHouse; }

};
