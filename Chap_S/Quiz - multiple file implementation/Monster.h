#ifndef MONSTER_H
#define MONSTER_H

#include "Race.h"

#include <string>

extern struct Monster {
	Race race;
	std::string name;
	int health;
};

#endif