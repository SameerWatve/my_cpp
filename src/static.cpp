#include <iostream>
using namespace std;
class Player{
private:
    int x,y,speed;
public:
    static long count;
    const static int max_speed = 100;
public:
    void Move(int xa, int ya){
        x = x + xa * speed;
        y = y + ya* speed;
    }
    void print(){
        ++count;
        cout<<count<<endl;
        cout<<max_speed<<endl;
        //cout<<x<<y<<endl;
    }
    void incr(){
        count++;
    }

};
long Player::count=0;
int main(){
    Player::count = 0;
    Player p1;
    //p1.incr();
    p1.print();
    Player p2;
    //p2.incr();
    p2.print();

}