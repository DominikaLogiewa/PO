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
template<typename T> class ListNode
{
private:
	friend class List<T>;
	friend int main();
	friend List <Flight* >* sort_FLIGHTS_by_airport(List<Flight>* FlightList);

	T data;
	ListNode* nextNode;
public:
	T getData();
	ListNode(T);
};

// Konstruktor elementu listy
template<typename T> ListNode<T>::ListNode(T data)
{
	this->data = data;
	nextNode = nullptr;
}

// Getter :P
template<typename T> T ListNode<T>::getData() { return data; }

// Definicja szablonu listy - w razie potrzeby do rozbudowania
template<typename T> class List {

private:
	friend int main();
	friend List <Flight* > sort_FLIGHTS_by_airport(List<Flight*> FlightList);
	ListNode<T>* head;
	ListNode<T>* tail;
	void insertBefore(T);
	void insertBehind(T);
	void copy_sort_by_airport_name(List<T>* L);
	void _print(true_type);
	void _print(false_type);

public:
	void copy_list(List<T>* obj);

    // check for head to see if list is empty
	bool isEmpty()
	{
		if (head == nullptr)
            return 1;

		else return 0;
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

	else
	{
		ListNode<T>* newptr = new ListNode<T>(data);
		newptr->nextNode = head;
		head = newptr;
	}
}

// Wstawianie elementu na ko�cu listy
template<typename T> void List<T>::insertBehind(T data)
{
	if (isEmpty()) head = tail = new ListNode<T>(data);

	else
	{
		tail->nextNode = new ListNode<T>(data);
		tail = tail->nextNode;
	}
}


// Dodawanie elementu w odpowiadaj�cym mu miejscu (sortowane rosn�co)

template<typename T> void List<T>::addElement(T data)
{
	if (isEmpty())
        head = tail = new ListNode<T>(data);

	else
	{
		if (data < head->data)
            insertBefore(data);

		else if (data >= tail->data)
            insertBehind(data);

		else
		{
			ListNode<T>* pointer = head;

			while (pointer != tail)
			{
				if (data >= pointer->data && data < pointer->nextNode->data)
				{
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
template<typename T> T* List<T>::findElement(T element)
{
	ListNode<T>* pointer = head;
	while (pointer)
	{
		if (pointer->data == element) return &pointer->data;
		pointer = pointer->nextNode;
	}
	return NULL;
}

// Usuni�cie pierwszego elementu z listy i zwr�cenie go
template<typename T> T List<T>::popFirst()
{
	ListNode<T> value = *head;
	ListNode<T>* del = head;
	if (head == tail) head = tail = nullptr;
	else head = head->nextNode;
	delete del;
	return value.getData();
}

// Wydrukowanie zawarto�ci listy
template<typename T> void List<T>::print()
{
	_print(std::is_pointer<T>());
}

template<typename T> void List<T>::_print(std::true_type)
{
	if (isEmpty())
        cout << "List empty" << endl;

	else
	{
		ListNode<T>* pointer = head;
		cout << "List: \n";
		while (pointer)
		{
			cout << pointer->data->ToString() << endl;
			pointer = pointer->nextNode;
		}
		cout << endl;
	}
}

template<typename T> void List<T>::_print(std::false_type)
{
	if (isEmpty())
        cout << "List empty" << endl;

	else
	{
		ListNode<T>* pointer = head;
		cout << "List: \n";
		while (pointer)
		{
			cout << pointer->data.ToString() << endl;
			pointer = pointer->nextNode;
		}
		cout << endl;
	}
}

// Konstruktor domy�lny listy
template<typename T> List<T>::List()
{
	head = tail = nullptr;
}

// Destruktor listy
template<typename T> List<T>::~List()
{
	if (!isEmpty())
	{
		ListNode<T> *pointer = head;
		ListNode<T> *del;
		while (pointer)
		{
			del = pointer;
			pointer = pointer->nextNode;
			delete del;
		}
	}
}

// FIXME NOT IMPLEMENTED YET

//template <typename T>
//void List<T>::copy_list(List<T>* obj)
//{
//	ListNode<T>* pointer = obj->head;
//	while (pointer)
//	{
//		if (pointer->data->flight_type == 'P')
//		{
//			Passenger_flight dummy = Passenger_flight((Passenger_flight)pointer->data);
////			dummy.setDeparture(AirportList->findElement(dep));
////			dummy.setDestination(AirportList->findElement(dest));
//			dummy.id == -1 ? NULL : value->addElement(new Passenger_flight(pointer->data));
//		}
//		else if (flightType == 'C')
//		{
//			Cargo_flight dummy = Cargo_flight(pointer->data);
////			dummy.setDeparture(AirportList->findElement(dep));
////			dummy.setDestination(AirportList->findElement(dest));
//			dummy.id == -1 ? NULL : value->addElement(new Cargo_flight(pointer->data));
//		}
//		pointer = pointer->nextNode;
//	}
//	return value;
//}