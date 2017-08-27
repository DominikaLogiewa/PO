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
	Flight(int id, Airport* departure, Airport* destination, int year, int month, int day, int hour, int min, int length, char type);
	virtual string ToString();
	long int getId();
	void setId();
	Airport getDeparture();
	void setDeparture(Airport* param);
	Airport getDestination();
	void setDestination(Airport* param);
	struct myOwnTimeStruct getDep_time();
	void setDep_time(int y, int m, int d, int h, int min);
	int getLenght_min();
	void setLenght_min(int param);
	void setFlight_type(char type);
	char getFlight_type();

	// FUNKCJA PSIAPSIӣKA!

	friend List<Flight*>* loadFlights(List<Airport>*);

	//PRZECIAZENIE OPERATOROW OLABOGA POMOCY!

	bool operator>(Flight& r)
	{
		if (r.dep_time.GetHash() > r.dep_time.GetHash())	return true;
		else	return false;
	};
	bool operator<(Flight& r) {
		if (r.dep_time.GetHash() < r.dep_time.GetHash())	return true;
		else	return false;	
	};
	bool operator>=(Flight& r)
	{
		if (r.dep_time.GetHash() >= r.dep_time.GetHash())	return true;
		else	 return false;
	};
	bool operator <= (Flight& r)
	{
		if (r.dep_time.GetHash() <= r.dep_time.GetHash())	return true;
		else	return false;
	};
	bool operator==(Flight& r)
	{
		if (r.dep_time.GetHash() == r.dep_time.GetHash())	return true;
		else	return false;	
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

