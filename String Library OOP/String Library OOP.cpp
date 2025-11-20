#include <iostream>
#include "clsString.h"

using namespace std;

int main()
{
	clsString String1("Hello World");

	cout << String1.CabitalAllLetter() << endl;
	cout << String1.LowerFirstLetter() << endl;
	cout << String1.LowerAllLetter() << endl;
	cout << String1.InvertAllString() << endl;
}
