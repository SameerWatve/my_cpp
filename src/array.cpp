#include <iostream>
#include <vector>
#include <bits/stdc++.h> 
using namespace std;
class ent{
int arr[5];
public:
    void setter(){
        for(int i=0;i<5;i++){
            arr[i] = 9;
        }
    }
    void getter(){
        for(int i=0;i<5;i++){
            cout<<arr[i]<<endl;
        }
    }
};
int main(){
    ent e;
    e.setter();
    e.getter();
    vector<int> v{2,5,6,8,9};
    sort(v.begin(),v.end());
}