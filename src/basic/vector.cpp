#include <iostream>
#include <vector>

class Vertex{
    float x,y,z;
public:
    Vertex(float x,float y, float z)
        :x(x),y(y),z(z){}
    Vertex(const Vertex& other)
        :x(other.x),y(other.y),z(other.z){
            std::cout<<"copied!"<<std::endl;
        }
};

int main(){
    std::vector<Vertex> v;
    v.reserve(2);
    //v.push_back(Vertex(1,2,3));
    //v.push_back(Vertex(4,5,6));
    v.emplace_back(1,2,3);
    v.emplace_back(4,5,6);
}