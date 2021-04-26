#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

vector<int> primesum(int A) {
    vector<int> prime;
    for(int i=2;i<A+1;i++){
        int n = sqrt(i)+1;
        bool p = true;
        for(int j=2;j<n;j++){
            if(i%j==0){
                p = false;
                break;
            }
        }
        if(p) prime.push_back(i);
    }
    vector<int>ans;
    for(int i =0;i<prime.size();i++){
        if(find(prime.begin(),prime.end(),A-prime[i])!=prime.end()){
            ans.push_back(prime[i]);
            ans.push_back(A-prime[i]);
            break;
        }
    }
    return ans;
}

vector<int> prime(int A) {
    vector<int> prime;
    for(int i=2;i<A+1;i++){
        int n = sqrt(i)+1;
        bool p = true;
        for(int j=2;j<n;j++){
            if(i%j==0){
                p = false;
                break;
            }
        }
        if(p) prime.push_back(i);
    }
    return prime;
}

int main()
{
    vector<int> ans = prime(15);
    vector<int> ans1 = primesum(15);
    for(auto i: ans){
        cout<<i<<" ";
    }
    cout<<endl;
    for(auto i: ans1){
        cout<<i<<" ";
    }
    cout<<endl;

}