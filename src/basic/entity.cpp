#include <iostream>
using namespace std;
class Player{
private:
    int x,y,speed=1;
public:
    static long count;
public:
    Player(int xa, int ya){
        cout<<"created object"<<endl;
        x = xa;
        y = ya;
    }
    ~Player(){
        cout<<"destroyed"<<endl;
    }
    void Move(int xa, int ya){
        x = x + xa * speed;
        y = y + ya* speed;
    }
    void print(){
        ++count;
        cout<<count<<endl;
        cout<<x<<y<<endl;
    }
    void incr(){
        count++;
    }
};
long Player::count = 0;

void func(){
    Player p1(1,2);
    p1.print();
    p1.Move(1,2);
    Player p2(2,4);
    p2.Move(9,8);
    p2.print();
}
int main(){
    func();

}