#include <iostream>
using namespace std;
class Hero {
public:
// 在此处补充你的代码
    void attack() { cout << "Hero::attack()" << endl; }
    virtual void defense() { cout << "Hero::defense()" << endl; } 
};
class Priest: public Hero {
public:
    virtual void attack() { cout << "Priest::attack()" << endl; }
    virtual void defense() { cout << "Priest::defense()" << endl; } 
}; 

int main() {
    Priest anduin;
    Hero h;
    h.defense();
    Hero *player = &anduin;
    player->attack();
    //Hero::attack()
    player->defense();
    //Priest::defense()
    anduin.attack();
    //Priest::attack()
    anduin.defense();
    //Priest::defense()
    return 0;
}