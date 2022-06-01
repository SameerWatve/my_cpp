#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

struct point{
  int x;
  int y;
};

struct comp{
   bool operator()(const point &p1, const point &p2){
       return p1.x>p2.x;
   }
};

int main()
{
    vector<point> v;
    v = {{1,2},{1,4},{2,3},{4,1}};
    sort(v.begin(),v.end(),comp());
    priority_queue<point, vector<point>, comp> pq;
    cout << "vector:" << endl;
    for(auto p:v){
        cout << p.x << " " << p.y << endl;
        pq.push(p);
    }
    cout << endl;
    cout << "priority queue:" << endl;
    while(!pq.empty()){
        cout << pq.top().x << " " << pq.top().y << endl;
        pq.pop();
    }
}

// output
// vector:
// 4 1
// 2 3
// 1 2
// 1 4

// priority queue:
// 1 2
// 1 4
// 2 3
// 4 1