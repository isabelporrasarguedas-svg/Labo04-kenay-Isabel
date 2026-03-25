#include "Squad.h"

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
	return 0.0f;
}

void Squad::showSquad() const
{
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
