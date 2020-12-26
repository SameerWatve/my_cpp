#include <iostream>
//#include "common.h"
//#include "log.h"
void log(const char* word);
using namespace std;
void increment(int& a){
    a++;
}
extern int t;
int main(){
    log("Hello!");
    log("hi");
    std::cin.get();
    std::cout<<"Sam"<<std::endl;
    int a = 5;
    increment(a);
    int* b = &a;
    int& ref = a;
    cout<<t<<endl;
    cout<<*b<<endl;
    cout<<ref<<endl;
    
}