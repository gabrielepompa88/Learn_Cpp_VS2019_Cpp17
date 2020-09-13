#ifndef MONSTER_H
#define MONSTER_H

#include "Race.h"

#include <string>

struct Monster {
	Race race;
	std::string name;
	int health;
};

#endif