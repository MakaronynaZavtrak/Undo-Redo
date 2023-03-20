#include <string>
#include <stack>
#include <iostream>
using namespace std;

int main()
{
	setlocale(LC_ALL, "RUS");
	class Operations {
	public:
		string some_Str;//основная строка
		int amountReDoConditions = 0;//размер массива состояний для Redo
		int amountConditions = 0;//размер массива состояния для Undo
		Operations(string input_String) {
			this->some_Str = input_String;
		};

		string* deleteLastElement(string arr[]) {
			int j = 0;
			string* upbdatedArr = new string[];
			for (int i = 0; i < (sizeof(arr) / sizeof(arr[0])) - 1; i++) {
				upbdatedArr[j] = arr[i];
				j++;
			};
			return upbdatedArr;
		};

		void Add(string additive_value) {
			conditions[amountConditions] = some_Str;
			amountConditions++;
			some_Str += additive_value;
		};

		string Delete(int amount_char_of_delete) {
			conditions[amountConditions] = some_Str;
			amountConditions++;
			string modifiedStr;
			for (int i = 0; i < ((some_Str.length() - amount_char_of_delete)); i++) {
				modifiedStr += some_Str[i];
			};
			return modifiedStr;
		};

		void undo() {
			if (sizeof(conditions) == 0) {
				cout << "Строка ещё пока никак не изменялась!" << endl;
			}
			else {
				some_Str = conditions[(sizeof(conditions)/sizeof(conditions[0]))-1];//из массива состояний возвращаем последнее из них
				ReDoconditions[amountReDoConditions] = conditions[(sizeof(conditions) / sizeof(conditions[0]) - 1)];//состояние, которое "откатили", заносим в массив состояний для ReDo
				amountReDoConditions++;
				deleteLastElement(conditions);
			};
		};

	

		void redo() {
			some_Str = ReDoconditions[(sizeof(ReDoconditions) / sizeof(ReDoconditions[0])) - 1];
			conditions[amountConditions] = ReDoconditions[(sizeof(ReDoconditions) / sizeof(ReDoconditions[0])) - 1];
			amountConditions++;
			deleteLastElement(ReDoconditions);
		};
	private:
		string* conditions = new string[];
		string* ReDoconditions = new string[];
	};

	Operations text("Hello, world");
	text.Add("Bababui");
	cout << text.some_Str << endl;
}
