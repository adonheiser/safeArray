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

// class to test safeArray class
class testSafeArray
{
public:
	void run();
};

// test program
void testSafeArray::run()
{
	// test initalizer list, use at()
	cout << "test initalizer :\n";
	int x =5;
	int n[] = {1,2,77,4,5};
	safeArray sa(x, n);
	cout << "size is " << sa.size() << endl;
	for (int i = 0 ; i < sa.size(); i++ )
		cout <<  sa.at(i) << "  ";

	// add 10
	cout << "\n\ntest add 10:\n";
	sa.addItems(10);
	cout << "size is " << sa.size() << endl;
	for (int i1 = 0 ; i1 < sa.size(); i1++ )
		cout << sa.at(i1);

	cout << "\n\ntest add() out of range";
	cout << "\nsize is " << sa.size() << endl;
	for (int q = 0 ; q < sa.size()+5; q++ )
	{
		cout << "(" << q << "),";
		try
		{
			int a = sa.at(q);
		}
		catch (const out_of_range& e)
		{
			cout << "OAR " << q << "|";
		}
	}

	// test put
	cout << "\n\ntest put() out of range";
	cout << "\nsize is " << sa.size() << endl;
	for (int p = 0 ; p < sa.size() + 5; p++ )
	{
		cout << "(" << p *2 << ", " << p << "),";
		try {
			sa.put(p * 2, p);;
		}
		catch (out_of_range& e) {
			cout << "AOR " << p << " ";
		}
	}
	cout << endl;
	for (int p1 = 0 ; p1 < sa.size(); p1++ )
		cout <<  sa.at(p1) << "  ";

	// test empty
	cout << "\n\ntest empty()";
	sa.empty();
	cout << "\nsize is " << sa.size() << endl;
	try {
	sa.put(0,0);
	} catch (out_of_range& e) {
		cout << "[0] is out of range\n";
	}

	sa.addItems(20);
	cout << "\nsize is " << sa.size() << endl;
	for (int e = 0 ; e < sa.size(); e++ )
	{
		sa.put(e,e);
		cout << sa.at(e) << " - ";
	}

	// test remove 5 items
	cout << "\nremoving 5 one parameter\n";
	sa.removeItems(5);
	cout << "size is " << sa.size() << endl;
	for (int e1 = 0 ; e1 < sa.size(); e1++ )
		cout << sa.at(e1) << " - ";

	cout << "\n\nremoving 5 two parameter\n";
	sa.removeItems(5,5);
	cout << "size is " << sa.size() << endl;
	for (int e2 = 0 ; e2 < sa.size(); e2++ )
		cout << sa.at(e2) << " - ";
	cout << endl;

	cout << "test copy constructor\n";
	safeArray newSa(sa);
	for (int e3 = 0 ; e3 < newSa.size(); e3++ )
		cout << newSa.at(e3) << " - ";
}

int main()
{
	testSafeArray testing;
	testing.run();
}
