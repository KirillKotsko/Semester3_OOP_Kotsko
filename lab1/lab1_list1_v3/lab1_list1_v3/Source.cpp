#include "containers.h"
#include "unit_test_framework.h"
#include "test.h"
#include "demonstration.h" 
#include <iostream>

using namespace std;

int main() {
	TestRunner tr;
	RUN_TEST(tr, TestStack);
	RUN_TEST(tr, TestQueue);
	RUN_TEST(tr, TestDeque);
	system("pause");
	demonstration_stack();
	demonstraation_queue(); 
	demonstration_deque();
	return 0;
}