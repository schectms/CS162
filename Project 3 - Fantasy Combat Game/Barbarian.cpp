#include "Barbarian.hpp"

Barbarian::Barbarian() : Character()
{
	strengthPoints = 12;
	armor = 0;
	attackMin = 2;
	attackMax = 12;
	defenseMin = 2;
	defenseMax = 12;
}

std::string Barbarian::getType()
{
	return "Barbarian";
}
