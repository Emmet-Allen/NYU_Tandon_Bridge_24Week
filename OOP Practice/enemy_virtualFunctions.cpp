#include <iostream>
using namespace std;

// Parent Class
class Enemy{
    // Protected: Child Members have access to these variables/values
    protected:
    int attackPower;

    public:
        // Ninja and Monster will have their own 'attack' functions
        // When you make a function virtual, you will be using the function polymorphically via pointers
        // So, it tells the pointer to use the Child Class function instead of the Parent's class
        // Virtual Functions are TEMPLATE FUNCTIONS
        virtual void attack(){}

        //Can use virtual functions to create TEMPLATE FUNCTIONS WITH PARAMETERS!
        virtual void setAttackPower(int _attackPower){}

};

// Child Class of "Enemy"
class Ninja: public Enemy{
    public:
    void setAttackPower( int _attackPower){
         attackPower = _attackPower;
    }

    void attack(){
        cout << "Ninja Swipe! -" << attackPower << endl;
    }

};

// Child Class of "Enemy"
class Monster: public Enemy{
    public:
    void setAttackPower(int _attackPower){
        attackPower = _attackPower;
    }

    void attack(){
        cout << "Monster Scream! -" << attackPower << endl;
    }
};



int main(){
    Ninja Sasuke;
    Monster Sully; 

    // Polymorphism, Monsters and Ninjas are more specific types of Enemies
    Enemy* enemy1 = &Sasuke;
    Enemy* enemy2 = &Sully;

    enemy1->setAttackPower(50);
    enemy2->setAttackPower(40);

    // Virtual OVERRIDE: Function knows to look into the Ninja/Monster classes for attack();
    enemy1->attack();
    enemy2->attack();
    

    return 0; 
}