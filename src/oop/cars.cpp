#include <string>
#include <iostream>

class Car {
public:
    Car(std::string name, double oil) : _name(name), _oil(oil) {}
    std::string getName() const{
        return _name;
    }
    double getLeftMiles() {
        return _oil * getMilesPerGallon();
    }
protected:
    std::string _name;
    double _oil;
    virtual double getMilesPerGallon() = 0;
};
class Benz : public Car {
public:
    Benz(std::string name, double oil) : Car(name, oil) {}
    double getMilesPerGallon() {return 20.0;}
};

class Audi : public Car {
public:
    Audi(std::string name, double oil) : Car(name, oil) {}
    double getMilesPerGallon() {return 18.0;}
};

class BMW : public Car {
public:
    BMW(std::string name, double oil) : Car(name, oil) {}
    double getMilesPerGallon() {return 19.0;}
};

void showCarLeftMiles(Car &car) {
    std::cout << car.getName() << " " << car.getLeftMiles() << std::endl;
}

int main() {
    Benz a("Benz", 20.0);
    Audi b("Audi", 20.0);
    BMW c("BWM", 20.0);
    showCarLeftMiles(a);	// Benz 400
    showCarLeftMiles(b);	// Audi 360
    showCarLeftMiles(c);	// BMW 380
    return 0;
}



