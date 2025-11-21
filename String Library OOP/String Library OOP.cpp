#include <iostream>
#include "clsString.h"

using namespace std;

int main()
{
	clsString String1("Hello World");

	String1.CabitalAllLetter();
	cout << String1.Value << endl;

    String1.LowerFirstLetter();
	cout << String1.Value << endl;

	String1.LowerAllLetter();
	cout << String1.Value << endl;

	String1.InvertAllLeterCase();
	cout << String1.Value << endl;

}
