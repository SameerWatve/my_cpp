#include <iostream>
#include <tuple>
using namespace std;
class Entity{
private:
    int m_x, m_y;
public:
    tuple<int,int> Getter() const//method can't change member variables
    {
        cout<<"I am Getter"<<m_x<<m_y<<endl;
        return make_tuple(m_x, m_y);
    }
    void Setter(int x, int y)
    {
        m_x = x;
        m_y = y;
    }
};
// void PrintX (Entity& e){
//     e.Setter(10,12);
//     cout<<get<0>(e.Getter())<<endl;
// }

void PrintX (const Entity& e){
    cout<<get<0>(e.Getter())<<endl;
}
void PrintY (const Entity& e){
    //e.Setter(0,0); //error
    cout<<get<1>(e.Getter())<<endl;
}
int main(){
    Entity* e1 = new Entity;
    e1->Setter(8,9);
    e1->Getter();
    const Entity* e2= new Entity;
    //e2->Setter(10,11); //error
    e2->Getter();
    PrintX(*e1);
    PrintY(*e1);

    int a = 5;
    const int MAX_AGE = 90;
    a = 6;
    const int* ptr = new int;
    ptr++;
    //*ptr = 2; //error
    
    int* const ptr1 = new int;
    *ptr1 = 2;
    //ptr1++; //error

    int const* ptr2 = new int;
    //*ptr2 = 2; //error
    ptr2++;

    const int* const ptr4 = new int;
    //both errors
    // *ptr4 = 4;
    // ptr4++;


}