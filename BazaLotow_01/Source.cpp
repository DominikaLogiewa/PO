#include "Includes.h"

List<Airport>* loadAirports() {
	List<Airport>* value = new List<Airport>();
	ifstream db;
	db.open("airports.txt", ios::in);
	if (!db.is_open()) {
		cout << "No db file found. Aborting." << endl;
		system("pause");
		exit(0);
	}
	while (!db.eof()) {
		Airport dummy;
		db >> dummy.id >> dummy.name >> dummy.country;
		dummy.id == -1 ? NULL : value->addElement(dummy);
	}
	return value;
}

List<Flight*>* loadFlights(List<Airport>* AirportList) {
	List<Flight*>* value = new List<Flight*>();
	ifstream db;
	db.open("flights.txt", ios::in);
	if (!db.is_open()) {
		cout << "No db file found. Aborting." << endl;
		std::system("pause");
		exit(0);
	}
	for (int i = 0; i < 4; i++) {
		string myLovelyLookingHeaders;
		// Pozbawiamy si� linii nag��wkowej
		getline(db, myLovelyLookingHeaders); 
	}
	while (!db.eof()) {
		Airport dep, dest;
		char flightType = 0;
		db >> flightType;

		if (flightType == 'P') {
			// FIXME
			Passenger_flight dummy;
			dummy.flight_type = 'P';
			db >> dummy.id >> dep.name >> dep.country >> dest.name >> dest.country >> dummy.dep_time.year >> dummy.dep_time.mon >> dummy.dep_time.day >> dummy.dep_time.hour >> dummy.dep_time.min >> dummy.length_min >> dummy.ticket_price;

			dummy.setDeparture(AirportList->findElement(dep));
			dummy.setDestination(AirportList->findElement(dest));
			dummy.id == -1 ? NULL : value->addElement(new Passenger_flight(dummy));
		}

		else if (flightType == 'C') {
			// FIXME
			Cargo_flight dummy;
			dummy.flight_type = 'C';
			db >> dummy.id >> dep.name >> dep.country >> dest.name >> dest.country >> dummy.dep_time.year >> dummy.dep_time.mon >> dummy.dep_time.day >> dummy.dep_time.hour >> dummy.dep_time.min >> dummy.length_min >> dummy.price_per_kg;
			dummy.setDeparture(AirportList->findElement(dep));
			dummy.setDestination(AirportList->findElement(dest));
			dummy.id == -1 ? NULL : value->addElement(new Cargo_flight(dummy));
		}

		else if (flightType == '\0') { ; }

		else {
			// FIXME
			cout << "Database corrupted. Incorrect Flight Type Data. Aborting." << endl;
			std::system("pause");
			exit(0);
		}
	}
	return value;
}

