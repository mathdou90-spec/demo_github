#include <iostream>
#include <cstdio>
#include <string>
using namespace std;

class Sport {
protected:
    int minutes, level;
public:
    Sport(int minutes, int level):
    minutes(minutes),
    level(level){
    }
    virtual string getDescription() = 0;
    virtual int getSportIntensity() = 0;
    virtual ~Sport() {}  // 添加虚析构函数
};

class SportRun: public Sport {
public:
    SportRun(int m, int l): Sport(m, l) {
    }
    
    string getDescription() override {
        char buffer[100];
        sprintf(buffer, "You're running for %d minute(s)", minutes);
        return string(buffer);
    }
    
    int getSportIntensity() override {
        return (minutes / 10) * level;
    }
};

class SportBicycle: public Sport {
public:
    SportBicycle(int m, int l): Sport(m, l) {
    }
    
    string getDescription() override {
        char buffer[100];
        sprintf(buffer, "You're riding for %d minute(s)", minutes);
        return string(buffer);
    }
    
    int getSportIntensity() override {
        int temp = minutes / 5;
        return temp * temp * level;
    }
};

int main() {
    int op, m, l;
    Sport* sp;
    for(int i = 0; i < 100; i++) {
        cin >> op >> m >> l;
        if(op == 1) sp = new SportRun(m, l);
        else sp = new SportBicycle(m, l);
        cout << sp->getDescription() << endl;
        cout << sp->getSportIntensity() << endl;
        delete sp;
    }
    return 0;
}