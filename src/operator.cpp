#include <iostream>
using namespace std;
struct Vector2{
    float x, y;
    Vector2(float x, float y)
        : x(x),y(y){}
    Vector2 operator+(const Vector2& other) const
    {
        return Vector2(x + other.x, y+ other.y);
    }
    Vector2 operator*(const Vector2& other) const
    {
        return Vector2(x * other.x, y * other.y);
    }
    bool operator==(const Vector2& other) const
    {
        return (x==other.x && y==other.y);
    }
};

ostream& operator<<(ostream& stream, const Vector2& v){
    stream << v.x << ","<< v.y;
    return stream;
}

int main(){
    Vector2 position(0.25f, 0.33f);
    Vector2 speed(0.5f, 0.46f);
    Vector2 powerup(1.2f,1.1f);
    Vector2 final = position + speed * powerup;
    cout<<position + speed<<endl;
    cout<<final<< endl;
}