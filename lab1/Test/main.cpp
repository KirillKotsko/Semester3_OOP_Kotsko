#include "../Test/Test.h"

using namespace std;

int main() {
	TestRunner tr;
	RUN_TEST(tr, TestStack);
	RUN_TEST(tr, TestQueue);
	RUN_TEST(tr, TestDeque);
	RUN_TEST(tr, TestDateWithTimeMinusDateWithTime);
	RUN_TEST(tr, TestDateWithTimeAddDifference);
	RUN_TEST(tr, TestDateWithTimeMinusDifference);
	RUN_TEST(tr, TestWeekDay);
	RUN_TEST(tr, TestWeekInMonth);
	RUN_TEST(tr, TestWeekInYear);
	RUN_TEST(tr, TestTimeManagmentInContainers);
	return 0;
}
