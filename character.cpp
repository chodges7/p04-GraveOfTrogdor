#include"character.h"
#include<iostream>
#include<string>

using namespace std;

int character::attackOut(){
	return attack;
}

int character::healthOut(){
	return health;
}

int character::speedOut(){
	return speed;
}

bool character::healthCheck(int check){
	if (health > check){
		return false;
	}
	else {
		return true;
	}
}

//A function that outputs the gold amount
int character::outGold(){
	return gold;
}

//Function to see if a player passes a speed check
bool character::speedCheck(int check){
	if (speed >= check){
		return true;
	}
	else {
		return false;
	}
}

void character::setSpeed(int delta){
	speed += delta;
}

void character::setAttack(int delta){
	attack += delta;
}

//This function checks if the player has enough gold to buy something
bool character::goldCheck(int check){
	if (gold >= check){
		return true;
	}
	else {
		return false;
	}
}

void character::setHealth(int delta){
	//This accounts for both losing and gaining health because if delta if +
	// then there is a gain in health and if health is - then there is a 
	// decrease in health	

	if (delta > 0){
		int temp = health;
		health += delta;
		if (health > 20){
			health = 20;
		}
		cout << "You gained " << health - temp << " health.\n";
	}
	else if (delta < 0){
		int temp = health;
		health += delta;
		cout << "You lost " << temp - health << " health.\n";
	}
}

void character::setGold(int delta){
	gold += delta;
}

void character::stats(){
	cout << "\nYou have:\n " << health << " health\n ";
	cout << attack << " attack\n " << speed << " speed\n ";
	cout << gold << " gold\n";
}

void character::createCharacter(string name){
	int input;
	bool done = false;

	cout << "\nWhat class would you like?\n--------------------------\n";
	cout << "(1)Fighter (5 atk 5 spd 10 hp)\n(2)Knight (7 atk 3 spd 10 hp)\n(3)Rouge (3 atk 7 spd 10 hp)\n\n";
	do {
		cin >> input;
		if (input == 1){
			health = 10;
			speed = 5;
			attack = 5;
			gold = 15;
			cout << "Welcome " << name << " the fighter\n";
			done = true;
		}
		else if (input == 2){
			health = 10;
			speed = 3;
			attack = 7;
			gold = 15;
			cout << "Welcome " << name << " the knight\n";
			done = true;
		}
		else if (input == 3){
			health = 10;
			speed = 7;
			attack = 3;
			gold = 15;
			cout << "Welcome " << name << " the rouge\n";
			done = true;
		}
		else {
			cerr << "Please enter a valid selection.\n";
		}
	}
	while (done != true);
}
