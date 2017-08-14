#include "safeArray.h"
#include <iostream>

using namespace std;
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
