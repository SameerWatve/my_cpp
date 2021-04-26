#include<iostream>
#include<vector>
using namespace std;
int repeatedNumber(const vector<int> &A) {
    int n = A.size();
    vector<int>B(1000,0);
    int i;
    for(i=0;i<A.size();i++)
    {
        cout<<A[i]<<" "<<B.size()<<" "<<B[A[i]]<<endl;
        B[A[i]]++;
        if( B[ A[i] ] >1)
        return A[i];
    }
return -1;
}
int main(){
    vector<int>A(1,0);
    A.push_back(11);
    A.push_back(2);
    A.push_back(2);
    A.push_back(9);
    int B[5]={1};
    //cout<<A[1500]<<endl;
    //A[1900]++;
    for(int i=0;i<A.size();i++){
        cout<<A[i]<<endl;
    }
    //A[1900]++;
    //cout<<++A[1900]<<endl;
    cout<<repeatedNumber(A)<<endl;
}