#include <iostream>
#include <chrono>

struct Timer{
    std::chrono::time_point<std::chrono::steady_clock> start, end; //= std::chrono::high_resolution_clock::now();
    std::chrono::duration<float> duration;
    Timer(){
        start = std::chrono::high_resolution_clock::now();
    }
    ~Timer(){
        end = std::chrono::high_resolution_clock::now();
        duration = end - start;
        float duration_ms = duration.count() * 1000.0f;
        std::cout<<"that took "<<duration_ms<<" misliseconds"<<std::endl;
    }
};


void Function(){
    Timer timer;
    for(int i=0;i<1000;i++){
        std::cout<<"Hello Sameer\n";
    }
}

int main(){
    Function();
}