#include <vector>
#include <iostream>

int fib_itr(int n){
    int a=0;
    int b =1;
    int c = a + b;
    for(int i=3;i<n+1;++i){
        a = b;
        b = c;
        c = a + b;
    }
    return c;
}

int fib_rec(int n){
    if(n==0)
        return 0;
    else if(n==1)
        return 1;
    else
        return fib_rec(n-1) + fib_rec(n-2);
}

std::vector<int> mem(100,-1);
int fib_mem(int n){
    if(n==0)
        mem[n] = 0;
    else if(n==1)
        mem[n] = 1;
    else if(mem[n] == -1)
        mem[n] = fib_mem(n-1) + fib_mem(n-2);
    return mem[n];

}

int main(){
    std::cout<<fib_itr(7)<<" "<<fib_rec(7)<<" "<<fib_mem(7)<<std::endl;
    std::cout<<fib_itr(20)<<" "<<fib_rec(20)<<" "<<fib_mem(20)<<std::endl;
}