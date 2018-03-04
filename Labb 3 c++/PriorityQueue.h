#ifndef PRIORITYQUEUE_H
#define PRIORITYQUEUE_H
#include "IPriorityQueue.h"
template <typename T>
class PriorityQueue: public IPriorityQueue<T>
{
private:
	T* queue;
	int *priorityIndex;
	int capacity;
	int nrOfItems;
	int capacityIncrement;
	void expand();
public:
	PriorityQueue(int capacity = 5, int capacityIncrement = 5);
	PriorityQueue(const PriorityQueue& origobj);
	PriorityQueue& operator=(const PriorityQueue<T>& origobj);
	virtual ~PriorityQueue();
	void enqueue(const T& element);
	T dequeue()throw(...);
	T front() const throw(...);
	bool isEmpty() const;
};
#endif

template<typename T>
void PriorityQueue<T>::expand()
{
	this->capacity += 5;
	T *temp = new T[this->capacity];
	for (int i = 0; i < this->nrOfItems; i++)
	{
		temp[i] = this->queue[i];
	}
	delete[] this->queue;
	this->queue = temp;
}


template<typename T>
PriorityQueue<T>::PriorityQueue(int capacity, int capacityIncrement)
{
	this->nrOfItems = 0;
	this->capacity = capacity;
	this->capacityIncrement = capacityIncrement;
	this->queue = new T[this->capacity];
	this->priorityIndex = new int[this->capacity];
	for (int i = 0; i < this->capacity; i++) {
		this->priorityIndex[i] = 0;
	}
}

template<typename T>
PriorityQueue<T>::PriorityQueue(const PriorityQueue & origObj)
{
	this->nrOfItems = origObj.nrOfItems;
	this->capacity = origObj.capacity;
	this->capacityIncrement = origObj.capacityIncrement;
	this->queue = new T[this->capacity];
	this->priorityIndex = new int[this->capacity];
	for (int i = 0; i < this->nrOfItems; i++) {
		this->queue[i] = origObj.queue[i];
		this->priorityIndex[i] = origObj.priorityIndex[i];
	}
}

template<typename T>
PriorityQueue<T> & PriorityQueue<T>::operator=(const PriorityQueue<T>& origObj)
{
	this->nrOfItems = origObj.nrOfItems;
	this->capacity = origObj.capacity;
	this->capacityIncrement = origObj.capacityIncrement;
	for (int i = 0; i < this->nrOfItems; i++) {
		this->queue[i] = origObj.queue[i];
		this->priorityIndex[i] = origObj.priorityIndex[i];
	}
	return *this;
}

template<typename T>
PriorityQueue<T>::~PriorityQueue()
{
	delete[] queue;
	delete[] priorityIndex;
}

template<typename T>
void PriorityQueue<T>::enqueue(const T & element)
{
	if (this->nrOfItems == this->capacity)
	{
		expand();
	}
	this->queue[this->nrOfItems] = element;
	this->priorityIndex[this->nrOfItems] = this->nrOfItems;
	this->nrOfItems++;
}

template<typename T>
T PriorityQueue<T>::dequeue() throw(...)
{
	if (this->nrOfItems == 0)
	{
		std::string test = "Error. No more items.";
		throw test;
	}
	int highestPriority = this->priorityIndex[0];
	T returnItem = queue[highestPriority];
	queue[highestPriority] = queue[this->nrOfItems];
	this->priorityIndex[this->nrOfItems] = highestPriority;
	for (int i = 0; i < this->nrOfItems; i++) {
		this->priorityIndex[i] = this->priorityIndex[i + 1];
	}
	this->nrOfItems--;

	return returnItem;
}

template<typename T>
T PriorityQueue<T>::front() const throw(...)
{
	if (this->nrOfItems == 0)
	{
		std::string test = "Error. No more items.";
		throw test;
	}
	int highestPriority = this->priorityIndex[0];
	T returnItem = queue[highestPriority];
	return returnItem;
}

template<typename T>
bool PriorityQueue<T>::isEmpty() const
{
	if (this->nrOfItems == 0) {
		return true;
	}
	else {
		return false;
	}
}