int main() {
	// Ustawienie nazwy okna konsoli
	std::system("title FLIGHTS");

	// Dane o oknie konsoli
	HWND console = GetConsoleWindow();

	// Prostok�cik?
	RECT r;
	GetWindowRect(console, &r);
	MoveWindow(console, r.left, r.top, 1200, 900, TRUE); // Ustawiamy wymiary okienka konsoli

	cout << "Strating program..." << endl;
	cout << "Loading ariport dababase file ..." << endl;

	List<Airport>* Airport_list = loadAirports();
	if (Airport_list->isEmpty()) {
		cout << "Airport database file is empty ora has not been created. Adding a new, empty database for airports..." << endl;
		FILE* db = NULL;
		db = fopen("airport.txt", "w");
		if (db == NULL) {
			cout << "Couldn't create new database on your disk. Without it the program will nor run properly. Exiting..." << endl;
			std::system("pause");
			exit(0);
		}
		cout << "Airport database file created (\"airports.txt\")" << endl;
	}
	else 		cout << "Airport database successfully loaded!" << endl;

	List<Flight*>* Flight_list = loadFlights(Airport_list);

	if (Flight_list->isEmpty()) {
		cout << "Flights database file is empty ora has not been created. Adding a new, empty database for flights..." << endl;
		FILE* db = NULL;
		db = fopen("flights.txt", "w");

		// plik z dana bazych nie zostal znaleziony
		if (db == NULL) {
			cout << "Couldn't create new database on your disk. Without it the program will nor run properly. Exiting..." << endl;
			std::system("pause");
			exit(0);
		}

		cout << "flights database file created (\"airports.txt\")" << endl;
	}

	else 		
		cout << "Flights database successfully loaded!" << endl;

	system("pause");

	while (1) {
		system("cls");
		int option;
		cout << "Choose an action:" << endl << endl;
		cout << "[1] View all the airports" << endl;
		cout << "[2] Add an  airport" << endl;
		cout << "[3] View all the flights" << endl;
		cout << "[4] Add a flight" << endl;
		cout << "[5] View flights from a given airport" << endl;
		cout << "[6] Find the shortest route" << endl;
		cout << "[7] Exit" << endl;
		cin >> option;
		cin.clear();
		switch (option) {
		case 1:
			system("cls");
			cout << "LIST OF AIRPORTS" << endl << "Sorted by country name" << endl << endl;
			Airport_list->print();
			system("pause");
			continue;
		case 2:
		case 3: {
			while (1) {
				List<Flight*>* COPIED_Flight_list = Flight_list->copyt_list_of_type();
				COPIED_Flight_list->sort_by_airport_name(COPIED_Flight_list);
				system("pause");
				break;
			}
		}
		break;
		//////////////////////////massive bugs down below///////////////////////////////
		case 4: {
			int choice;
			char type;
			Airport dummy;
			List<Flight*>* COPIED_Flight_list = Flight_list->copyt_list_of_type();
			if (COPIED_Flight_list->isEmpty()) {
				cout << "Currently there are no flights of desired type." << endl;
				break;
			}
			while (1) {
				cout << "What airport would you like to fly from?" << endl << " COUNTRY: \t" << endl;
				string name, country;
				cin.clear();
				cin >> country;
				cout << "AIRPORT NAME:\t" << endl;
				cin.clear();
				cin >> name;
				dummy.setId();
				dummy.setCountry(country);
				dummy.setName(name);
				Airport* pointer = Airport_list->findElement(dummy);
				while (pointer == NULL) {
					cin.clear();
					cout << "No such airport has been found. Would you like to [1]try again or [2]go back to main menu?" << endl;
					cin >> choice;
					if (choice == 1)
						break;
					else {
						while (choice != 2 && choice != 1) {
							cout << "Wrong input. Try again" << endl;
							break;
						}
					}
				}
			}
			ListNode<Flight*>* pointer2 = COPIED_Flight_list->head;
			while (pointer2) {
				//do type AND airport match
				if (pointer2->getData()->getDeparture() == dummy
					&& pointer2->getData()->getFlight_type() == COPIED_Flight_list->head->getData()->getFlight_type()) {
					cout << pointer2->getData()->ToString() << endl;
				}
				pointer2 = pointer2->nextNode;
			}
		}
		case 5: {
			string country, airport_name;
			int choice = -1;
			system("cls");
			while (1) {
				cout << "Type in the airport name:" << endl;
				cin.clear();
				cin.ignore();
				cin >> airport_name;
				cout << "Type in the country" << endl;
				cin.clear();
				cin.ignore();
				cin >> country;

				transform(country.begin(), country.end(), country.begin(), ::toupper);
				transform(airport_name.begin(), airport_name.end(), airport_name.begin(), ::tolower);
				airport_name[0] = toupper(airport_name[0]);

				Airport dummy(-1, airport_name, country);
				if (Airport_list->findElement(dummy) == NULL) {
					cout << "No such airport. Seems like there are no flights from there..." << endl;
					cout << "Would you like to try another airport? [1]Yes\[2]No: " << endl;
					cin.clear();
					cin >> choice;
					if (choice == 1) continue;
					else if (choice == 2) break;
					else {
						while (choice != 2 && choice != 1) {
							cout << "Wrong input. Try again:" << endl;
							cout << "Would you like to try another airport? [1]Yes\[2]No: " << endl;
							cin.clear();
							cin.ignore();
							cin >> choice;
						}
					}
				}
				else {
					cout << "FLIGHTS FROM " << dummy.ToString() << endl << endl;
					//TODO  lista z konkretnego lotniska

					system("cls");
					break;
				}
			}
		}
		case 6: {
			while (1) {
				string country_1, airport_name_1, country_2, airport_name_2;
				int choice = -1;
				system("cls");
				cout << "Type in the departure airport name:" << endl;
				cin.clear();
				cin.ignore();
				cin >> airport_name_1;
				cout << "Type in the departure country" << endl;
				cin.clear();
				cin >> country_1;
				cout << "Type in the destination airport name:" << endl;
				cin.clear();
				cin.ignore();
				cin >> airport_name_2;
				cout << "Type in the destination country" << endl;
				cin.clear();
				cin.ignore();
				cin >> country_2;
				transform(country_1.begin(), country_1.end(), country_1.begin(), ::toupper);
				transform(airport_name_1.begin(), airport_name_1.end(), airport_name_1.begin(), ::tolower);
				airport_name_1[0] = toupper(airport_name_1[0]);
				transform(country_2.begin(), country_2.end(), country_2.begin(), ::toupper);
				transform(airport_name_2.begin(), airport_name_2.end(), airport_name_2.begin(), ::tolower);
				airport_name_2[0] = toupper(airport_name_2[0]);
				Airport A1(-1, airport_name_1, country_1);
				Airport A2(-1, airport_name_2, country_2);
				if (Airport_list->findElement(A1) == NULL || Airport_list->findElement(A2) == NULL) {
					cout << "One of the airports you're looking for has not been found. Would you like to search again? [1]Yes\[2]No" << endl;
					cin.clear();
					cin.ignore();
					cin >> choice;
					if (choice == 1) continue;
					else if (choice == 2) break;
					else {
						while (choice != 2 && choice != 1) {
							cout << "Wrong input. Try again" << endl;
							cout << "One of the airports you're looking for has not been found. Would you like to search again? [1]Yes\[2]No" << endl;
							cin.clear();
							cin.ignore();
							cin >> choice;
						}
					}
				}
				else { //TODO wyswielic najkrotsze polaczeie }
			}
		}
		case 7:
			cout << "Exiting ..." << endl;
			system("pause");
			exit(1);
		}
	}

	Airport_list->print();
	Flight_list->print();

	std::system("pause");
}