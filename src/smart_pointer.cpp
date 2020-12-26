#include <iostream>
#include <memory>
using namespace std;
class Entity {
private:
    int m_entity = 0;
public:
    Entity(int x){
        m_entity = x;
        cout<<"Created!"<<endl;
    }
    ~Entity(){
        cout<<"Destroyed!"<<endl;
    }
    void print(){
        cout<<"I am method "<<m_entity<<endl;
    }
};
int main(){
    {
        std::unique_ptr<Entity> e1 = std::make_unique<Entity>(100);
        e1->print();
        int* e2 = new int(8);
        std::unique_ptr<int> e3 = std::make_unique<int>(9);
        cout<<*e2<<*e3<<endl;
    }
    std::shared_ptr<Entity> e4;
    {
        std::shared_ptr<Entity> e5 = std::make_shared<Entity>(101);
        e5->print();
        e4 = e5;
    }
    {
        e4->print();
    }

}