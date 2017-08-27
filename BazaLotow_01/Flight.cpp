#include "Includes.h"

Flight::Flight()
{
}

Flight::Flight(Flight & obj)
{
	this->id = obj.id;
	this->departure = obj.departure;
	this->destination = obj.destination;
	dep_time.year = obj.dep_time.year;
	dep_time.mon = obj.dep_time.mon;
	dep_time.day = obj.dep_time.day;
	dep_time.hour = obj.dep_time.hour;
	dep_time.min = obj.dep_time.min;
	length_min = obj.length_min;
	this->flight_type = obj.flight_type;
}

Flight::~Flight()
{
}

Flight::Flight(int id, Airport* departure, Airport* destination, int  year, int month, int day, int hour, int min, int lenght, char type)
{
	this->id = id;
	this->departure = departure;
	this->destination = destination;
	dep_time.year = year;
	dep_time.mon = month;
	dep_time.day = day;
	dep_time.hour = hour;
	dep_time.min = min;
	length_min = lenght;
	this->flight_type = type;
}

string Flight::ToString()
{
	string str;
	ostringstream oss;
	oss << "Lot nr" << id << "(" << dep_time.DateToString() << dep_time.TimeToString();
	oss << ")" << " z lotniska: " << departure->getName() << ", " << departure->getCountry();
	oss << " do: " << destination->getName() << ", " << destination->getCountry() << "  ";
	str = oss.str();
	return str;
}

long int Flight::getId()
{
	return id;
}

void Flight::setId()
{
	id = seed++;
}

Airport Flight::getDeparture()
{
	return *departure;
}

void Flight::setDeparture(Airport* param)
{
	departure = param;
}

Airport Flight::getDestination()
{
	return *destination;
}

void Flight::setDestination(Airport* param)
{
	destination = param;
}

myOwnTimeStruct Flight::getDep_time()
{
	return dep_time;
}

void Flight::setDep_time(int y, int m, int d, int h, int min)
{
	if ((y > 1950 && y < 2100) &&
		(	//warunmek na lata przestepne............<3
		(m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12) && (d > 0 && d < 32)
			||
			(m == 3 || m == 6 || m == 9 || m == 11) && (d > 0 && d < 31)
			||
			(m == 2 && d > 0 && d < 29)
			||
			(m == 2 && y % 4 == 0 && y % 10 != 0 && (d > 0 && d < 30))
			)
		&& (h > -1 && h < 24) && (min > -1 && min < 60))
	{
		dep_time.year = y;
		dep_time.mon = m;
		dep_time.day = d;
		dep_time.hour = h;
		this->dep_time.min = min;
	}
	else
	{
		cout << "Wrong data given. Default values have been set." << endl;
		dep_time.year = 0;
		dep_time.mon = 0;
		dep_time.day = 0;
		dep_time.hour = 0;
		this->dep_time.min = 0;
	}
}

int Flight::getLenght_min()
{
	return length_min;
}

void Flight::setLenght_min(int param)
{
	if (param <= 0)
	{
		cout << "Blednie wprowadzona wartosc czasu lotu. Wartosc powinna byc dodatnia..." << endl;
		cout << "Wcisnij X by zakonczyc podawanie danych" << endl;
		cin >> param;
		while (param <= 0)
		{
			cin >> param;
			if (param == 'X')	return;
		}

		length_min = param;
	}
	length_min = param;
}
void Flight::setFlight_type(char type)
{
	if (type == 'P' || type == 'C') flight_type = type;
	else
	{
		cout << "Wrong type value. Default set..." << endl;
		flight_type = '0';
	}
}
char Flight::getFlight_type()
{
	return flight_type;
}

long int  Flight::seed = 0;
