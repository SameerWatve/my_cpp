#include <iostream>
#include <string>

template<typename T>
void print(T val){
    std::cout<<val<<std::endl;
}

template<typename T, int N>
class player{
    T m_array[N];
public:
    int getsize(){
        return N;
    }
};

int main(){
    print(2);
    print<int>(5);
    print(std::string("Sameer"));
    print<float>(5.57f);
    player<int,5> p1;
    print(p1.getsize());
    player<std::string, 50> p2;
    print(p2.getsize());
}