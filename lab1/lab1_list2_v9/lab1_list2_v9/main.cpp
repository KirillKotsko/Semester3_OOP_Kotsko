#include "date.h"
#include "unit_test_framework.h"
#include "test.h"
#include "demonstration.h"

using namespace std;

int main() {
	TestRunner tr;
	RUN_TEST(tr, TestDateMinusDate);
	RUN_TEST(tr, TestDateAddDifference);
	RUN_TEST(tr, TestDateMinusDifference);
	RUN_TEST(tr, TestWeekDay);
	RUN_TEST(tr, TestWeekInMonth);
	RUN_TEST(tr, TestWeekInYear);
	RUN_TEST(tr, TestTimeManagmentInContainers);
	system("pause");

	return 0;
}