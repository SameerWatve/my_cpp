// eager
class Singleton
{
public:
  static Singleton *getInstance()
  {
    return &_instance;
  }

private:
  static Singleton _instance;
  Singleton() {}
  Singleton(const Singleton &) = delete;
  Singleton &operator=(const Singleton &) = delete;
};

Singleton Singleton::_instance;


// lazy
class LazySingleton
{
public:
  static LazySingleton *getInstance()
  {
    static LazySingleton instance;
    return &instance;
  }

private:
  LazySingleton() {}
  LazySingleton(const LazySingleton &) = delete;
  LazySingleton &operator=(const LazySingleton &) = delete;
};
int main()
{
  Singleton *p1 = Singleton::getInstance();
  Singleton *p2 = Singleton::getInstance();
  Singleton *p3 = Singleton::getInstance();
  LazySingleton *p4 = LazySingleton::getInstance();
  LazySingleton *p5 = LazySingleton::getInstance();
}