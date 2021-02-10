#include <iostream>

using namespace std;

int main(){
    int n;
    int lineCount, starCount, spaceCount, numberOfStars, numberOfSpaces;

    cout << "Please enter a positive integer: " << endl;
    cin >> n; 

    cout <<"Square" << endl;
    for(lineCount = 1; lineCount <= n; lineCount+= 1){
        // print a sequece of n stars;
        for(starCount = 1; starCount <= n; starCount+= 1){
            cout <<"*";
        }
        // break the line
        cout << endl;
    }

    cout << "Right Triangle" << endl;
    for(lineCount = 1; lineCount <= n; lineCount+= 1){
        //print a sequence of lineCount stars
        for(starCount = 1; starCount <= lineCount; starCount+= 1){
            cout << "*";
        }
        //break the line
        cout << endl;
    }

    cout << "Right Triangle aligned to the Right" << endl;

    for(lineCount = 1; lineCount <= n; lineCount+= 1){
        //print a sequence of "n - linecount" spaces
      for(spaceCount = 1; spaceCount <= (n-lineCount); spaceCount+= 1){
          cout<<" "; 
      }  

        //print a sequence of "lineCount" stars
        for(starCount = 1; starCount <= lineCount; starCount+= 1){
            cout<<"*";
        }

        //break the line
        cout << endl; 

    }

    cout << "Right Triangle aligned to the Right in the incremental approach" << endl;

    //numberOfStars is initalized and incremented throughout the iterations
        for(lineCount = 1; numberOfStars = 1, numberOfSpaces = (n-1); 

        //gcc doesn't like this.
        lineCount <= n; 
        lineCount+= 1, numberOfStars +=1, numberOfSpaces -= 1){
        //print a sequence of "numberOfSpaces" spaces
      for(spaceCount = 1; spaceCount <= numberOfSpaces; spaceCount += 1){
          cout<<" "; 
      }  

        //print a sequence of "lineCount" stars
        for(starCount = 1; starCount <= numberOfStars; starCount+= 1){
            cout<<"*";
        }

        //break the line
        cout << endl; 

    }



    return 0;
}