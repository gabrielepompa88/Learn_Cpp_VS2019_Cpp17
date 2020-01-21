#include <string>
#include <iostream>

enum class Race {
	OGRE, 
	DRAGON, 
	ORC,
	GIANT_SPIDER,
	SLIME,
};

struct Monster {

	Race race;
	std::string name;
	int health;
};

std::string getMonsterRace(Race race) {

	std::string race_name{};

	switch (race)
	{
	case Race::OGRE:
		race_name = "Ogre";
		break;
	case Race::DRAGON:
		race_name = "Dragon";
		break;
	case Race::ORC:
		race_name = "Orc";
		break;
	case Race::GIANT_SPIDER:
		race_name = "Giant Spider";
		break;
	case Race::SLIME:
		race_name = "Slime";
		break;
	}

	return race_name;
}

void printMonster(Monster monster) {

	std::cout << "This " << getMonsterRace(monster.race) << " is named " << monster.name << " and has " << monster.health << " health points.\n";
}

int main() {

	Monster ogre{ Race::OGRE, "Arturo", 145 };
	Monster slime{ Race::SLIME, "Blurp", 23 };

	printMonster(ogre);
	printMonster(slime);

}