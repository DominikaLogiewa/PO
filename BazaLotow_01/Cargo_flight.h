#pragma once

class Cargo_flight :
	public Flight
{
	//static long int seed;
	float price_per_kg;
	//long int id;
public:
	
	Cargo_flight();
	Cargo_flight(Cargo_flight &obj);
	Cargo_flight(int id, Airport* departure, Airport* destination, int year, int month, int day, int hour, int min, int length, float price, char type);
	~Cargo_flight();
	float getPrice_per_kg();
	void setPrice_per_kg(float price);
	string ToString();
//	long int getId();
//	void setId();
//	static void setSeed_0();

	// FUNKCJA PSIAPSIӣKA!

	friend List<Flight*>* loadFlights(List<Airport>*);

};


