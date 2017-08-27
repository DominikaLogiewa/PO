#pragma once

class Passenger_flight : public Flight
{

	float ticket_price;

public:
	Passenger_flight();
	Passenger_flight(Passenger_flight &obj);
	Passenger_flight(int id, Airport* departure, Airport* destination,
					 int year, int month, int day, int hour, int min,
					 int length, float price, char type);
	~Passenger_flight();

    // getters and setters
	float getTicket_price();
	void setTicket_price(float price);

	string ToString();

	// FUNKCJA PSIAPSIӣKA!

	friend List<Flight*>* loadFlights(List<Airport>*);
};

