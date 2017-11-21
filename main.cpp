#include<iostream>
#include<fstream>
#include<vector>
#include<string>
#include<ctime>
#include<cstdlib>

using namespace std;

//Classes
class character{
	public:
		int health;
		int speed;
		int attack;
		int gold;
};
class Monster{
	public:
		static void bunny(Monster &);
		static void scorpion(Monster &);
		static void troll(Monster &);
	public:
		int health;
		int attack;
		int speed;
		int gold;
};

Monster current;

//Prototypes
void mainMenu(char &);
void runGame();
character createCharacter(string, character &);
int randomNumber(unsigned int, unsigned int);
void menu(int &locate, character &, vector <string> &, vector <string> &);
void go(int &locate);
void use(bool &, character &, vector <string> &);
void list(vector <string> );
void fight(Monster &current, character &, vector <string> &);
void stats(character);
void shop(character &, vector <string> &, int &);

bool gameWon = false;

int main(){
	//Seed the random number generator
	srand( time(NULL));
	char input;
	string name;
	character player;
	vector <string> inventory;
	vector <string> shopkeep;

	//Locator value so the program knows where the player is
	int locate = 0;

	shopkeep.push_back("ironarmor");
	shopkeep.push_back("steelarmor");
	shopkeep.push_back("ironsword");
	shopkeep.push_back("steelsword");

	//Menu to get started
	mainMenu(input);
	if (input == 'q' || input == 'Q'){
		return 0;
	}


	//Name for the player
	cout << "\nPlease enter a character name:";
	cin >> name;

	//This function creates the object used for battling
	createCharacter(name, player);

	//Let the game begin
	do {
		menu(locate, player, inventory, shopkeep);
	}
	while (gameWon != true);
	return 0;
}

void shop(character &player, vector <string> &shopkeep, int &locate){
	int ironarmor = 0;
	int steelarmor = 0;
	int ironsword = 0;
	int steelsword = 0;
	int again;
	string input;

	cout << "I have many things to sell.\n--------------------------\nPotions - 15g\nHomeward Bones - 10g\n";
	for (int index = 0; index < shopkeep.size(); index++){
		if (shopkeep[index] == "ironarmor"){
			ironarmor += 1;
		}
		if (shopkeep[index] == "steelarmor"){
			steelarmor += 1;
		}
		if (shopkeep[index] == "ironsword"){
			ironsword += 1;
		}
		if (shopkeep[index] == "steelsword"){
			steelsword += 1;
		}
	} 
	cout << ironarmor << " set(s) of iron armor - 50g\n" << steelarmor << " set(s) of steel armor - 100g\n";
	cout << ironsword << " iron sword(s) - 50g\n" << steelsword << " steel sword(s) - 100g\n";
	cout << "\nWhat would you like to buy? ";
	cin >> input;

	cout << "Would you like to buy something else?\n";
	cout << "1) Yes\n2) No\n";
	cin >> again;

	if (again == 1){
		return ;
	}
	if (again == 2){
		locate = 0;
		return ;
	}
}

void menu (int &locate, character &player, vector <string> &inventory, vector <string> &shopkeep){
	string input;

	//Town
	if (locate == 0){
		cout << "You're in the town. What will you do? ";
		cin >> input;
		if (input == "go" || input == "GO"){
			go(locate);
		}
		else if (input == "list" || input == "LIST"){
			list(inventory); 
		}
		else if (input == "stats" || input == "STATS"){
			stats(player);
		}
	}
	//Shop
	else if (locate == 1){
		shop (player, shopkeep, locate);	
		return ;        
	}
	//Forest
	else if (locate == 2){
		cout << "You are in the forest. A bunny appears!\n";
		Monster::bunny(current); 
		fight(current, player, inventory);
		locate = 0;
	}
	//Desert
	else if (locate == 3){
		cout << "You are in the desert. A scorpion appears!\n";
		Monster::scorpion(current);
		fight(current, player, inventory); 
		locate = 0;
	}
	//Mountains
	else if (locate == 4){
		cout << "You are in the mountains. A troll appears!\n";
		Monster::troll(current); 
		fight(current, player, inventory);
		locate = 0;
	}
	//Graveyard
	else if (locate == 5){
		cout << "You are at the graveyard. What will you do? ";
		cin >> input; 
		if (input == "go" || input == "GO"){
			go(locate);
		}
		else if (input == "list" || input == "LIST"){
			list(inventory);
		}
		else if (input == "stats" || input == "STATS"){
			stats(player);
		}
	}
	//End of game tomb
	else if (locate == 6){
		cout << "You are in Trogdor's tomb. You claim the riches! Thank you for playing!\n";
		gameWon = true;	
	}
}

