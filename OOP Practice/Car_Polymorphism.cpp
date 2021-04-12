#include <iostream>
#include <string>

using namespace std; 

//Vehicle Parent Class
class Vehicle{
    
    
    private:
    string name; 
    float weight; 
    int horsePower; 
    
    
    public:
    // Constructor with default intilizations
    Vehicle(string _name, float _weight, int _horsePower): name("Cyar"), weight(0.0), horsePower(0) {
        // Intilizations of values via Constructor Arguements. 
        name = _name;
        weight = _weight;
        horsePower = _horsePower; 
    };
   // Worry about this later, brain is focused on something else; 
   // Vehicle(string name, int horsePower): name("Cyar"), horsePower(horsePower) {};

    //Mutators/Setters
    void setWeight(float gWeight) { weight = gWeight;}
    void setName(string gName) {name = gName;}
    void setHorsePower(int gHorsePower) {horsePower = gHorsePower;}
    
    //Accesors/Getters
    string getName() const {return this->name;}
    int getWeight() const {return this->weight;}
    float getHorsePower() const {return this->horsePower;} 
    
    // Safe Version of assignment overload
    Vehicle& operator=(const Vehicle& other){
        if(this != &other){
            this->weight = other.weight;
            this->name = other.name;
            this->horsePower = other.horsePower;
        }
        return *this; 
    };
};

// Child BMW Class from Parent Vehicle Class
class BMW :public Vehicle{
    
    private:
    string luxuryTier;
    
    public:
    // Base Intilizations List 
    BMW() :Vehicle("BMW", 4586.3, 542){}
    
    //Mutators
    void setLuxuryTier(string getLuxuryTier){luxuryTier = getLuxuryTier;}
    
    string getLuxuryTier(){return this->luxuryTier;}
    
    //Overloader Y U NOT WORKING?
    BMW& operator=(const BMW& other) {
        if (this != &other) {
            this->luxuryTier = other.luxuryTier;
        }
        return *this;
    };

    BMW& operator=(const Vehicle& other) {
        if (this != &other) {
            Vehicle::operator=(other);
        }
        return *this;
    };
    
};



int main()
{
    Vehicle Jaguar("Jaguar", 8001.0, 234);
    BMW X254; 
    //Jaguar.setHorsePower(234);
    
    X254.setLuxuryTier("Top-tier");
    
    cout << X254.getLuxuryTier() << endl; 
    
    cout << Jaguar.getHorsePower() << Jaguar.getName();
    
    Vehicle OscarMyerWeinerTruck();
    Vehicle* pOscarMyerWeinerTruck;
    BMW Z9001, *pZ9001; 
    
    // Pointer Parent Object to Address Child Object 
    pOscarMyerWeinerTruck = &Z9001; 
    Z9001 = OscarMyerWeinerTruck;  
    
    

    return 0;
}