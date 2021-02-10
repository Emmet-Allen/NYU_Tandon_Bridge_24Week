#include<iostream>
#include <cmath>

using namespace std;

// First Method
// **********************************
// int main(){

//     int n; 
//     int lineCount, powerOf2;

//          cout << "Please enter a positive integer: " << endl;
//          cin >> n; 

//         lineCount = 1; 
//         while(lineCount <= n){
      
//             powerOf2 = pow(2, lineCount-1); 
//             cout << lineCount <<". " << powerOf2 << endl; 
//             lineCount +=1; 
//         }
//     return 0;
// }
// *******************************************************

// Second Method
//************************************************************
// int main(){

//     int n; 
//     int lineCount, powerOf2;

//          cout << "Please enter a positive integer: " << endl;
//          cin >> n; 
    
//         //Intialization, Condtion, Increamentation. Same as While loop just condensed
//     for(lineCount = 1; lineCount <= n; lineCount +=1){
//             powerOf2 = pow(2, lineCount-1); 
//             cout << lineCount <<". " << powerOf2 << endl; 

//     }


//     return 0;
// }
// **************************************************************


//Third Method Using "while in the incremental approach"
//********************************************************************
// int main(){

//     int n; 
//     int lineCount, powerOf2;

//          cout << "Please enter a positive integer: " << endl;
//          cin >> n; 

//          lineCount = 1;
//          powerOf2 = 1;

//          while (lineCount <= n){
//              cout << lineCount <<". " << powerOf2 << endl; 
//              lineCount += 1;
//              powerOf2 *= 2;
//          }

//      return 0;
// }
//************************************************************************

//Fourth Method Using "For in the incremental approach "
//************************************************************************

int main(){
    int n; 
    //lineCount instead of lineCount
    int lineCount, powerOf2;

         cout << "Please enter a positive integer: " << endl;
         cin >> n; 

        //Can intialize multiple intializations by seperating with a comma (,)
        for(lineCount = 1,powerOf2 = 1; lineCount <= n; lineCount += 1, powerOf2 *= 2){
            cout<< lineCount <<". " << powerOf2 << endl; 
        }

return 0;
}