void use(bool &defeated, character &player, vector <string> &inventory){

	int temp;
	int lower = 0;
	int potions = 0;
	int homewordBone = 0;
	string input; 

	for (int index = 0; index < inventory.size(); index++){
		if (inventory[index] == "potion"){
			potions += 1;
		}
		else if (inventory[index] == "homewardbone"){
			homewordBone += 1;
		}
	}

	cout << "What do you want to use? You have:\n" << potions;
	cout << " potions\n" << homewordBone << " homeword bones\n";
	cin >> input;

	if (input == "potion" || input == "POTION"){
		if (potions > 0){
			for (int index = 0; lower < 1; index ++){
				if (inventory[index] == "potion"){
					inventory.erase(inventory.begin() + index);
					lower += 1;
				}
			}
			if (player.health <= 10){
				temp = player.health;
				player.health = 20;
				temp = player.health - temp;
				cout << "You gained " << temp << " health\n";
			}
			else {
				cout << "You gained 5 health\n";
			}
		}
		else {
			cout << "You have no potions.\n";
		}
	}
	else if (input == "homeward bone" || input == "bone"){
		if (homewordBone > 0){
			for (int index = 0; lower < 1; index ++){
				if (inventory[index] == "homewardbone"){
					inventory.erase(inventory.begin() + index);
					lower += 1;
				}
			}
			cout << "You ran away in a flash of smoke\n";
			defeated = true;
		}
		else {
			cout << "You have no bones.\n";
		}
	}

	return ;
}

void fight (Monster &current, character &player, vector <string> &inventory){
	string input;
	bool defeated = false;
	bool turn = true;
	int hit;
	int damage;
	int run;

	do {
		if (turn == true){ 
			cout << "======= FIGHT =======\n";

			cout << "What will you do? ";
			cin >> input;

			if (input == "attack" || input == "ATTACK"){
				hit = randomNumber(1, 10);
				if (hit >= current.speed){
					damage = randomNumber (1,player.attack);
					cout << "You deal " << damage << " damage.\n";
					current.health -= damage; 
					if (current.health <= 0){
						defeated = true;
					}
					turn = false;
				}
				else {
					cout << "You missed\n";
					turn = false;
				}
			}

			else if (input == "run" || input == "RUN"){
				run = randomNumber (1,10);
				if (run <= current.speed){
					cout << "You failed to run away.\n";
					turn = false;
				}		
				else {
					if (player.gold >= 5){
						cout << "You ran away and dropped 5 gold!\n";			
						player.gold -= 5;
						defeated = true;				
					}
					else {
						cout << "You ran away!\n";
						defeated = true;
					}
				}
			}

			else if (input == "use" || input == "USE"){
				use(defeated,player,inventory);
				if (defeated == false){ 
					turn = false;
				}
			}
		}
		if (turn == false){
			hit = randomNumber(1,10);
			if (hit > player.speed){
				damage = randomNumber(1,current.attack);
				cout << "You get hit with " << damage << " damage.\n";
				player.health -= damage;
				if (player.health <= 0){
					defeated = true;
				}
			}
			else if (hit <= player.speed){
				cout << "They missed!\n";
			}
			turn = true;
		}
	}
	while (defeated == false);

	if (current.health <= 0){
		cout << "You have won! Gained " << current.gold << " gold!\n";
		player.gold += current.gold;
	}

	if (player.health <= 0){
		cout << "You have died.\n";
		gameWon = true;
	}
	return ;
}

void stats(character player){
	cout << "\nYou have:\n  " << player.health << " health\n";
	cout << "  " << player.attack << " attack\n  " << player.speed;
	cout << " speed\n  " << player.gold << " gold\n\n";
}

void list(vector <string> inventory){
	if (inventory.size() == 0){
		cout << "Your inventory is currently empty.\n";
		return ;
	}
	else {
		cout << "Your inventory:\n";
		for (int index = 0; index < inventory.size(); index++){
			cout << inventory[index] << endl;
		}
	}
}

