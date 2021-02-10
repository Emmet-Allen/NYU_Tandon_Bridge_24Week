#include <iostream>

using namespace std;

int main(){

    int userInput, num;
    int currentDigit;

    //Used to determine odd digit
    bool seenOddDigit; 

    cout << "Please enter a postive integer" << endl;
    cin >> userInput;

    num = userInput;

    while( (num > 0) && (seenOddDigit == false)){
        currentDigit = num % 10;
        if( (currentDigit % 2) == 1){
            seenOddDigit = true; 
        }
        num = num / 10;      
    }

    if(seenOddDigit == false){
        cout << userInput << " is super even" << endl;
    }
    else{
        cout << userInput <<" is not super even" << endl; 
    }

   
    return 0;
}