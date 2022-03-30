
#include <iostream>
#include <string>

class Employee {
public:
  Employee(const std::string name, const int age, const int baseSalary)
      : _name(name), _age(age), _baseSalary(baseSalary) {}

  // This is not exposed to the user
  void calculateMonthlyBonus() {
    auto _finalSalary = _baseSalary + _monthlyBonus;
    std::cout << "Final Salary is : " << _finalSalary << std::endl;
  }

  void getEmpDetails() {
    std::cout << "Name: " << _name << " Age: " << _age
              << " baseSalary: " << _baseSalary << std::endl;
    calculateMonthlyBonus();
  }

private:
  std::string _name;
  int _age;
  int _baseSalary;
  const int _monthlyBonus = 1000;
};

int main() {
  auto emp1 = Employee("John", 30, 2000);
  emp1.getEmpDetails();
}

// OUTPUT
// Name: John Age: 30 baseSalary: 2000
// Final Salary is :  3000