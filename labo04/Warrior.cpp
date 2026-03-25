#include "Warrior.h"
#include <iostream>
using namespace std;

Warrior::Warrior(string name, string combatClass, int attack, int defense, int health, int maxSkills) {
    if (name.empty()) {
        this->name = "Unknown";
    }
    else {
        this->name = name;
    }

    if (combatClass == "Tank" || combatClass == "Assassin" || combatClass == "Mage" || combatClass == "Support") {
        this->combatClass = combatClass;
    }
    else {
        this->combatClass = "Support";
    }

    if (attack < 1) this->attack = 1;
    else if (attack > 100) this->attack = 100;
    else this->attack = attack;

    if (defense < 1) this->defense = 1;
    else if (defense > 100) this->defense = 100;
    else this->defense = defense;

    if (health < 1) this->health = 1;
    else if (health > 1000) this->health = 1000;
    else this->health = health;

    this->maxSkills = maxSkills;
    this->skillCount = 0;

    skills = new EIF201::Skill* [maxSkills];
}

Warrior::~Warrior() {

    for (int i = 0; i < skillCount; i++) {
        delete skills[i];
    }


    delete[] skills;
}

bool Warrior::learnSkill(string name, string type, int power, int cost) {
    if (skillCount >= maxSkills) {
        return false;
    }

    skills[skillCount] = new EIF201::Skill(name, type, power, cost);
    skillCount++;
    return true;
}

float Warrior::getPower() const {
    float total = attack + defense + (health * 0.1f);

    for (int i = 0; i < skillCount; i++) {
        total += skills[i]->calculateEffect();
    }

    return total;
}

void Warrior::show() const {
    cout << "Name: " << name << endl;
    cout << "Class: " << combatClass << endl;
    cout << "ATK: " << attack << " DEF: " << defense << " HP: " << health << endl;

    cout << "Skills:" << endl;
    for (int i = 0; i < skillCount; i++) {
        cout << "- " << skills[i]->getName()
            << " (" << skills[i]->getDamageType() << ")"
            << " Power: " << skills[i]->getPower()
            << " Cost: " << skills[i]->getEnergyCost()
            << endl;
    }
}

string Warrior::getName() const {
    return name;
}

string Warrior::getClass() const {
    return combatClass;
}