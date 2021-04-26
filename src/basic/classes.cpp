#include <iostream>
using namespace std;
class Player{
public:
    int x,y;
    int speed;
    Player(int x1 , int y1){
        x = x1;
        y = y1;
    }
    void move(int xa, int ya){
        x = x+ xa*speed;
        y = y+ ya*speed;
    }
};
struct Vec2{
    int x,y;
    int total;
    void caltotal(){
        total = x+y;
    }
};
int main(){
    Player* p;
    Player p1(3,4);
    {
    Player* p2 = new Player(5,6);
    Player p3(7,8);
    p = p2;
    }
    //p1.x = 5;
    //p1.y = 7;
    p1.speed = 2;
    p1.move(-3,1);
    cout<<p1.x<<" "<<p1.y<<endl;
    Vec2 v;
    v.x=4;
    v.y=5;
    v.caltotal();
    cout<<p->x<<p->y<<endl;
    delete p;
    //cout<<v.total<<endl;

}