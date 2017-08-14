#ifndef SAFEARRAY_H
#define SAFEARRAY_H

class safeArray
{
public:

	safeArray();				 	// default constructor
	safeArray(const safeArray&); 	// copy constructor
	safeArray(int);			 		// parmeterized
	safeArray(int, int*);			// parmeterized
	~safeArray();					// destructor
	int at(int);					// get int at pos
	void put(int, int);				// put int at pos
	void empty();					//
	void addItems(int);				// add len
	void removeItems(int);			// remove len from tail
	void removeItems(int, int);		// remove len from pos
	int size();

private:
	int *data;		// ints
	int len;		// size
};

#endif
