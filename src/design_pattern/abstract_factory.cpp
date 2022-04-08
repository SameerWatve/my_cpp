#include <iostream>

class Car {
public:
  Car() { std::cout << "Car is created" << std::endl; }
  virtual ~Car() {}
  virtual void checkCar() = 0;
};

class LuxuryCar : public Car {
public:
  LuxuryCar() { std::cout << "Luxury Car is created" << std::endl; }
  ~LuxuryCar() {}
  void checkCar() { std::cout << "Luxury Car is here" << std::endl; }
};

class SedanCar : public Car {
public:
  SedanCar() { std::cout << "Sedan Car is created" << std::endl; }
  ~SedanCar() {}
  void checkCar() { std::cout << "Sedan Car is here" << std::endl; }
};

class Truck {
public:
  Truck() { std::cout << "Truck is created" << std::endl; }
  virtual ~Truck() {}
  virtual void checkTruck() = 0;
};

class SemiTruck : public Truck {
public:
  SemiTruck() { std::cout << "Semi Truck is created" << std::endl; }
  ~SemiTruck() {}
  void checkTruck() { std::cout << "Semi Truck is here" << std::endl; }
};

class PickupTruck : public Truck {
public:
  PickupTruck() { std::cout << "Pickup Truck is created" << std::endl; }
  ~PickupTruck() {}
  void checkTruck() { std::cout << "Pickup Truck is here" << std::endl; }
};

class AutoFactory {
public:
  AutoFactory() { std::cout << "Welcome to Auto factory" << std::endl; }
  virtual ~AutoFactory() {
    std::cout << "Factory is closing down" << std::endl;
  }
  virtual Truck *createTruck() = 0;
  virtual Car *createCar() = 0;
};

class USAFactory : public AutoFactory {
public:
  USAFactory() { std::cout << "Welcome to Auto factory USA" << std::endl; }
  virtual ~USAFactory() {
    std::cout << "USA Factory is closing down" << std::endl;
  }
  virtual Truck *createTruck() { return new PickupTruck; }
  virtual Car *createCar() { return new LuxuryCar; }
};

class AsiaFactory : public AutoFactory {
public:
  AsiaFactory() { std::cout << "Welcome to Auto factory Asia" << std::endl; }
  virtual ~AsiaFactory() {
    std::cout << "Asia Factory is closing down" << std::endl;
  }
  virtual Truck *createTruck() { return new SemiTruck; }
  virtual Car *createCar() { return new SedanCar; }
};

int main() {
  AutoFactory *factory1 = new USAFactory;
  AutoFactory *factory2 = new AsiaFactory;
  Car *c1 = factory1->createCar();
  c1->checkCar();
  Car *c2 = factory2->createCar();
  c2->checkCar();
  Truck *t1 = factory1->createTruck();
  t1->checkTruck();
  Truck *t2 = factory2->createTruck();
  t2->checkTruck();
}

// Output
//  Welcome to Auto factory
//  Welcome to Auto factory USA
//  Welcome to Auto factory
//  Welcome to Auto factory Asia
//  Car is created
//  Luxury Car is created
//  Luxury Car is here
//  Car is created
//  Sedan Car is created
//  Sedan Car is here
//  Truck is created
//  Pickup Truck is created
//  Pickup Truck is here
//  Truck is created
//  Semi Truck is created
//  Semi Truck is here