#include <iostream>
using namespace std;

// Parent Class
class Enemy{
    protected: 
 
        int attackPower;
 
    public:
 
    void setAttackPower(int _AttackPower){
        attackPower = _AttackPower; 
    }

};

// Child Class of "Enemy"
class Ninja : public Enemy{

    public:
    void attack(){
        cout << "Ninja Star! -" << attackPower << endl; 
    }
};

// Child Class of "Enemy"
class Monster: public Enemy{
    public:
    void attack(){
        cout << "Bite Attack! -" << attackPower << endl;
    }
};



int main(){

    Ninja Naruto;
    Monster CookieMonster;

    // All Ninja's are Enemies, All Monsters are Enemies
    // So we can set the address of a Ninja or Monster, to the pointer of Enemy
    // Anything an Enemy can do, A Ninja/Monster can do
    Enemy* enemy1 = &Naruto;
    Enemy* enemy2 = &CookieMonster; 

    // Any Enemy object you can call 'setAttackPower' or any Function of that object
    // Because it is pointing to the Ninja object, it is setting the Ninja's attack power
    enemy1->setAttackPower(10);
    enemy2->setAttackPower(30);

    // We can't use enemy1/enemy2 because it is the Class Enemy
    // So it doesn't have access to Ninja.attack() or Monster.attack()
    Naruto.attack();
    CookieMonster.attack();




    return 0; 
}
