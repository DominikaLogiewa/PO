#include "Includes.h"

Airport::Airport(int ID, string NAME, string COUNTRY) {
	id = ID;
	this->setName(NAME);
	this->setCountry(COUNTRY);
}
Airport::Airport() : id(-1), name("DEFAULT"), country("DEFAULT") {};

Airport::~Airport() {}

string Airport::ToString() {
	string str;
	ostringstream oss;
	oss << name << ", " << country << " ";
	str = oss.str();
	return str;
}

int Airport::getId() {
	return id;
}

void Airport::setId() {
	id = ++seed;
}

string Airport::getName() {
	return name;
}

void Airport::setName(string name) {
	transform(name.begin(), name.end(), name.begin(), ::tolower);
	name[0] = toupper(name[0]);
	this->name = name;
}

string Airport::getCountry() {
	return country;
}

void Airport::setCountry(string country) {
	transform(country.begin(), country.end(), country.begin(), ::toupper);
	this->country = country;
}

long int  Airport::seed = 0;