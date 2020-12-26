#include <iostream>
using namespace std;
class Entity{
protected:
    int m_X,m_Y;
public:
    void setter(int x, int y){
        this->m_X = x;
        this->m_Y = y;
    }
    virtual void getter(){
        cout<<"Entity ";
        cout<<this->m_X<<" "<<this->m_Y<<endl;
    }
};

class Player: public Entity{
public:
    void setter(int x, int y){
        this->m_X = x;
        this->m_Y = y;
    }
    void getter(){
        cout<<"Player ";
        cout<<this->m_X<<" "<<this->m_Y<<endl;
    }
};
int main(){
    Entity *e = new Entity();
    Entity *p = new Player();
    e->setter(3,5);
    p->setter(7,8);
    p->getter();
    e->getter();
}