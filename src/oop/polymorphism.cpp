#include <iostream>
#include <string>
class Animal {
public:
  Animal(const std::string name) : _name(name) {}
  void eats() const { std::cout << _name << " eats food" << std::endl; }

protected:
  std::string _name;
};

class Alligator : public Animal {
public:
  Alligator(const std::string name) : Animal(name) {}
  void eats() { std::cout << _name << " eats fishes" << std::endl; }
};

int main() {
  Alligator murphy("Murphy");
  murphy.eats();
}

// OUTPUT : Murphy eats fishes
