#pragma once

// FIXME not implemented yet

// Sprawdzajka czy dzia�amy na zmiennej lub obiekcie czy wska�niku na takowy
// Wykorzystane przy drukowaniu na ekran element�w listy
//template<typename T>
//struct is_Pointer
//{
//	static const bool value = false;
//};
//
//template<typename T>
//struct is_Pointer<T*>
//{
//	static const bool value = true;
//};
//
//template<typename T>
//bool isPointer(T arg)
//{
//	return is_Pointer<T>::value;
//}

// Deklaracja istnienia List
template<typename T> class List;

// Pojedynczy element listy (szablon spowodowany potrzeb� wska�nika na nast�pny element listy)
template<typename T> class ListNode {
private:
	friend int main();

	T data;
	ListNode* nextNode;
public:
	friend class List<T>;
	T getData();
	ListNode(T);
};

// Konstruktor elementu listy
template<typename T> ListNode<T>::ListNode(T data) {
	this->data = data;
	nextNode = nullptr;
}

// Getter :P
template<typename T> T ListNode<T>::getData() { return data; }

// Definicja szablonu listy - w razie potrzeby do rozbudowania
template<typename T> class List {
private:
	friend int main();
	void delete_element(ListNode<T>* elem);
	List<Flight*>* copyt_list_of_type();
	ListNode<T>* head;
	ListNode<T>* tail;
	void insertBefore(T);
	void insertBehind(T);
	List<T>* sort_by_airport_name(List<T>* L);
	void _print(true_type);
	void _print(false_type);

public:
	// check for head to see if list is empty
	bool isEmpty() {
		return head == nullptr;
	};

	void addElement(T);
	T* findElement(T);
	T popFirst();
	void print();
	List();
	~List();
};

// Wstawianie elementu na pocz�tek listy
template<typename T> void List<T>::insertBefore(T data)
{
	if (isEmpty())
		head = tail = new ListNode<T>(data);

	else {
		ListNode<T>* newptr = new ListNode<T>(data);
		newptr->nextNode = head;
		head = newptr;
	}
}

// Wstawianie elementu na ko�cu listy
template<typename T> void List<T>::insertBehind(T data) {
	if (isEmpty()) head = tail = new ListNode<T>(data);

	else {
		tail->nextNode = new ListNode<T>(data);
		tail = tail->nextNode;
	}
}

// Dodawanie elementu w odpowiadaj�cym mu miejscu (sortowane rosn�co)

template<typename T> void List<T>::addElement(T data) {
	if (isEmpty())
		head = tail = new ListNode<T>(data);

	else {
		if (data < head->data)
			insertBefore(data);

		else if (data >= tail->data)
			insertBehind(data);
		else {
			ListNode<T>* pointer = head;

			while (pointer != tail) {
				if (data >= pointer->data && data < pointer->nextNode->data) {
					ListNode<T>* temp = pointer->nextNode;
					pointer->nextNode = new ListNode<T>(data);
					pointer->nextNode->nextNode = temp;
					break;
				}
				pointer = pointer->nextNode;
			}
		}
	}
}

// Sprawdzenie czy podany element znajduje si� na li�cie
template<typename T> T* List<T>::findElement(T element) {
	ListNode<T>* pointer = head;
	while (pointer) {
		if (pointer->data == element) return &pointer->data;
		pointer = pointer->nextNode;
	}
	return NULL;
}

// Usuni�cie pierwszego elementu z listy i zwr�cenie go
template<typename T> T List<T>::popFirst() {
	ListNode<T> value = *head;
	ListNode<T>* del = head;

	if (head == tail)
		head = tail = nullptr;

	else
		head = head->nextNode;

	delete del;
	return value.getData();
}

// Wydrukowanie zawarto�ci listy
template<typename T> void List<T>::print() {
	_print(std::is_pointer<T>());
}

template<typename T> void List<T>::_print(std::true_type) {
	if (isEmpty())
		cout << "List empty" << endl;

	else {
		ListNode<T>* pointer = head;
		cout << "List: \n";

		while (pointer) {
			cout << pointer->data->ToString() << endl;
			pointer = pointer->nextNode;
		}
		cout << endl;
	}
}

