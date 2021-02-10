#include <iostream>

using namespace std;

int main() {
	char inputLetter;
	char firstLetter = 'a';
	char currentLetter;
	int n;
	int spaceCount; 

	//cout << "Please enter a lower case letter: " << endl;
	//cin >> inputLetter; 

	//
	////We have an input with a letter 'd', so we can figure out number of iterations

	//
	//	// So we can intialize a starting char with ch
	//	//then we can have a condition of ch = a <= inputLetter = d via complier repesentation
	//	// In the body, we can cast the ch from an int to a char,
	//	// Lastly we can incrament ch by 1, compiler will do the casting

	//	//Prints line from currenLetter to inputLetter
	////	for (char currentLetter = 'a'; currentLetter <= inputLetter; currentLetter++) {
	////		cout << currentLetter;
	////}

	//	// # of spaces by taking inputLetter - 'a'(first lowercase letter) + 1 
	//	// e.g. ('d' - 'a') + 1 which would equal 3 + 1 = 4
		n = (inputLetter - 'a') + 1;

	
		for (int linenumber = 1, lastletterinline = 'a'; linenumber <= n; linenumber++, lastletterinline++) {
			// prints a sequence of (n - linecount) spaces
			for (int spacecount = 1; spacecount <= (n - linenumber); spacecount++) {
				cout << " "; 
			}
			
			//print letters (from 'a') up to lastletterinline
			for (char currentletter = 'a'; currentletter <= lastletterinline; currentletter++) {
				cout << currentletter;
			}
			cout << endl;
		}

	//My Implementation of the 2nd Program
	//int inputNumbers, addedNumbers; 

	//cout << "Please enter a sequence of positive integers."
	//	<< "Each in a seperate line. End your sequence by typing -1:";

	//addedNumbers = 0; 
	//do {
	//	cin >> inputNumbers;


	//	addedNumbers += inputNumbers;
	//} while (inputNumbers != -1);
	//
	//cout << "Sum is " << addedNumbers; 

	// Professor Implementation


	int currInput = 0;
	int sum = 0;
	int counter = 0;
	int evenCounter = 0;
	int min;
	double average; 
	bool seenEndOfInput, isFirstIteration;

	cout << "Please enter a sequence of positive integers."
	<< "Each in a seperate line. End your sequence by typing -1:";

	seenEndOfInput = false;
	isFirstIteration = true;
	sum = 0;

	while (seenEndOfInput == false) {
		//1. read a number
		cin >> currInput; 

		
		if (currInput == -1) {
			// Assign seenEndOfInput to True, when user input is -1
			seenEndOfInput = true;
		}
		else {
			
			// Add the current inputs
			sum += currInput;
			// Have a counter that counts how many inputs0
			counter++;

			//When current input is even, add 1 to the evenCounter
			if ((currInput % 2) == 0) {
				evenCounter++; 
			}

			//When firstIteration is true, which its initalized
			if (isFirstIteration == true) {
				//Set the Current Input as Mininum Input
				min = currInput;
				// Assign firstIteration to false
				isFirstIteration = false;
			}

			// We want to compare the Current Input to the Mininum Input
			if (currInput < min) {
				//assign Current Input to Mininum Input
				min = currInput;
			}
		}
		
		
	}
	average = (double)sum / (double)counter; 
	cout << "The sum is: " << sum << endl;
	cout << "The average is: " << average << endl; 
	cout << "The number of evens is: " << evenCounter << endl;
	cout << "Mininum value is: " << min << endl; 


	system("pause");
}