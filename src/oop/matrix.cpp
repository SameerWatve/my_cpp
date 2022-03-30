#include <vector>
#include <iostream>

template<typename T>
class Matrix
{
public:
  Matrix(unsigned int rows, unsigned int cols) : _rows(rows), _cols(cols)
  {
    if (rows == 0 || cols == 0) {
      throw std::invalid_argument("Matrix constructor has 0 size");
    }
    _data = std::vector<T>(_rows * _cols, 0);
  }

  T &operator()(unsigned int row, unsigned int col)
  {
    if (row >= _rows || col >= _cols) {
      throw std::invalid_argument("trying to access out of bounds");
    }
    return _data.at(_cols * row + col);
  }

  // getters
  T operator()(unsigned int row, unsigned int col) const
  {
    if (row >= _rows || col >= _cols) {
      throw std::invalid_argument("trying to access out of bounds");
    }
    return _data.at(_cols * row + col);
  }
  int size() const { return _rows * _cols; }
  int rows() const { return _rows; }
  int cols() const { return _cols; }

private:
  unsigned int _rows;
  unsigned int _cols;
  std::vector<int> _data;
};

int main()
{
  Matrix<int> m(3, 3);
  int i = 0;
  for (int x = 0; x < 3; ++x) {
    for (int y = 0; y < 3; ++y, ++i) {
      m(x, y) = i;
    }
  }
  m(2,2) = 1000;
  for (int x = 0; x < 3; ++x) {
    for (int y = 0; y < 3; ++y) {
      std::cout << "@(" << x << ", " << y << ") : " << m(x, y) << " ";
    }
    std::cout << std::endl;
  }
  std::cout << m(4,4);

}