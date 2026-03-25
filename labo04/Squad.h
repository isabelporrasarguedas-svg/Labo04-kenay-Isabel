#ifndef SQUAD_H
#define SQUAD_H

#include <string>
#include "Warrior.h"
using namespace std;

class Squad {
private:
    string name;
    Warrior** warriors; 
    int capacity;
    int count;

    
    void expand();

public:
   
    Squad(string name, int capacity);

    
    ~Squad();

    
    Warrior* recruit(string name, string cls, int atk, int def, int hp, int maxSkills);
    bool dismiss(string name);
    float totalPower() const;
    void showSquad() const;

    int getCount() const;
    string getName() const;

  
    Warrior** getByClass(string cls, int& resultCount) const;
    void sortByPower();
    string simulateBattle(const Squad& enemy) const;
};

#endif
