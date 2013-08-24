/*
TODO:
-----
Fix maximum values such as feeding
Implement healing through time
Implement a function to save progress

*/
#include <iostream>
#include "stdio.h"
#include <string>

#include "Pet.h"

using namespace std;

int _tmain(int argc, _TCHAR* argv[]){
	cout << "Welcome to Pet Simulator v1.0!\n";
	cout << "What would you like your pet to be named? ";

	string name;
	getline(cin, name);

	cout << "What type of pet would you like to have? ";
	
	string type;
	getline(cin, type);

	Pet pet = Pet(45, 45, 10, 1, 1, name, type, 15, 25, false);

	cout << pet.name << " the " << pet.type << ". Nice choice!\n";

	cout << "Type \"help\" if you need help at any time.\n";

	string input;
	int jobCounter = 0; //incremented every time a command is run
	int cmdCounter = 1;

	while(!pet.dead){
		cout << "> ";

		getline(cin, input);

		//there must be a prettier way to do this...
		if(input == "eat"){
			cout << "amount: ";
			getline(cin, input);

			int amount = atoi(input.c_str());

			pet.eat(amount);

			cmdCounter++;
		}

		if(input == "play"){
			cout << "time: ";
			getline(cin, input);

			int time = atoi(input.c_str());

			pet.play(time);

			cmdCounter++;
		}

		if(input == "pet"){
			cout << "times: ";
			getline(cin, input);

			int times = atoi(input.c_str());

			pet.pet(times);
			
			cmdCounter++;
		}

		if(input == "bathe"){
			pet.bathe();
			
			cmdCounter++;
		}

		if(input == "buy"){
			string temp;
			
			cout << "what to buy: ";
			getline(cin, input);

			cout << "\nhow much: ";
			getline(cin, temp);
			int tempint = atoi(temp.c_str());

			pet.buy(input, tempint);
			
			cmdCounter++;
		}

		if(input == "hurt"){
			cout << "Why would you do that to poor " << name << "?";
			pet.hurt();
			
			cmdCounter++;
		}

		if(input == "kill"){
			cout << "Message from all pet owners: I hate you.\n"; //haha
			pet.dead = true;
		}

		if(input == "stats"){
			pet.stats();
			
			cmdCounter++;
		}

		if(input == "exit"){
			cout << "You will lose any progress made. Are you sure? (y/n) ";
			getline(cin, input);

			if(input == "y"){
				cout << "Thanks for playing!\n";
				break;
			}

			else{
				continue;
			}
		}

		if(input == "help"){} //maybe later... C:

		jobCounter++;
		
		if(jobCounter == 5){
			cout << "You have earned 15 GP.\n";
			pet.inventory.money += 15;
			
			jobCounter = 0;
		}

		if(cmdCounter >= 3){
			if(pet.hunger == 0){
				pet.hurt();
			}
			
			if(pet.hunger != 0){
				pet.hunger -= 0.5;
			}
			
			cmdCounter = 1;
		}

		input = ""; //reset input after a command has been run
	}

	system("pause");
	return 0;
}

