#include "lib/print_ip.h"

#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <tuple>

using namespace std;

int main()
{
	char myChar(-1);
	short meShort(0);
	int myInt(2130706433);
	long long myLong(8875824491850138409);
	string myString("string");
	vector<int> myVector = { 0, 1, 2, 3 };
	list<int> myList = { 4, 5, 6, 7 };
	tuple<int, int, int, int> myTuple = { 8, 9, 10, 11 };

	print_ip(myChar);
	print_ip(meShort);
	print_ip(myInt);
	print_ip(myLong);
	print_ip(myString);
	print_ip(myVector);
	print_ip(myList);
	print_ip(myTuple);

	return 0;
}
