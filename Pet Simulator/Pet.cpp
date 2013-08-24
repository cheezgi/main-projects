#include "Pet.h"
#include <string>
#include <iostream>

Pet::Pet(double happiness_, double hunger_, int weight_, int age_, int cleanliness_, std::string name_, std::string type_, int food_, int money_, bool dead_){
	happiness = happiness_;
	hunger = hunger_;
	age = age_;
	cleanliness = cleanliness_;
	name = name_;
	type = type_;
	dead = dead_;
	health = 100;

	inventory.food = food_;
	inventory.money = money_;
}

void Pet::eat(int amount){
	if(hunger <= 45){
		std::cout << "You feed " << name << ".\n";

		hunger += amount;
		inventory.food -= amount;

		return;
	}
	std::cout << "Your pet is already full!";
}

void Pet::play(int time){
	std::cout << "You play with " << name << ". " << name << " gains some happiness.\n";

	happiness += 1;
}

void Pet::pet(int times){
	std::cout << "You pet " << name << ". " << name << " gains some happiness.\n";

	happiness += 0.2;
}

void Pet::bathe(){
	std::cout << "You bathe " << name << ". " << name << " becomes cleaner.\n";

	cleanliness--;
}

void Pet::buy(std::string item, int quantity){
	if(item == "food"){
		std::cout << "You buy some food.\n";

		inventory.food += quantity;
		inventory.money -= quantity;
	}
	//maybe some more later...
}


//add maximums
//
//
void Pet::stats(){
	std::cout << "dead: ";
	std::cout << dead;
	std::cout << "\n";
	std::cout << "health: ";
	std::cout << health;
	std::cout << "; max: 100";
	std::cout << "\n";
	std::cout << "happiness: ";
	std::cout << happiness;
	std::cout << "\n";
	std::cout << "hunger: ";
	std::cout << hunger;
	std::cout << "; max: 10";
	std::cout << "\n";
	std::cout << "age: ";
	std::cout << age;
	std::cout << "\n";
	std::cout << "cleanliness: ";
	std::cout << cleanliness;
	std::cout << "\n";
	std::cout << "name: " << name << std::endl;
	std::cout << "type: " << type << std::endl << std::endl;

	std::cout << "money: ";
	std::cout << inventory.money;
	std::cout << "\n";
	std::cout << "food: ";
	std::cout << inventory.food;
	std::cout << "\n";
}

void Pet::hurt(){
	std::cout << name << " lost some health and happiness.";

	happiness -= 2;
	health -= 4;
}