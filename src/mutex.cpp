# include <iostream>
# include <thread>
# include <chrono>
# include <mutex>
#include <atomic>

std::atomic<unsigned int> atomic_count(0);
unsigned int count = 0;
std::mutex pencil;
void how_many(){
    for(int i=0;i<1000000;i++){
        pencil.lock();
        count++;
        pencil.unlock();
    }
}

void atomic_how_many(){
    for(int i=0;i<1000000;i++){
        atomic_count++;
    }
}

int main(){
    std::thread first(how_many);
    std::thread second(how_many);
    std::thread third(atomic_how_many);
    std::thread fourth(atomic_how_many);
    first.join();
    second.join();
    third.join();
    fourth.join();
    std::cout<<count<<std::endl;
    std::cout<<atomic_count<<std::endl;
}