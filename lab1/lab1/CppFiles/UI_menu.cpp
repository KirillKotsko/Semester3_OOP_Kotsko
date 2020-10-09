#include "../HeaderFiles/Demonstration/Demonstration.h"

using namespace std;

int UI::main_menu()
{
	int key = 0;
	int code;
	do {
		system("cls");
		cout << "############################################################" << endl;
		cout << "#                          Menu                            #" << endl;
		cout << "############################################################" << endl;
		cout << endl;
		key = (key + 11) % 11;
		if (key == 0) cout << "-> Show dates" << endl;
		else  cout << "   Show dates" << endl;
		if (key == 1) cout << "-> Insert date1" << endl;
		else  cout << "   Insert date1" << endl;
		if (key == 2) cout << "-> Insert date2" << endl;
		else  cout << "   Insert date2" << endl;
		if (key == 3) cout << "-> Alternative date display" << endl;
		else  cout << "   Alternative date display" << endl;
		if (key == 4) cout << "-> Change of GMT" << endl;
		else  cout << "   Change of GMT" << endl;
		if (key == 5) cout << "-> Add and substract the difference of date1 and date2 to the dates" << endl;
		else  cout << "   Add and substract the difference of date1 and date2 to the dates" << endl;
		if (key == 6) cout << "-> Show day of week for each date" << endl;
		else  cout << "   Show day of week for each date" << endl;
		if (key == 7) cout << "-> Show week number in month and year for each date" << endl;
		else  cout << "   Show week number in month and year for each date" << endl;
		if (key == 8) cout << "-> Convert dates to Julian calendar" << endl;
		else  cout << "   Convert dates to Julian calendar" << endl;
		if (key == 9) cout << "-> Demontration mode with stack,queue,deque." << endl;
		else  cout << "   Demontration mode with stack,queue,deque." << endl;
		if (key == 10) cout << "-> Exit" << endl;
		else  cout << "   Exit" << endl;

		code = _getch();
		if (code == 224)
		{
			code = _getch();
			if (code == 80) key++;
			if (code == 72) key--;
		}
	} while (code != 13);
	system("cls");
	return key;
}

int UI::demonstration_choice_menu() {
	int key = 0;
	int code;
	do {
		system("cls");
		cout << "############################################################" << endl;
		cout << "#                 Show functionality using:                #" << endl;
		cout << "############################################################" << endl;
		cout << endl;
		key = (key + 5) % 5;
		if (key == 0) cout << "-> Int" << endl;
		else  cout << "   Int" << endl;
		if (key == 1) cout << "-> String" << endl;
		else  cout << "   String" << endl;
		if (key == 2) cout << "-> Vector<int>" << endl;
		else  cout << "   Vector<int>" << endl;
		if (key == 3) cout << "-> Custom class(Time_managment)" << endl;
		else  cout << "   Custom class(Time_managment)" << endl;
		if (key == 4) cout << "-> Back to main menu" << endl;
		else  cout << "   Back to main menu" << endl;

		code = _getch();
		if (code == 224)
		{
			code = _getch();
			if (code == 80) key++;
			if (code == 72) key--;
		}
	} while (code != 13);
	system("cls");
	return key;
}

int UI::variant_of_output_difference() {
	int key = 0;
	int code;
	do {
		system("cls");
		cout << "############################################################" << endl;
		cout << "#     Choose variant of output difference between date     #" << endl;
		cout << "############################################################" << endl;
		cout << endl;
		key = (key + 4) % 4;
		if (key == 0) cout << "-> Standart (in days)" << endl;
		else  cout << "   Standart (in days)" << endl;
		if (key == 1) cout << "-> In hours" << endl;
		else  cout << "   In hours" << endl;
		if (key == 2) cout << "-> In minutes" << endl;
		else  cout << "   In minutes" << endl;
		if (key == 3) cout << "-> In seconds" << endl;
		else  cout << "   In seconds" << endl;

		code = _getch();
		if (code == 224)
		{
			code = _getch();
			if (code == 80) key++;
			if (code == 72) key--;
		}
	} while (code != 13);
	system("cls");
	return key;
}