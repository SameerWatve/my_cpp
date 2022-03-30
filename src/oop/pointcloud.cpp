#include <iostream>
#include <unordered_map>

class PointCloud {
public:
  virtual void print() { std::cout << "type: 0 " << x << y << z; }
  int x = 2, y = 3, z = 4;
};

class PointCloud1 : public PointCloud {
public:
  virtual void print() override {
    std::cout << "type: 1 " << x << y << z << intensity << std::endl;
  }
  int intensity = 10;
};

class PointCloud2 : public PointCloud {
public:
  virtual void print() override {
    std::cout << "type: 2 " << x << y << z << r << g << b << std::endl;
  }
  int r = 1, g = 1, b = 1;
};

class pointCloudLib {
public:
  int add(PointCloud *pt) {
    _count++;
    _data[_count] = pt;
    return _count;
  }
  PointCloud* remove(int id) {
    if (_data.find(id) == _data.end()) {
      throw std::invalid_argument("id not in data");
    }
    auto res = _data[id];
    _data.erase(id);
    return res;
  }
  void Serialze() const {
    for (auto it : _data) {
        std::cout << "id: " << it.first << " ";
      it.second->print();
    }
  }

private:
  int _count = 0;
  std::unordered_map<int, PointCloud *> _data;
};

int main() {
  pointCloudLib pts;
  PointCloud *pt1 = new PointCloud;
  PointCloud *pt2 = new PointCloud1;
  PointCloud *pt3 = new PointCloud2;
  std::cout << pts.add(pt1) << std::endl;
  std::cout << pts.add(pt2) << std::endl;
  std::cout << pts.add(pt3) << std::endl;
  std::cout << std::endl;
  pts.Serialze();
  std::cout << std::endl;
  std::cout << std::endl;
  auto *pt = pts.remove(2);
  pt->print();
  std::cout << std::endl;
  pts.Serialze();
  std::cout << std::endl;
  delete pt1;
  delete pt2;
  delete pt3;
}