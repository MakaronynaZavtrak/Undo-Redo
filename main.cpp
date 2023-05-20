#include <string>
#include <iostream>
#include <math.h>
#include "Class.h"
using namespace std;
int main()
{
	setlocale(LC_ALL, "RUS");
	cout << "Please, input string" << endl;
	Operations Text;
	cout << "What do you want to do with string?" << endl;
	bool isFinish = false;
	while (isFinish != true) {
		string command;
		cin >> command;
		if (command == "delete_begin") {
			cout << "input amount of char you want to delete" << endl;
			int amount;
			cin >> amount;
			string newStr = Text.deleteBegin(amount);
			cout << "You've got this string: " << newStr << endl;
		}
		else if (command == "delete_end") {
			cout << "input amount of char you want to delete" << endl;
			int amount;
			cin >> amount;
			string newStr = Text.deleteEnd(amount);
			cout << "You've got this string: " << newStr << endl;
		}
		else if (command == "add_begin") {
			cout << "input string you want to add" << endl;
			string addStr;;
			cin >> addStr;
			Text.addBegin(addStr);
			cout << "You've got this string: " << Text.some_Str << endl;
		}
		else if (command == "add_end") {
			cout << "input string you want to add" << endl;
			string addStr;;
			cin >> addStr;
			Text.addEnd(addStr);
			cout << "You've got this string: " << Text.some_Str << endl;
		}
		else if (command == "undo") {
			Text.undo();
			cout << "Undo has done: " << Text.some_Str << endl;
		}
		else if (command == "redo") {
			Text.redo();
			cout << "Redo has done :" << Text.some_Str << endl;
		}
		else if (command == "quit") {
			isFinish = true;
		}
		else
			cout << "operation is not found" << endl;
	};
}
