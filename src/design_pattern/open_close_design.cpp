#include <iostream>
#include <vector>
#include <string>

enum class Color {Red, Green, Blue};
enum class Size {Small, Med, Large};

struct Product
{
    std::string name;
    Color color;
    Size size;
};

template <typename T> 
struct Ispecification
{
    virtual bool is_valid(T* item) = 0;
};

template <typename T> 
struct IFilter
{
    virtual std::vector<T*> filter(const std::vector<T*>& items, Ispecification<T>& spec) = 0;
};

struct betterfilter: public IFilter<Product>
{
    std::vector<Product*> filter(const std::vector<Product*>& items, Ispecification<Product>& spec) override{
        std::vector<Product*> res;
        for(auto& i: items){
            if(spec.is_valid(i)){
                res.push_back(i);
            }
        }
        return res;
    }
};

template<typename T>
struct Andspec: public Ispecification<T>{
    Ispecification<T>& spec1;
    Ispecification<T>& spec2;
    Andspec(Ispecification<T>& one,Ispecification<T>& two): spec1(one), spec2(two){}
    bool is_valid(Product* item) override{
        return spec1.is_valid(item) && spec2.is_valid(item);
    }
};

struct Colorspec: public Ispecification<Product>{
    Color color;
    Colorspec(const Color& c): color(c){}
    bool is_valid(Product* item)override{
        return item->color == color;
    }
};

struct Sizespec: public Ispecification<Product>{
    Size size;
    Sizespec(const Size& s): size(s){}
    bool is_valid(Product* item) override{
        return item->size == size;
    }
};
 int main()
 {
    Product apple{"Apple", Color::Red, Size::Small};
    Product tree{"Tree", Color::Green, Size::Large};
    Product house{"House",Color::Red, Size::Large};

    std::vector<Product*> all = {&apple, &tree, &house};
    betterfilter bf;
    Colorspec red_things(Color::Red);
    auto res1 = bf.filter(all, red_things);
    for(auto& i: res1){
        std::cout<<i->name<<" is red"<<std::endl;
    }
    Sizespec small_things(Size::Large);
    auto res2 = bf.filter(all, small_things);
    for(auto& i: res2){
        std::cout<<i->name<<" is large"<<std::endl;
    }
    Andspec<Product> large_and_red{red_things, small_things};
    auto res3 = bf.filter(all, large_and_red);
    for(auto& i: res3){
        std::cout<<i->name<<" is large and red"<<std::endl;
    }
 }
