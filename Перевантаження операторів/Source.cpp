#include <iostream>
#include "Time.h"
using namespace std;

int main() {

	Time p1(4,35,53);
	p1.ShowTime();
	Time p2(8,11,57);
	p2.ShowTime();

	

	Time p3=p2/p1;
	p3.ShowTime();

	

	system("pause");
	return 0;
}