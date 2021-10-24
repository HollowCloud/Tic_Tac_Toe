#include <iostream>
#include "Person.h"
using namespace std;
int main()
{
    Person o;
	cout << o;
	o.define_turn();
	o.exit();
	return 0;
}
