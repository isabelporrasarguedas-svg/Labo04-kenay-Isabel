#include "Squad.h"
#include<iostream>

Warrior* Squad::recruit(string name, string cls, int atk, int def, int hp, int maxSkills)
{
	return nullptr;
}

bool Squad::dismiss(string name)
{
	return false;
}

float Squad::totalPower() const
{
    float total = 0.0f;

    for (int i = 0; i < count; i++)
    {
        total += warriors[i]->getPower();
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
	return 0;
}

string Squad::getName() const
{
	return string();
}

Warrior** Squad::getByClass(string cls, int& resultCount) const
{
	return nullptr;
}

void Squad::sortByPower()
{
}

string Squad::simulateBattle(const Squad& enemy) const
{
	return string();
}
