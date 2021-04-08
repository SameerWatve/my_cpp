# include <chrono>
# include <thread>
# include <iostream>
void kitchen_cleaner(){
    while(true){
    std::cout<<"kitchen is cleaned!"<<std::endl;
    std::this_thread::sleep_for(std::chrono::seconds(2));
    }    
}
void soup_maker(){
    std::this_thread::sleep_for(std::chrono::microseconds(10));
    std::cout<<"chopped!"<<std::endl;
    std::this_thread::sleep_for(std::chrono::seconds(2));
    std::cout<<"boiled!"<<std::endl;
    std::this_thread::sleep_for(std::chrono::seconds(2));
    std::cout<<"served!"<<std::endl;
    std::this_thread::sleep_for(std::chrono::seconds(1));
}

int main(){
    std::cout<<"main thread"<<std::endl;
    std::thread cleaner(kitchen_cleaner);
    cleaner.detach();
    for(int i=0;i<3;i++){
        std::this_thread::sleep_for(std::chrono::seconds(1));
        std::thread cook(soup_maker);
        std::cout<<"cooking order number: "<<i<<std::endl; 
        cook.join();
    }
    std::cout<<"main has finished"<<std::endl;
}