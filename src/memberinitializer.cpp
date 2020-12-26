#include <iostream>
#include <string>
using namespace std;
class Example{
public:
    Example(){
        cout<<"created example!"<<endl;
    }
    Example(int x){
        cout<<"created example "<<x<<"!"<<endl;
    }
};
class Entity{
private:
    string m_name;
    Example m_exam;
public:
    Entity(): m_name("Unknown"),m_exam(8){}
};
int main(){
    Entity e;
}