#include <iostream>
#include<string>
using namespace std;

class string1{
    char* m_Buffer;
    unsigned int m_size;
public:
    string1(const char* str){
        m_size = strlen(str);
        m_Buffer = new char[m_size];
        memcpy(m_Buffer, str, m_size);
    }
    string1(const string1& other): m_size(other.m_size){
        cout<<"copied!"<<endl;
        m_Buffer = new char[other.m_size+1];
        memcpy(m_Buffer, other.m_Buffer, m_size+1);
    }
    ~string1(){
        delete[] m_Buffer;
    }
    char& operator[](int ind){
        return m_Buffer[ind];
    }
    friend std::ostream& operator<<(std::ostream& stream, const string1& str);
};

std::ostream& operator<<(std::ostream& stream, const string1& str){
    stream << str.m_Buffer;
    return stream;
}
void print(const string1& str){
    cout<<str<<endl;
}
int main(){
    string1 str1 = "Sameer";

    string1 str2 = str1;
    str2[1] = 'e';
    print(str1);
    print(str2);
}