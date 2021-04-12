#include <iostream>
using namespace std;

// An Abstract Class is Any Class with a Pure Virtual Function
class Enemy{
    public:

        // If a child class does not implement a virtual overide
        // It will default to the Parent Class virtual function
        // virtual void attack(){
        //     cout << "I am an Enemy Class!" << endl; 
        // }

        // A pure virtual function DOES NOT DO ANYTHING!
        // Any child class that inherits a PURE virtual function from a parent class
        // THE CHILD CLASS MUST OVERRIDE THE FUNCTION! NO EXCEPTION! 
        virtual void attack() = 0;

};

class Ninja: public Enemy{
    public:
    void attack(){
        cout << "Shadow Clone Jutsu!" <<endl;
    }

};

class Monster: public Enemy{
    public:
    void attack(){
        cout << "ThunderBolt! " << endl;
    }
};




int main(){
    Ninja Jiraya;
    Monster Pikachu;

    Enemy* pJiraya = &Jiraya, *pPikachu = &Pikachu; 

    pJiraya->attack();
    pPikachu->attack();


    return 0; 
}