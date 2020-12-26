#include <iostream>
#include <vector>
#include <functional>

void foreach(const std::vector<int>& values, const std::function<void(int)>& func){
    for(int i=0;i<values.size();i++){
        func(values[i]);
    }
}
bool isOdd(int a){
    return (!a%2==0);
}
int main(){
    std::vector<int> values = {1,2,4,6,7};
    int a=1;
    auto lambda = [](int value){std::cout<<"Value: "<<value<<std::endl;};
    foreach(values,lambda);
    std::cout<<"---------------"<<std::endl;
    foreach(values,[&](int value){std:: cout<<"Value: "<<value+a<<std::endl;a++;});
    std::cout<<"---------------"<<std::endl;
    auto it1 = std::find_if(values.begin(),values.end(),isOdd);
    std::cout<<*it1<<std::endl;
    auto it = std::find_if(values.begin(),values.end(),[](int val){return val>3;});
    std::cout<<*it<<std::endl;
}
