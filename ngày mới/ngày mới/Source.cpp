#include "hauto.h"
#include "tinhhauto.h"
#include "hautologic.h"

#include "Struct.h"
#include <string>

int main()
{
	string Str = Hauto("(12+24)*3+15");
	cout << Str << endl;
	cout << calculate("1 2 + 3 * 15 + ")<<endl;
	cout << Hautologic("(a and not b) or c");
	return 0;
}