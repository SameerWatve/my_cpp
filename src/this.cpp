#include <iostream>
using namespace std;
class Entity;
void PrintableX(const Entity* e);
void PrintableY(const Entity& e);
class Entity{
public:
    int x, y;
    Entity(int x,int y){
        this->x = x;
        this->y = y;
        cout<<" created entity"<<endl;
        PrintableX(this);
        PrintableY(*this);
    }
    void Getx() const{
        cout<<this->x;
    }
};
void PrintableX(const Entity* e){
    cout<<e->x<<endl;
}
void PrintableY(const Entity& e){
    cout<<e.y<<endl;
}

int main(){
    Entity* e1 = new Entity(1,2);
    Entity e2(8,9);
    delete e1;
}