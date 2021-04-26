#include <iostream>
#include <array>

template<typename T, int N>
void print(const std::array<T,N>& data){
    for(int i=0;i<N;i++){
        std::cout<<data[i]<<std::endl;
    }
}

int main(){
    std::array<int,3> data;
    data[0] = 1;
    data[1] = 2;
    data[2] = 3;
    print<int,data.size()>(data);
}