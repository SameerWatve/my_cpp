#include <iostream>
#include <string>
#include <memory>

struct Plane{
    std::string _plane_type;
    std::string _body;
    std::string _engine;
    Plane(const std::string& p): _plane_type(p){}
    void setBody(const std::string& b){
        _body = b;
    }
    void setEngine(const std::string& e){
        _engine = e;
    }
    std::string getBody() const{
        return _body;
    }
    std::string getEngine() const{
        return _engine;
    }
    void show() const{
        std::cout<<"Plane type "<<_plane_type<<std::endl;
        std::cout<<"Plane body "<<_body<<std::endl;
        std::cout<<"Plane enfgine "<<_engine<<std::endl;
    }
};

class PlaneBuilder{
protected:
    std::shared_ptr<Plane> p;
public:
    virtual void makePartsDone() = 0;
    virtual void makeBody() = 0;
    virtual void makeEngine() = 0;
    std::shared_ptr<Plane> getPlane() const{
        return p;
    }
};

class JetPlaneBuilder: public PlaneBuilder{
public:
    void makePartsDone() override{
        p = std::make_shared<Plane>("Jet plane");
        std::cout<<"building jet plane"<<std::endl;
    }
    void makeBody() override{
        p->setBody("Jet body");
        std::cout<<"building body of jet plane"<<std::endl;
    }
    void makeEngine() override{
        p->setEngine("Jet engine");
        std::cout<<"building engine of jet plane"<<std::endl;
    }
    
};

class PropellerPlaneBuilder: public PlaneBuilder{
public:
    void makePartsDone() override{
        p = std::make_shared<Plane>("Propeller Plane");
        std::cout<<"building propeller plane"<<std::endl;
    }
    void makeBody() override{
        p->setBody("Propeller body");
        std::cout<<"building body of propeller plane"<<std::endl;
    }
    void makeEngine() override{
        p->setEngine("Propeller engine");
        std::cout<<"building engine of propeller plane"<<std::endl;
    }
    
};

class Director{
public:
    std::shared_ptr<Plane> createPlane(PlaneBuilder* builder){
        builder->makePartsDone();
        builder->makeBody();
        builder->makeEngine();
        return builder->getPlane();
    }
};
int main(){
    JetPlaneBuilder jb;
    PropellerPlaneBuilder pb;
    Director dr;
    auto j = dr.createPlane(&jb);
    auto p = dr.createPlane(&pb);
    j->show();
    p->show();

}