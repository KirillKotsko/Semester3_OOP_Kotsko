#include "Header.h"
#include "unit_test_framework.h"

using namespace std;

int main() {
	Time_managment a;
	a.set_date({ 28,1,2003, 21,2,25 }, 1);
	a.set_date({ 11,11,2011, 11,11,11 }, 2);
	a.show_difference();
	a.show_date(1);
	a.show_date(2);
	a.day_of_the_week();
	return 0;
}