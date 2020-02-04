#include <ctime> // for time()
#include <cstdlib> // for rand() and srand()
#include <iostream>
#include <string>
#include <vector>

class Monster {

	std::string name;
	std::string roar;
	int hitPoints;

public:
	enum class MonsterType {
		DRAGON,
		GOBLIN,
		OGRE,
		ORC,
		SKELETON,
		TROLL,
		VAMPIRE,
		ZOMBIE,
		MAX_MONSTER_TYPES
	};

private:
	MonsterType type;

public:

	Monster(MonsterType monType, std::string monName, std::string monRoar, int monHitPoints) :
		type(monType), name(monName), roar(monRoar), hitPoints(monHitPoints)
	{
	}

	std::string getTypeString(Monster::MonsterType monType) const {

		switch (monType) {
		case Monster::MonsterType::DRAGON:
			return "Dragon";
		case Monster::MonsterType::GOBLIN:
			return "Goblin";
		case Monster::MonsterType::OGRE:
			return "Ogre";
		case Monster::MonsterType::ORC:
			return "Orc";
		case Monster::MonsterType::SKELETON:
			return "Skeleton";
		case Monster::MonsterType::TROLL:
			return "Troll";
		case Monster::MonsterType::VAMPIRE:
			return "Vampire";
		case Monster::MonsterType::ZOMBIE:
			return "Zombie";
		}
	}

	void print() const {
		std::cout << name << " the " << getTypeString(type) << " has " << hitPoints << " hit points and says " << roar << "\n";
	}
};

class MonsterGenerator {

	static const std::vector<std::string> s_names;	
	static const std::vector<std::string> s_roars;

public:

	static const Monster generateMonster() {

		Monster::MonsterType randomType = static_cast<Monster::MonsterType>(MonsterGenerator::getRandomNumber(0, static_cast<int>(Monster::MonsterType::MAX_MONSTER_TYPES) - 1));
		int randomHitPoints = MonsterGenerator::getRandomNumber(1, 100);

		return Monster(randomType, s_names[getRandomNumber(0, 5)], s_roars[getRandomNumber(0, 5)], randomHitPoints);
	}

	// Generate a random number between min and max (inclusive)
	// Assumes srand() has already been called
	static int getRandomNumber(int min, int max)
	{
		static const double fraction = 1.0 / (static_cast<double>(RAND_MAX) + 1.0);  // static used for efficiency, so we only calculate this value once
		// evenly distribute the random number across our range
		return static_cast<int>(rand() * fraction * (max - min + 1) + min);
	}

};

const std::vector<std::string> MonsterGenerator::s_names{ "name1", "name2" , "name3" , "name4" , "name5" , "name6" };
const std::vector<std::string> MonsterGenerator::s_roars{ "roar1", "roar2" , "roar3" , "roar4" , "roar5" , "roar6" };

int main()
{
	Monster skele(Monster::MonsterType::SKELETON, "Bones", "*rattle*", 4);
	skele.print();

	srand(static_cast<unsigned int>(time(0))); // set initial seed value to system clock
	rand(); // If using Visual Studio, discard first random value

	Monster m = MonsterGenerator::generateMonster();
	m.print();

	return 0;
}