#include <iostream>
#include <string>

class Employee {
public:
  void setEmpDetails(const std::string name, const int id, const long phone) {
    _name = name;
    _id = id;
    _phone = phone;
  }

  std::string getEmpName() const { return _name; }
  int getEmpId() const { return _id; }
  int getEmpPhoneNo() const { return _phone; }

private:
  std::string _name;
  int _id;
  long _phone;
};

int main() {
  auto emp1 = Employee();
  emp1.setEmpDetails("John", 319, 9788786086);
  std::cout << emp1.getEmpName() << std::endl;
}

// OUTPUT : John