//By Emmet Allen. Feel free to mess around with it, think of it as a playground. Make sure to break things. 

#include <iostream>
#include <string>

using namespace std;

class Fighter{
    private:
    // Variables that can be used with class
    string fighterName;
    int healthPoints;
    double attackPower;
    string specialMove;

    public:
    //Constructor
    Fighter(): fighterName("New Fighter"), healthPoints(500), attackPower(50.0), specialMove("Twerk") {} 

    // Setters / Mutators
    void setStats(string newName, int newHealth, double newAttack, string newSpecial);
    void setName(string newName);
    void setHealthPoints(int newHealth);
    void setAttackPower(double newAttack);
    void setSpecialMove(string newSpecial);

    // Getters / Accesors
    string getName();
    int getHealthPoints() const {return this->healthPoints;}
    double getAttackPower() const {return this->attackPower;}
    string getSpecialMove();

    // function Fighter can use
    void saySpecialMove();
    void getAllStats();

    // Overloads input and output for custom fighters
    friend ostream& operator << (ostream& output, const Fighter &fighter);
    friend istream& operator >> (istream& input, Fighter &fighter);

    //Nevermind this, was figuring out something. 
    // Fighter operator-(const Fighter& lhs, const Fighter& rhs){
    //     auto s = this->fighterName
    //     s.append(opponent.fighterName);
    //     Fighter temp (this->fighterHealth + opponent.healthPoints )
    // }

    // Destructor
    ~Fighter(){
    cout << "Destoryed Fighter Class" << endl; 
    }

};


int main(){

    Fighter ryu, ken, customFighter1;
    Fighter* guile;
    ryu.setStats("Ryu", 1000, 56.4, "Hadoken");
    
    ken = ryu;
    ken.setName("Ken");
    ken.setHealthPoints(950);
    ken.setSpecialMove("Shoryuken");
   
    
    //ryu.getAllStats();
    cout << ryu; 
    cout << ken; 
     
    //ken.getAllStats();

    
    guile = new Fighter;
    guile->setStats("Guile", 920, 67.4, "Sonic Boom");
    //guile->getAllStats();
    cout << *guile; // Need to derefence because guile is intalized on the heap via new
    delete guile; 

    cin >> customFighter1; 
    cout << customFighter1; 

    return 0;
}

void Fighter::setStats(string newName, int newHealth, double newAttack, string newSpecial){
    fighterName = newName;
    healthPoints = newHealth;
    attackPower = newAttack;
    specialMove = newSpecial; 
}

void Fighter::setName(string newName)  {
    this -> fighterName = newName; 
}

void Fighter::setHealthPoints(int newHealth)  {
    if( (newHealth > 0) && (newHealth <= 1000 ) ){
    this -> healthPoints = newHealth;
    }
    else{
        cout << "Error health cannot be negative or Higher than 1000. Program will abort";
        exit(1);
    }
}

void Fighter::setAttackPower(double newAttack)  {
    this->attackPower = newAttack;
}

void Fighter::setSpecialMove(string newSpecial) {
    this->specialMove = newSpecial; 
}

string Fighter::getName() {
    return this->fighterName; 
}

string Fighter::getSpecialMove() {
    return this->specialMove; 
}

void Fighter::getAllStats() {
    cout << fighterName << " " << healthPoints << " " << attackPower << " " << specialMove; 
}

ostream& operator << (ostream& output, const Fighter &fighter){
    output << "The Fighter " << fighter.fighterName << " has " << fighter.healthPoints << " with " << fighter.attackPower;
    output << ". Their special move is " << fighter.specialMove << "!" << endl; 
    return output;
}

istream& operator >> (istream& input, Fighter &fighter){
    cout << "Create your own fighter here!" << endl;
    cout << "Fighters Name, Fighters Health, Fighters Attack Power, and the Fighters Special Move: "; 
    input >> fighter.fighterName >> fighter.healthPoints >> fighter.attackPower >> fighter.specialMove;
    return input;
}

