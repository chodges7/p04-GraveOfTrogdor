#include"character.h"
#include<iostream>
#include<string>

using namespace std

void stats(){
	cout << "\nYou have:\n " << health << " health\n ";
	cout << attack << " attack\n " << speed << " speed\n ";
	cout << gold << " gold\n";
}

void createCharacter(string name){
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
			attack 3;
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
