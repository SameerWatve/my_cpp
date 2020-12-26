#include <iostream>
#include <string>

class Entity{
public:
    int m_x=0;
public:
    Entity(int x=0): m_x(x){}
    void Print() const {
        std::cout<<"hello "<<m_x<<std::endl;
    }
};

class scopedptr{
private:
    Entity* m_obj;
public:
    scopedptr(Entity* e):m_obj(e){}
    ~scopedptr(){delete m_obj;}
    const Entity* operator->()
    {
        return m_obj;
    }
};
int main(){
    Entity* e = new Entity();
    Entity e1;
    e->m_x = 10;
    e->Print();
    delete e;
    e1.Print();
    scopedptr entity = new Entity(5);
    entity->Print();
}