// Created by Emmet Allen
// Feel Free to share!

#include <iostream>
#include <vector>

using namespace std;

void pointerBasics();
void pointerMath();
void usingArrays();
void accesssingArrays();
void accessingCharArrays(); 

int main() {
	
	//pointerBasics();
	//pointerMath(); 
	//usingArrays();
	//accesssingArrays();
	//accessingCharArrays();


	system("Pause");
	return 0;
}

void accessingCharArrays() {
	
	// An Array of type 'char'. Simply a string. 
	char SomeString[] = "Hello!";

	// A pointer that points to the memory addresses of "SomeString"
	char* pSomeString = SomeString; 

	// Prints the pointer of the memory addresses of "SomeString"
	cout << "pSomeString = " <<  pSomeString <<endl; 

	// Get the memory location at indexes '3' and '0'
	char* pLocation3 = &SomeString[3];
	char* pLocation0 = &SomeString[0];

	cout << "Memory address of 'pLocation3' in bits : " << (int)pLocation3 << endl;
	cout << "Memory address of 'pLocation0' in bits : " << (int)pLocation0 << endl;
	// The difference will be dependent on the 'type' of memory. 
	cout << "Difference b/w sizes of 'pLocation3' and 'pLocation0' : " << pLocation3 - pLocation0 << endl;

	// Will start the index of the string at '3' and '0' respectfully.
	// This is because pointers that have a type 'char' are expecting a string
	// So they will act differently depending on the type of data they recieve. 
	cout << "pLocation3 : " << pLocation3 << endl;
	cout << "pLocation0 : " << pLocation0 << endl;


}

void accesssingArrays() {

	//Arrays are pointers in disguise. They hold the memory address of a certain type continously.
	int SomeArray[10] = { 3, 6, 9, 12, 15, 18, 21, 24, 27, 30 };

	//Arrays just hold the memory of a specified type of data in a sequence of memory.
	// We can then just call the array without referencing it.
	int* pLocation0 = &SomeArray[0];

	cout << "Pointer that holds the address of Array at index '0': " << pLocation0 << endl;
	cout << endl; 

	// Arrays are pointers in disguise. This prints out the memory address of each index of the array.
	// Each index of the array is 'type-more' size than the next. These indexes are 'int' size more than the next. 
	for (int i = 0; i < 10; i++) {
		cout << "Address of SomeArray [" << i << "] " << SomeArray + i << '\t';

	// Arrays hold the memory address of a type of data continously.
	// We can first: Increment the starting address of the Array by 'i' 
	// and second: Use the value of (*) operator to get the stored value at the address "Array + i"
		cout << "The Value of SomeArray[" << i << "] " << *(SomeArray + i) << endl;

	// We can also access the values of the array using a pointer and incrementing it by each iteration of the loop
	// First: Increment the pointer
	// Second: Use the 'value of' (*) operator to get the stored value from the pointer. 
		cout << "Using pointer 'pLocation0' to access the values of the array: " << *(pLocation0++) << endl;
		cout << endl;

	}


}


void usingArrays() {

	//40 bytes of uninterupted memory
	int SomeArray[10]; 

	// Pointer that holds the memory address of Array at position '6'
	int* pLocation6 = &SomeArray[6];

	//Pointer that holds the memory address of Array at position '0'
	int* pLocation0 = &SomeArray[0];

	cout << "Memory address of 'pLocation6' in bits : " << (int)pLocation6 << endl;
	cout << "Memory address of 'pLocation0' in bits : " << (int)pLocation0 << endl;
	// The difference will show as an integer of bytes. 1 bytes = 8 bits. 
	cout << "Difference b/w sizes of 'pLocation6' and 'pLocation0' : " << pLocation6 - pLocation0 << endl; 

	// The memory addresses work on a 'per byte' basis. 
	// The pointers work in a space depending on the 'type' its pointing to. 

}



void pointerMath() {
	int a = 5;
	
	//'b' originally points to 'a' which is an int and takes 4 bytes, or 32 bits.
	int* b = &a; 
	cout << "Original memory address of 'b' pointer :" << b << endl;

	//if we increment 'b' by '1', we get the next 'int' memory address.
	b = b + 1;
	cout << "Increment 'b' by next memory address: " << b << endl;

	// We can also increment 'b' using 'sizeof(x)' which will let us increment by a specific number of bytes, based on data type 'x'.
 	b = b + sizeof(int);
	cout << "Increment 'b' by the size of 'int' bytes: " << b << endl; 

}

void pointerBasics() {
	// Direct Addressing
	int a = 5;

	// Indirect Addressing

	// 1. Create pointer variable
	int* b;
	// 2. Pointers holds memory address
	b = &a;
	// 3. Create another variable that retieves the value from the memory address
	int c = *b;

	// Direct Addressing
	cout << "Direct Addressing: " << a << endl;

	// Indirect Addressing: Pointer to memory Address
	cout << "Indirect Addressing: Pointer holds memory address: " << b << endl;

	// Indirect Addressing: Get the value from the location pointed to
	cout << "Indirect Addressing: Another variable retieves the value from pointed memory address: " << c << endl;

}
