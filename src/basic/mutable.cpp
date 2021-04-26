#include <iostream>
using namespace std;
class Entity{
private:
    int m_x,m_y;
    mutable int debug_count = 0;
public:
    Entity(int x, int y): m_x(x), m_y(y){}
    void getter() const
    {
        debug_count++;
        cout<<m_x<<" "<<m_y<<" "<<debug_count<<endl;
    }
};
int main(){
    const Entity e1(1,2);
    e1.getter();
    int a = 5;
    int b = a > 6 ? 0 : 9;
    int c = a > 3 ? 0 : 1;
    a = b > a ? b : a;
    cout<<b<<" "<<c<<" "<<a<<endl;
}