#include <iostream>
#include <string>
class Car {
public:
  void setName(const std::string name) { _name = name; }

  void startEngine() const {
    std::cout << "Engine started For " << _name << std::endl;
  }

  void stopEngine() const {
    std::cout << "Engine stopped For " << _name << std::endl;
  }

protected:
  std::string _name;
};

class Toyota : public Car {
public:
  void topSpeed(const int speed) const {
    std::cout << "Top Speed For " << _name + " is " << speed << std::endl;
  }
};

int main() {
  auto myCar = Toyota();
  myCar.setName("Camry");
  myCar.startEngine();
  myCar.stopEngine();
  myCar.topSpeed(200);
}

// OUTPUT :
// Engine started For Camry
// Engine stopped For Camry
// Top Speed For Camry is 200