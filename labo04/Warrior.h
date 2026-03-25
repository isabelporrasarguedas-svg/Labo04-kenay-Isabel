#pragma once
#ifndef WARRIOR_H
#define WARRIOR_
#include <string>
#include "Skill.h"
    using namespace std;

    class Warrior {
    private:
        string name;
        string combatClass;
        int attack;
        int defense;
        int health;

        EIF201::Skill** skills;     // arreglo dinámico de punteros a Skill
        int skillCount;
        int maxSkills;

    public:
        // Constructor
        Warrior(string name, string combatClass, int attack, int defense, int health, int maxSkills);

        // Destructor
        ~Warrior();

        // Métodos
        bool learnSkill(string name, string type, int power, int cost);
        float getPower() const;
        void show() const;

        // Getters
        string getName() const;
        string getClass() const;
    };

#endif




