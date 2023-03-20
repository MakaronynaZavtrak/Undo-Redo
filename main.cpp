#include <string>
#include <iostream>
#include <math.h>
using namespace std;

int main()
{
	setlocale(LC_ALL, "RUS");
	class Operations {
	public:
		string some_Str;//основная строка
		int countUndo = 0;
		int countRedo = 0;
		int amountReDoConditions = 0;//размер массива состояний для Redo
		int amountConditions = 0;//размер массива состояния для Undo
		string* conditions = new string[50];
		string* ReDoconditions = new string[50];
		Operations(string input_String) {
			this->some_Str = input_String;
		};

		string* deleteLastElement(string arr[], int countElements) {
			string* upbdatedArr = new string[50];
			for (int i = 0; i < countElements; i++) {
					upbdatedArr[i] = arr[i];
				};
			delete[] arr;
			return upbdatedArr;
		};

		void Add(string additive_value) {
			conditions[amountConditions] = some_Str;
			amountConditions++;
			countUndo++;
			some_Str += additive_value;
		};

		string Delete(int amount_char_of_delete) {
			conditions[amountConditions] = some_Str;
			amountConditions++;
			countUndo++;
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
				//ReDoconditions[amountReDoConditions - 1] = conditions[sizeof(conditions) / sizeof(conditions[0])];//состояние, которое "откатили", заносим в массив состояний для ReDo
				ReDoconditions[amountReDoConditions] = some_Str;
				amountReDoConditions++;
				countRedo++;
				some_Str = conditions[amountConditions-1];//из массива состояний возвращаем последнее из них			
				conditions = deleteLastElement(conditions, countUndo);
				countUndo--;
				amountConditions--;
			};
		};



		void redo() {
			some_Str = ReDoconditions[amountReDoConditions-1];
			conditions[amountConditions] = ReDoconditions[(sizeof(ReDoconditions) / sizeof(ReDoconditions[0]))];
			amountConditions++;
			ReDoconditions = deleteLastElement(ReDoconditions, countRedo);
			countRedo--;
			amountReDoConditions--;
		};

	};

	Operations Text("Hello, world");
	cout << Text.some_Str << endl;

	Text.Add("Bababui");
	cout << Text.some_Str << endl;

	Text.some_Str = Text.Delete(2);
	cout << Text.some_Str << endl;

	Text.undo();
	cout << Text.some_Str << endl;

	Text.undo();
	cout << Text.some_Str << endl;

	Text.redo();
	cout << Text.some_Str << endl;

	Text.Add("dadadasdsad");
	cout << Text.some_Str << endl;

	Text.undo();
	cout << Text.some_Str << endl;

	Text.redo();
	cout << Text.some_Str << endl;
}
