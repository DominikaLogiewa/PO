#include "Includes.h"


Passenger_flight::Passenger_flight() : Flight(), ticket_price(0) {}
Passenger_flight::Passenger_flight(Passenger_flight & obj): Flight(obj)
{
	ticket_price = obj.ticket_price;
}
;
Passenger_flight::Passenger_flight(int id, Airport* departure, Airport* destination,
								   int year, int month, int day, int hour, int min,
								   int length, float price, char type)
	: Flight(id, departure, destination, year, month, day, hour, min, length, type)
{
	ticket_price = price;
}


Passenger_flight::~Passenger_flight() {}

float Passenger_flight::getTicket_price()
{
	return ticket_price;
}

void Passenger_flight::setTicket_price(float price)
{
	if(price > 0)
		ticket_price = price;
	else
	{
		cout << "Wrong value for ticket price. Default value set" << endl;
		ticket_price = 250.0;
	}
}
string Passenger_flight::ToString()
{
	string str;
	ostringstream oss;
	oss << "Passenger flight:\t" << Flight::ToString() << "Price: " << getTicket_price();
	str = oss.str();
	return str;
}