template<typename T> void List<T>::_print(std::false_type) {
	if (isEmpty())
		cout << "List empty" << endl;
	else {
		ListNode<T>* pointer = head;
		cout << "List: \n";

		while (pointer) {
			cout << pointer->data.ToString() << endl;
			pointer = pointer->nextNode;
		}
		cout << endl;
	}
}

// Konstruktor domy�lny listy
template<typename T>
List<T>::List() { head = tail = nullptr; }

// Destruktor listy
template<typename T> List<T>::~List() {
	if (!isEmpty()) {
		ListNode<T> *pointer = head;
		ListNode<T> *del;
		while (pointer) {
			del = pointer;
			pointer = pointer->nextNode;
			delete del;
		}
	}
}

template<typename T>
List<T>* List<T>::sort_by_airport_name(List<T>* L) {
	if (L == NULL) {
		cout << "There are no flights of the sort you're looking for. Add some and try again..." << endl;
		return NULL;
	}
	ListNode<Flight*>* pointer = L->head;
	if (pointer->nextNode == NULL) {
		cout << pointer->data->ToString() << endl;;
		return NULL;
	}
	while (!isEmpty()) {
		pointer = L->head;
		ListNode<Flight*>* search_pointer = L->head;
		while (search_pointer) {
			//pionter stays at the minumum value, search_pointer is gonna go through the list
			if (pointer->getData()->getDeparture().getName().compare(search_pointer->getData()->getDeparture().getName()) > 0) {
				pointer = search_pointer;
			}
			search_pointer = search_pointer->nextNode;
		}
		cout << pointer->data->ToString() << endl;
		delete_element(pointer);
	}
}

template<typename T> void List<T>::delete_element(ListNode<T>* elem) {
	ListNode<T>* del = head;
	if ((elem == head && (elem->getData()->getDeparture().getName().compare(head->getData()->getDeparture().getName())) == 0)
		&& (elem->getData()->getDeparture().getCountry().compare(head->getData()->getDeparture().getCountry()) == 0)) {
		del = elem;
		head = head->nextNode;
		delete del;
	}
	else if ((elem == tail && (elem->getData()->getDeparture().getName().compare(tail->getData()->getDeparture().getName())) == 0)
		&& (elem->getData()->getDeparture().getCountry().compare(tail->getData()->getDeparture().getCountry()) == 0)) {
		del = tail;
		tail = head;
		while (tail->nextNode != del)
			tail = tail->nextNode;
		delete del;
		tail->nextNode = NULL;
	}
	else {
		ListNode<T>* del2 = elem;
		del = head;
		while (del->nextNode != del2)
			del = del->nextNode;
		del->nextNode = del2->nextNode;
		delete del2;
	}
}
template<typename T>
List<Flight*>* List<T>::copyt_list_of_type() {
	int choice = -1;
	cout << "Would you like to view [1] passenger or [2]cargo flights?" << endl;
	cin.clear();
	cin.ignore();
	cin >> choice;
	system("cls");
	List<Flight*>* COPIED_Flight_list = new List<Flight*>();
	ListNode<Flight*>* pointer = head;
	if (choice == 1) {
		cout << "LIST OF PASSENGER FLIGHTS" << endl << "Sorted by departure airport" << endl << endl;
		while (pointer) {
			if (pointer->data->getFlight_type() == 'P') {
				Passenger_flight* pointer2 = (Passenger_flight*)pointer->data;
				Passenger_flight dummy(*pointer2);
				pointer->data->getId() == -1 ? NULL : COPIED_Flight_list->addElement(new Passenger_flight(dummy));
			}
			pointer = pointer->nextNode;
		}
		return COPIED_Flight_list;
	}
	else if (choice == 2) {
		cout << "LIST OF CARGO FLIGHTS" << endl << "Sorted by departure airport" << endl << endl;

		while (pointer) {
			if (pointer->data->getFlight_type() == 'C') {
				Cargo_flight* pointer2 = (Cargo_flight*)pointer->data;
				Cargo_flight dummy(*pointer2);
				pointer->data->getId() == -1 ? NULL : COPIED_Flight_list->addElement(new Cargo_flight(dummy));
			}
			pointer = pointer->nextNode;
		}
		return COPIED_Flight_list;
	}
	else {
		while (choice != 2 && choice != 1) {
			cout << "Wrong input. Try again" << endl;
			cout << "Would you like to view [1] passenger or [2]cargo flights?" << endl;
			cin.clear();
			cin.ignore();
			cin >> choice;
		}
	}
}
