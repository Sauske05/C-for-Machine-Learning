#include <iostream>
#include <string>
#include <ctime>
#include <vector>
#include <array>
using namespace std;

static string ternary_operator() {
	int grade = 60;
	string message;
	grade >= 60 ? message = "Congratas!" : message = "Try Harder";
	return message;
}



static string if_statements() {
	int age;
	cout << "Enter your age: ";
	cin >> age;
	string message;
	if (age <= 18) {
		message = "Congrats on being less than or equal to 18 yo.";
	}
	else {
		message = "Damn you old!";
	}
	return message;

}

static void string_operations() {
	string name = "";
	// can use name.length() for the length attribute. Similar to len(name) for py.
	//to check if the name is empty or not
	string* name_pointer = &name;
	//We can also use the .append() function to append string at the end of our string.
	//name.at(index) to display the character at that index
	//name.insert(index, string)
	//name.find(string) --> for searching substring in a string
	
	//nam.erase(begin_index, end_index)
	if (name.empty()) {
		cout << "Name is Empty!" << endl;
		
	}
	else {
		cout << "Name not empty!";
		
	}

	cout << name_pointer << endl;
}

static void loops() {
	// while loop
	//bool is_valid = 0; // 0 means false and 1 means true
	//bool value;
	//while(!is_valid) {
	//	cout << "Enter True to end: ";
	//	cin >> value;
	//	if (value) {
	//		is_valid = true;
	//	}
	//	else {
	//		cout << "Try again!" << endl;
	//		cin.clear();
	//	}
	//
	//}

	// do while loop = do some block of code first then repeat again if the condition is true!
	// for loops:
	for (int i = 1; i < 10; i++) {
		if (i == 4) {
			continue;
		}
		if (i == 7) {
			break;
		}

		cout << i << endl;
	}
}

static void random_number_generator() {
	time_t timestamp = time(NULL);
	//cout << "Without using the address:" << ctime(timestamp) << endl;
	cout << "This is the time : " << ctime(&timestamp) << endl;
	srand(time(NULL));
	cout << time(NULL) << endl;
	int randNum = rand() % 101;
	cout << randNum << endl;
}


//global scope
int num = 3;
static void printNum() {
	int num = 1;
	//using the :: in variable indicates its reference to the global variable rather than local
	cout << ::num << endl;

}


static void arrays() {
	array<string, 3> test_array = { "Arun", "barun", "Carun"}; //STL Array Library
	string car[] = { "Toyota", "Honda"};
	cout << car[1] << endl;
	//sizeof() -> determines the size in bytes of a variable, data type, class, objects etc
	/*cout << sizeof(car) << endl;
	cout << sizeof(test_array) << endl;
	for (int i = 0; i < sizeof(test_array) / sizeof(string); i++) {
		cout << test_array[i] << endl;
	}

	for each(string var in test_array)
	{
		cout << var << endl;
	}*/


}

int main() {
	//if statements
	//string if_statement_message = if_statements();
	//cout << if_statement_message;
	//string_operations();
	//loops();
	//random_number_generator();
	//printNum();
	arrays();
	return 0;
}



