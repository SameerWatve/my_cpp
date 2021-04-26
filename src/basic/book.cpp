#include <iostream>
using namespace std;

template<typename T>
class player{
    int m_x;
    T m_y;
public:
    player(int x,T& y)
        :m_x(x),m_y(y){}
    void print(){
        cout<<"I am object"<<m_x<<m_y<<endl;
    }
};
int main(){
    int a = 5;
    player<int>p1(8,a);
    //player<float>p2(p1);
    //player<float>p3(7,8.8f);
    //p3 = p1;
    //p3.print();
    //p2.print();

}