#include <iostream>
using namespace std;
class Print{
public:
   virtual void PrintName() = 0; 
};
class Entity: public Print{
public:
    virtual void GetName(){
        cout<<"entity"<<endl;
    }
    void PrintName(){
        cout<<"Entity"<<endl;
    }
};
class Player: public Entity{
private:
    std::string m_name;
public:
    Player(const std::string s): m_name(s){}
    void GetName(){
        cout<<"player class ";
        cout<<m_name<<endl;
    }
    // void PrintName(){
    //     cout<<"Player"<<endl;
    // }

};

int main(){
    Entity *e = new Entity();
    e->PrintName();
    Player *p = new Player("Sameer");
    Entity *e1 = p;
    int *a = new int(8);
    cout<<*a<<endl;
    e1->PrintName();
}