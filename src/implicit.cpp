#include <iostream>
#include <string>
using namespace std;
class Entity{
private:
    string m_Name;
    int m_Age;
public:
    Entity(const string& name)
        : m_Name(name), m_Age(-1){}
    explicit Entity(const int& age)
        : m_Name("Unknown"), m_Age(age){}
    void Getter() const{
        cout<<m_Name<<" "<<m_Age<<endl;
    }
};
void Printable(Entity& e){
    e.Getter();
}
int main(){
//Entity e1 = 22; //error due to explicit constructor
Entity e1 = Entity(22);
Entity e2 = std::string("Sameer");
Entity e3("Sameer");
Entity e4(22);
Printable(e1);
Printable(e2);
Printable(e3);
Printable(e4);

}