#include "Includes.h"

Cargo_flight::Cargo_flight() : Flight(), price_per_kg(0) {}

Cargo_flight::Cargo_flight(Cargo_flight & obj) : Flight(obj)
{
	price_per_kg = obj.price_per_kg;
}
;

Cargo_flight::Cargo_flight(int id, Airport* departure, Airport* destination,
						   int year, int month, int day, int hour, int min,
						   int length, float price, char type)
	: Flight(id, departure, destination, year, month, day, hour, min, length, type)
{
	price_per_kg = price;
}



Cargo_flight::~Cargo_flight()
{}

float Cargo_flight::getPrice_per_kg()
{
	return price_per_kg;
}

void Cargo_flight::setPrice_per_kg(float price)
{
		if (price <= 0)
		{
			cout << "Wrong price value. Default value has been set" << endl;
			price_per_kg = 10.0;
		}
		else	price_per_kg = price;
}

string Cargo_flight::ToString()
{
	string str;
	ostringstream oss;
	oss << "Cargo flight:\t\t" << Flight::ToString()<< "Price/kg: " << getPrice_per_kg();
	str = oss.str();
	return str;
}

// FIXME NOT IMPLEMENTED YET

//long int Cargo_flight::getId()
//{
//	return id;
//}

//void Cargo_flight::setId()
//{
//}

//long int Cargo_flight::getId()
//{
//	return id;
//}
//
//void Cargo_flight::setId()
//{
//	id = seed++;
//}
//
//void Cargo_flight::setSeed_0()
//{
//	seed = 0;
//}
