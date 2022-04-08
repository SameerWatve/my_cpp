#include <iostream>
#include <string>

class Product {
public:
  Product() { std::cout << "Product is created" << std::endl; }
  virtual ~Product() { std::cout << "Product is destroyed" << std::endl; };
  virtual void checkProduct() = 0;
};

class ProductA : public Product {
public:
  ProductA() { std::cout << "Product A is created" << std::endl; }
  ~ProductA() { std::cout << "Product A is destroyed" << std::endl; };
  void checkProduct() { std::cout << "Product A is here" << std::endl; };
};

class ProductB : public Product {
public:
  ProductB() { std::cout << "Product B is created" << std::endl; }
  ~ProductB() { std::cout << "Product B is destroyed" << std::endl; };
  void checkProduct() { std::cout << "Product B is here" << std::endl; };
};

class Creater {
public:
  Creater() { std::cout << "Creater is created" << std::endl; }
  virtual ~Creater() { std::cout << "Creater is destroyed" << std::endl; };
  virtual Product *createProductA() = 0;
  virtual Product *createProductB() = 0;
};

class ConcreteCreater : public Creater {
public:
  ConcreteCreater() { std::cout << "ConcreteCreater is created" << std::endl; }
  virtual ~ConcreteCreater() {
    std::cout << "ConcreteCreater is destroyed" << std::endl;
  };
  Product *createProductA() { return new ProductA; }
  Product *createProductB() { return new ProductB; }
};

int main() {
  Creater *creater = new ConcreteCreater;
  Product *productA = creater->createProductA();
  productA->checkProduct();
  Product *productB = creater->createProductB();
  productB->checkProduct();
  delete productA;
  delete productB;
  delete creater;
}

// Output:
// Creater is created
// ConcreteCreater is created
// Product is created
// Product A is created
// Product A is here
// Product is created
// Product B is created
// Product B is here
// Product A is destroyed
// Product is destroyed
// Product B is destroyed
// Product is destroyed
// ConcreteCreater is destroyed
// Creater is destroyed