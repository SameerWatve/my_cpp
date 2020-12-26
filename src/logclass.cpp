#include <iostream>
using namespace std;
class Log{
public:
    enum Level
    {
    loglevelwarning = 0, loglevelerror, loglevelinfo
    };
private:
    Level m_loglevel = loglevelwarning;
public:
    void setlevel(Level i){
        m_loglevel = i;
    }
    void warning(const char* msg){
        if(m_loglevel>=loglevelwarning)
        cout<<msg<<endl;
    }
    void error(const char* msg){
        if(m_loglevel>=loglevelerror)
        cout<<msg<<endl;
    }
    void info(const char* msg){
        if(m_loglevel>=loglevelinfo)
        cout<<msg<<endl;
    }

};

int main(){
    Log log;
    log.setlevel(Log::loglevelwarning);
    log.warning("Hello");
    log.info("hello");
    log.error("HELLO");
}