void go(int &locate){
	string input;
	cout << "Where would you like to go?\n";
	cin >> input;
	if (input == "north" || input == "NORTH"){
		//Shop is to the north		
		if (locate == 0){ 
			locate = 1;
		}
		else{
			cout << "\nThere is nothing in that direction.\n";
		}
	}
	else if (input == "south" || input == "SOUTH"){
		//Desert to the south		
		if (locate == 0){
			locate = 3;    
		}
		else if (locate == 1){
			locate = 0;
		}
	}
	else if (input == "west" || input == "WEST"){
		//Forest to the west		
		if (locate == 0){
			locate = 2;
		}
	}
	else if (input == "east" || input == "EAST"){
		//Mountains to the east
		locate = 4;
	}
	else if (input == "graveyard" || input == "GRAVEYARD"){
		//Graveyard in town
		locate = 5;
	}

	return ;
}

void Monster::bunny(Monster &current){
	current.health = 5;
	current.attack = 2;
	current.speed = 2;
	current.gold = 10;
	return ;
}

void Monster::scorpion(Monster &current){
	current.health = 15;
	current.attack = 7;
	current.speed = 5;
	current.gold = 20;
	return ;
}

void Monster::troll(Monster &current){
	current.health = 35;
	current.attack = 10;
	current.speed = 5;
	current.gold = 0;
	return ;
}

character createCharacter(string name, character &player){
	int input;
	bool done = false;

	cout << "\nWhat class would you like?\n--------------------------\n";
	cout << "(1)Fighter (5 atk 5 spd 10 hp)\n(2)Knight (7 atk 3 spd 10 hp)\n(3)Rouge (3 atk 7 spd 10 hp)\n\n";
	do {
		cin >> input;
		if (input == 1){
			player.health = 10;
			player.speed = 5;
			player.attack = 5;
			player.gold = 15;
			cout << "Welcome " << name << " the fighter\n";
			done = true;
		}
		else if (input == 2){
			player.health = 10;
			player.speed = 3;
			player.attack = 7;
			player.gold = 15;
			cout << "Welcome " << name << " the knight\n";
			done = true;
		}
		else if (input == 3){
			player.health = 10;
			player.speed = 7;
			player.attack = 3;
			player.gold = 15;
			cout << "Welcome " << name << " the rouge\n";
			done = true;
		}
		else{
			cerr << "Please enter a valid selection\n";
		}
	}
	while (done != true);
	return player;
}

void runGame(){
	cout << "\nIt is nighttime, you're in a graveyard, the full moon illuminates\n";
	cout << "your path, and finally you reach onto Trogdor's tomb. It is a giant\n";
	cout << "structure compared to the rest of the gravestones around you. As you\n";
	cout << "go to walk through the doorway, you realize a giant lock holds the\n";
	cout << "gate shut. If the legend is correct, the key should be being protected\n";
	cout << "in the mountains.\nFor now you can't enter the tomb. Find the key and take what is yours!\n";
}

void mainMenu(char &input){
	string name;

	do{
		cout << "\n======= Grave of Trogdor =======\n";
		cout << "(S)tart\n(I)nstructions\n(L)ore\n(Q)uit\n\n";
		cin >> input;
		if (input == 'i' || input == 'I'){
			cout << "\nSimilar to old fashioned video games, this is a little RPG that takes\n";
			cout << "input commands. Unlike old fashioned video games, you have to enter the\n";
			cout << "seperate words as seperate commands.\nList of possible commands:\n";
			cout << "go north (or any other cardinal direction)\nuse 'item'\nlist\n\nWhile in battle:\nattack\nrun\nuse\nstats\n";
		}
		else if (input == 'l' || input == 'L'){
			cout << "\nYou are a grave robber, and your goal is to rob the grave of Trogdor.\n";
			cout << "In the town of Hesperia Trogdor was a benevolent duke who owed vast\n";
			cout << "amounts of land surrounding the town. Unfortunately for Trogdor, he\n";
			cout << "has no heirs; all of his valubles have been stowed in his tomb. Are you\n";
			cout << "willing to risk everything for a chance at Trogdors riches?\n";
		}
		else if (input == 's' || input == 'S'){
			runGame();
			return ;
		}
		else if (input == 'q' || input == 'Q'){
			cout << "Have a nice day\n";
		}
		else{
			cerr << "Please enter a valid character.\n";
		} 
	}
	while (input != 'q' && input != 'Q');
	return ;
}

int randomNumber(unsigned int min, unsigned int max){
	if (min > max){
		int temp = max;
		max = min;
		min = max;
	}
	return rand() % (max + 1 - min) + min;
}
