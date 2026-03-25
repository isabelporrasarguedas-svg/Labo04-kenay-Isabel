#include "Squad.h"
#include<iostream>

Warrior* Squad::recruit(string name, string cls, int atk, int def, int hp, int maxSkills)
{
    Warrior* newWarrior = new Warrior(name, cls, atk, def, hp, maxSkills);

    if (count >= capacity) {
        expand();
    }

    warriors[count++] = newWarrior;
    return newWarrior;
}

void Squad::expand()
{
    int quantity = capacity;
    int nuevaCapacidad = capacity * 2;
    Warrior** nuevoArray = new Warrior * [nuevaCapacidad];

    for (int i = 0; i < quantity; i++) {
        nuevoArray[i] = warriors[i];
    }

    for (int i = quantity; i < nuevaCapacidad; i++) {
        nuevoArray[i] = nullptr;
    }

    delete[] warriors;

    warriors = nuevoArray;
    capacity = nuevaCapacidad;
}

Squad::Squad(string name, int capacity) : name(name), capacity(capacity) {
    this->count = 0; // Inicializar en 0
    this->warriors = new Warrior*[capacity]; // Crear el arreglo dinámico
    for (int i = 0; i < capacity; i++) {
        warriors[i] = nullptr; // Limpiar punteros
    }
}
Squad::~Squad() {
    for (int i = 0; i < count; i++) {
        delete warriors[i]; // Borra cada guerrero
    }
    delete[] warriors; // Borra el arreglo de punteros
}
bool Squad::dismiss(string name)
{
    for (int i = 0; i < count; i++) {
        if (warriors[i] && warriors[i]->getName() == name) {
            delete warriors[i];
            // shift left
            for (int j = i; j < count - 1; j++) warriors[j] = warriors[j + 1];
            warriors[count - 1] = nullptr;
            count--;
            return true;
        }
    }
    return false;
}

float Squad::totalPower() const {
    float total = 0;
    for (int i = 0; i < count; i++) {
        if (warriors[i]) {
            total += warriors[i]->getPower(); 
        }
    }
    return total;
}
void Squad::showSquad() const

{
    cout << "-----------------------------" << endl;
    cout << "=========== SQUAD ===========" << endl;
    cout << "-----------------------------" << endl;
    cout << "Name: " << name << endl;
    cout << "Warriors: " << count << endl;

    cout << "\n--- Warrior List ---" << endl;

    for (int i = 0; i < count; i++)
    {
        cout << "\nWarrior #" << (i + 1) << endl;
        warriors[i]->show();
    }

    cout << "\n----------------" << endl;
    cout << "Total Power: " << totalPower() << endl;
    cout << "-----------------------------" << endl;
    cout << "=========== FINISH ===========" << endl;
    cout << "-----------------------------" << endl;
}

int Squad::getCount() const
{
    return count;
}

string Squad::getName() const
{
    return name;
}
Warrior** Squad::getByClass(string cls, int& resultCount) const
{
    resultCount = 0;
    for (int i = 0; i < count; i++) {
        if (warriors[i] && warriors[i]->getClass() == cls) resultCount++;
    }

    if (resultCount == 0) return nullptr;

    Warrior** result = new Warrior * [resultCount];
    int idx = 0;
    for (int i = 0; i < count; i++) {
        if (warriors[i] && warriors[i]->getClass() == cls) {
            result[idx++] = warriors[i];
        }
    }
    return result;
}

void Squad::sortByPower()
{
    // Simple selection sort by power (descending)
    for (int i = 0; i < count - 1; i++) {
        int best = i;
        for (int j = i + 1; j < count; j++) {
            if (warriors[j] && warriors[best]) {
                if (warriors[j]->getPower() > warriors[best]->getPower()) {
                    best = j;
                }
            }
            else if (warriors[j] && !warriors[best]) {
                best = j;
            }
        }
        if (best != i) {
            Warrior* tmp = warriors[i];
            warriors[i] = warriors[best];
            warriors[best] = tmp;
        }
    }
}

string Squad::simulateBattle(const Squad& enemy) const
{
    float myPower = totalPower();
    float enemyPower = enemy.totalPower();
    if (myPower > enemyPower) return name;
    if (enemyPower > myPower) return enemy.getName();
    return string("Draw");
}
