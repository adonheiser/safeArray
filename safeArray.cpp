// safe array implements vector sytle dynamic array

#include <iostream>
#include <string>
#include <stdexcept>
#include <string.h>
#include "safeArray.h"

using namespace std;

safeArray::safeArray() // default
{
	this->len = 0;
	this->data = new int[len];
}

safeArray::safeArray(const safeArray& arr)	// copy
{
	cout << "copy constructor\n";
	this->len = arr.len;
	this->data = new int[len];
	for (int i = 0 ; i < this->size(); i++ )
		this->data[i] = arr.data[i];
}

safeArray::safeArray(int n) :len(n) // default
{
	this->data = new int[this->size()];
}

// Initialization list constructor
safeArray::safeArray(int x, int *n) : len(x), data(n)
{
	int* temp = new int[len];
	for (int i = 0 ; i < this->size(); i++ )
	{
		cout << data[i] << " ";
		temp[i] = this->data[i];
	}
	this->data = temp;
}

// destructor
safeArray::~safeArray()
{
	cout <<"\ndestroy\n";
	delete[] this->data;
}

// return int at
int safeArray::safeArray::at(int i)
{
	if (i > this->size()-1)
	{
		throw out_of_range("out of range "+ this->size());
	}
	return data[i];
}

// put int at pos
void safeArray::safeArray::put(int i,int pos)
{
	if (pos > this->size()-1)
	{
		throw out_of_range("out of range "+ this->size());
	}
	this-> data[pos] = i;
}

// get rid of everything
void safeArray::empty()
{
	delete[] this->data;
	this->len = 0;
	this->data = new int[len];
}

// add
void safeArray::addItems(int howmany)
{
	int newSize = len + howmany;
	int* newData = new int[newSize];
	for (int i = 0 ; i < this->size() ;i++)
	{
		newData[i] = this->data[i];
	}
	this->len = newSize;
	delete[] this->data;
	this->data = newData;
}

// remove from tail
void safeArray::removeItems(int howmany)
{
	int newSize = this->size() - howmany;
	if (newSize < 0)
	{
		throw out_of_range("out of range "+ this->size());
	}

	int* newData = new int[newSize]; // array

	for (int i = 0; i < newSize; i++)
	{
		newData[i] = this->data[i];
	}
	delete[] this->data;
	this->len = newSize;
	this->data = newData;
}


// remove from pos
void safeArray::removeItems(int howmany, int start)
{
	int count = 0;
	int newSize = this->size() - howmany;
	if (newSize < 0)
	{
		throw out_of_range("out of range "+ this->size());
	}
	int* newData = new int[newSize];

	for (int i = 0; i < size(); i++)
	{
		if (i >= start && i < start + howmany)
		{
			continue;
		}
		newData[count] = this->data[i];
		count++;
	}
	delete[] this->data;
	this->len = newSize;
	this->data = newData;
}


// get size of data
int safeArray::size()
{
	return this->len;
}
