#pragma once

class Airport
{
	static long int seed;
	int id;
	string name;
	string country;
public:
	Airport(int id, string name, string country);
	Airport();
	~Airport();
	string ToString();

	// FUNKCJE PSIAPSIӣKI!

	friend List<Airport>* loadAirports();
	friend List<Flight*>* loadFlights(List<Airport>*);

	int getId();
	void setId();
	string getName();
	void setName(string name);
	string getCountry();
	void setCountry(string country);
	bool operator>(Airport& r) {
		if (country.compare(r.country)>0) return true; else return false;
	};
	bool operator<(Airport& r) {
		if (country.compare(r.country)<0) return true; else return false;
	};
	bool operator>=(Airport& r) {
		if (country.compare(r.country) >= 0) return true; else return false;
	};
	bool operator<=(Airport& r) {
		if (country.compare(r.country) <= 0) return true; else return false;
	};
	bool operator==(Airport& r) {
		if (country.compare(r.country) == 0 && name.compare(r.name) == 0) return true; else return false;
	};
	Airport& operator=(Airport& r) {
		id = r.id;
		name = r.name;
		country = r.country;
		return *this;
	};

};

