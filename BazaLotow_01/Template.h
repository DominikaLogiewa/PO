#pragma once

// FIXME not implemented yet

// Sprawdzajka czy dziaï¿½amy na zmiennej lub obiekcie czy wskaï¿½niku na takowy
// Wykorzystane przy drukowaniu na ekran elementï¿½w listy
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

// Pojedynczy element listy (szablon spowodowany potrzebï¿½ wskaï¿½nika na nastï¿½pny element listy)
template<typename T> class ListNode
{
private:
	friend int main();

	T data;
	ListNode* nextNode;
public:
//	friend  void List<T>::delete_element(ListNode<T>* elem);
	friend class List<T>;
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
    ListNode<T>* head;
    ListNode<T>* tail;
    void insertBefore(T);
    void insertBehind(T);
	List<T>* sort_by_airport_name(List<T>* L);
	void delete_element(ListNode<T>* elem);
    void _print(true_type);
    void _print(false_type);

public:
    void copy_list(List<T>* obj);
    // check for head to see if list is empty
    bool isEmpty()
    {
        return head == nullptr;
    };

    void addElement(T);
    T* findElement(T);
    T popFirst();
    void print();
    List();
    ~List();
};

// Wstawianie elementu na poczï¿½tek listy
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

// Wstawianie elementu na koï¿½cu listy
template<typename T> void List<T>::insertBehind(T data)
{
	if (isEmpty()) head = tail = new ListNode<T>(data);

	else
	{
		tail->nextNode = new ListNode<T>(data);
		tail = tail->nextNode;
	}
}


// Dodawanie elementu w odpowiadajï¿½cym mu miejscu (sortowane rosnï¿½co)

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

// Sprawdzenie czy podany element znajduje siï¿½ na liï¿½cie
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
//////////////////////////////////////////////////////////////////////////////////////////////////////
// Usuniï¿½cie pierwszego elementu z listy i zwrï¿½cenie go
template<typename T> T List<T>::popFirst()
{
	ListNode<T> value = *head;
	ListNode<T>* del = head;

	if (head == tail)
        head = tail = nullptr;

	else
        head = head->nextNode;

	delete del;
	return value.getData();
}

// Wydrukowanie zawartoï¿½ci listy
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


// Konstruktor domyœlny listy
template<typename T>
List<T>::List() { head = tail = nullptr; }


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



template<typename T>
 void List<T>::delete_element(ListNode<T>* elem)
{
	 ListNode<T>* del = head;
	if (elem == head && (elem->getData()->getDeparture().name.compare(head>getData()->getDeparture().name)==0)
		&& (elem->getData()->getDeparture().country.compare(head>getData()->getDeparture().country) == 0))
	{
		popFirst();
		return ;
	}
	else if (elem == tail && (elem->getData()->getDeparture().name.compare(head > getData()->getDeparture().name) == 0)
		&& (elem->getData()->getDeparture().country.compare(head-> getData()->getDeparture().country) == 0))
	{
	
		del = tail;
		tail = head;
		while (tail->nextNode)
		{
			tail = tail->nextNode;
		}
		delete del;
	}
}

template<typename T>
List<T>* List<T>:: sort_by_airport_name(List<T>* L)
{
	if (L == NULL)
	{
		cout << "There are no flights of the sort you're looking for. Add some and try again..." << endl;
		return NULL;
	}
	ListNode<Flight*>* pointer = L->head;
	if (pointer->nextNode == NULL)
	{
		cout << pointer->data->ToString();
		return NULL;
	}
	ListNode<Flight*>* search_pointer = L->head;
	while (search_pointer)
	{
		//pionter stays at the minumum value, search_pointer is gonna go through the list
		if (pointer->getData()->getDeparture().getName().compare(search_pointer->getData()->getDeparture().getName()) > 0)
		{
			pointer = search_pointer;
		}
		search_pointer = search_pointer->nextNode;
	}
	cout << pointer->data->ToString() << endl;
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

