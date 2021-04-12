#include <iostream>
#include <vector>
using namespace std;


void main1() {
    int arrSize = 0;
    int *userSeqPtr;
    userSeqPtr = new int [arrSize];
    int searchCounter = 0;
    int *searchIndexesPtr;
    searchIndexesPtr = new int[searchCounter];
    int userInput = 0;
    int searchInt;



    cout << "Please enter a sequence of positive integers, each in a separate line." << endl;
    cout << "End your input by typing -1" << endl;

    while (userInput >= 0) {
        cin >> userInput;
        arrSize ++;
        userSeqPtr[(arrSize-1)] = userInput;

    }

    cout << "Please enter a number you want to search." << endl;
    cin >> searchInt;

    for (int i = 0; i < arrSize; ++i) {
        if(userSeqPtr[i] == searchInt) {
            searchCounter ++;
            searchIndexesPtr[(searchCounter-1)] = (i+1);
        }
    }

    if (searchCounter > 0) {
        cout << searchInt << " shows in lines ";

        for (int i = 0; i < searchCounter; ++i) {
            cout << searchIndexesPtr[i];
            if (i < (searchCounter - 1)) {
                cout << ", ";
            }
        }

        cout << ".";
    }
    else {
        cout << searchInt << " does not appear in the sequence.";
    }

    delete [] userSeqPtr;
    delete [] searchIndexesPtr;
}

void main2() {
    vector<int> userSeq;
    vector<int> searchIndexes;
    int userInput = 0;
    int searchInt;
    int searchCounter = 0;


    cout << "Please enter a sequences of positive integers, each in a separate line." <<endl;
    cout << "End your input by typing -1." << endl;

    while (userInput >= 0) {
        cin >> userInput;
        userSeq.push_back(userInput);
    }

    cout << "Please enter a number you want to search." << endl;
    cin >> searchInt;

    for (int i = 0; i < userSeq.size(); ++i) {
        if (userSeq[i] == searchInt) {
            searchCounter ++;
            searchIndexes.push_back((i + 1));
        }
    }

    if (searchIndexes.size() > 0) {
        cout << searchInt << " shows in lines ";

        for (int i = 0; i < searchIndexes.size(); ++i) {
            cout << searchIndexes[i];
            if (i < (searchIndexes.size() - 1)) {
                cout << ", ";
            }
        }
        cout << ".";
    }
    else {
        cout << searchInt << " does not appear in the sequence.";
    }
}


int main() {

    cout << "RUNNING MAIN 1 - NON-VECTOR SOLUTION" << endl;
    main1();

    cout << endl << endl;

    cout << "RUNNING MAIN 2 - VECTOR SOLUTION" << endl;
    main2();

    return 0;
}