#ifndef __Pet__
#define __Pet__

#include <string>

class Pet{
public:
	//pet's attributes (you can't set a variable inside a class... you have to use a constructorf)
	bool dead;
	int health;
	double happiness; //higher
	double hunger; //higher
	int age;
	int cleanliness; //lower
	std::string name;
	std::string type;

	//items in inventory
	struct inventory{
		int food;
		int money;
		//maybe some more later...
	}inventory;

	//pet's functions
	void eat(int amount);
	void play(int time);
	void pet(int times);
	void bathe();
	void buy(std::string item, int quantity);
	void stats();

	//attribute changing functions
	void hurt();
	

	//wow... this is a lot...
	Pet(double happiness_, double hunger_, int weight_, int age_, int cleanliness_,
		std::string name_, std::string type__, int food_, int money_, bool dead_);

};


#endif