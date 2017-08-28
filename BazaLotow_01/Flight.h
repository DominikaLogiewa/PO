#pragma once

class Airport;
class Flight
{
	static long int seed;
	long int id;
	Airport* departure;
	Airport* destination;
	struct myOwnTimeStruct dep_time;
	int length_min;
	char flight_type;

public:

	Flight();
	Flight(Flight &obj);
	~Flight();
	Flight(int id, Airport* departure, Airport* destination,
		int year, int month, int day, int hour, int min, int length, char type);

	virtual string ToString();

	// setters and getters
	long int getId();
	void setId();
	Airport getDeparture();
	void setDeparture(Airport* param);
	Airport getDestination();
	void setDestination(Airport* param);
	void setDep_time(int y, int m, int d, int h, int min);
	int getLenght_min();
	void setLenght_min(int param);
	void setFlight_type(char type);
	char getFlight_type();

	struct myOwnTimeStruct getDep_time();

	// FUNKCJA PSIAPSIӣKA!

	friend List<Flight*>* loadFlights(List<Airport>*);
	friend class List<Flight>;
	friend  class List<Airport>;
	// overloading operators > < <= >= ==
	// allows to compare 2 different flight objects based on the departure time

	bool operator>(Flight& r)
	{
		return r.dep_time.GetHash() > r.dep_time.GetHash();
	};

	bool operator<(Flight& r)
	{
		return r.dep_time.GetHash() < r.dep_time.GetHash();
	};

	bool operator>=(Flight& r)
	{
		return r.dep_time.GetHash() >= r.dep_time.GetHash();
	};

	bool operator <= (Flight& r)
	{
		return r.dep_time.GetHash() <= r.dep_time.GetHash();
	};

	bool operator==(Flight& r)
	{
		return  r.dep_time.GetHash() == r.dep_time.GetHash();
	};

	Flight& operator=(Flight& r)
	{
		id = r.id;
		departure = r.departure;
		destination = r.destination;
		dep_time = r.dep_time;
		length_min = r.length_min;
		return *this;
	};
};