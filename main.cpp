#include<iostream>
#include<fstream>
#include<vector>
#include<string>
#include<ctime>
#include<cstdlib>
#include "character.h"
#include "Monster.h"

using namespace std;

//Prototypes
int randomNumber(unsigned int, unsigned int);
void mainMenu(char &);
void runGame();
void menu(int &locate, vector <string> &, vector <string> &);
void go(int &locate);
void use(bool &, vector <string> &);
void list(vector <string> );
void fight(vector <string> &);
void shop(vector <string> &, int &, vector <string> &);
void townUse(vector <string> &);

//Bool to track when the game is won
bool gameWon = false;
character player;
Monster current;


int main(){
	//Seed the random number generator
	srand( time(NULL));
	char input;
	string name;
	vector <string> inventory;
	vector <string> shopkeep;

	//Locator value so the program knows where the player is
	int locate = 0;

	//Gives shopkeeper all the armor and swords to sell
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

	//This function creates the player object
	player.createCharacter(name);

	//Let the game begin
	do {
		menu(locate, inventory, shopkeep);
	}
	while (gameWon != true);
	return 0;
}

void fight (vector <string> &inventory){
	return ;
}

/*
void fight (vector <string> &inventory){
	string input;
	bool defeated = false;
	bool turn = true;
	int hit;
	int damage;
	int run;

	do {
		if (turn == false){
			hit = randomNumber(1,10);
			if (player.speedCheck(hit)){
				damage = randomNumber(1,current.attack);
				cout << "You get hit with " << damage << " damage.\n";
				player.setHealth(-damage);
				if (player.health <= 0){
					defeated = true;
				}
			}
			else if (hit <= player.speed){
				cout << "They missed!\n";
			}
			turn = true;
		}
		if (turn == true){ 
			cout << "======= FIGHT =======";
			cout << "     You have " << player.health << " hp\n";
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
				use(defeated,inventory);
				if (defeated == false){ 
					turn = false;
				}
			}
		}
	}
	while (defeated == false);

	if (current.health <= 0){
		cout << "You have won! Gained " << current.gold << " gold!\n";
		player.gold += current.gold;
	}

	if (current.health <= 0 && current.attack == 7){
		cout << "The troll drops the key.\n";
		inventory.push_back("key");		
	}

	if (player.health <= 0){
		cout << "You have died.\n";
		gameWon = true;
	}
	return ;
}
*/

//Allows player to use potions while outside of combat
//See Use() for comments; townuse() is comprised of use()
void townUse (vector <string> &inventory){
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
			player.setHealth(10);
		}		
		else {
			cout << "You have no potions.\n";
		}
	}
	else if (input == "homeward bone" || input == "bone"){
		cout << "You aren't in battle. It would be useless to use one here.\n";	
	}

	return ;

}

//Menu that sees which location the player is at and acts accordinglly
void menu (int &locate, vector <string> &inventory, vector <string> &shopkeep){
	string input;

	//Town
	if (locate == 0){
		cout << "\nYou're in the town. What will you do? ";
		for (int index = 0; index < inventory.size(); index++){
			if (inventory[index] == "key"){
				cout << "You have the key. Go to the graveyard!\n";
			}			
		}
		cin >> input;
		if (input == "go" || input == "GO"){
			go(locate);
		}
		else if (input == "list" || input == "LIST"){
			list(inventory); 
		}
		else if (input == "stats" || input == "STATS"){
			player.stats();
		}
		else if (input == "use" || input == "USE"){
			townUse(inventory);
		}
	}
	//Shop
	else if (locate == 1){
		cout << "\nWelcome to the shop.\n";
		shop (shopkeep, locate, inventory);
		return ;        
	}
	//Forest
	else if (locate == 2){
		cout << "\nYou are in the forest. A bunny appears!\n";
		current.bunny(); 
		fight(inventory);
		locate = 0;
	}
	//Desert
	else if (locate == 3){
		cout << "\nYou are in the desert. A scorpion appears!\n";
		current.scorpion();
		fight(inventory); 
		locate = 0;
	}
	//Mountains
	else if (locate == 4){
		cout << "\nYou are in the mountains. A troll appears!\n";
		current.troll(); 
		fight(inventory);
		locate = 0;
	}
	//Graveyard
	else if (locate == 5){
		bool keythere = false;
		cout << "You are at the graveyard.";
		for (int index = 0; index < inventory.size(); index++){
			if (inventory[index] == "key"){
				keythere = true;		
			}
		}
		if (keythere == true){
			cout << "You unlock the gate and enter Trogdor's tomb.\n";
			locate = 6;			
		}
		else {
			cout << "You look at the locked tomb with determination.\n";
		}
	}
	//End of game tomb
	else if (locate == 6){
		cout << "You are in Trogdor's tomb. You claim the riches! Thank you for playing!\n";
		gameWon = true;	
	}
}

//Shop function so that players can buy things
void shop(vector <string> &shopkeep, int &locate, vector <string> &inventory){
	int ironarmor = 0;
	int steelarmor = 0;
	int ironsword = 0;
	int steelsword = 0;
	string again;
	string input;

	//This is the main menu of the shop
	cout << "I have many things to sell.\n--------------------------   It looks like you have: " << player.outGold() << " gold\n";
	cout << "Potions - 15g\nHomeward Bones - 10g\n";
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
	cout << "armor\nswords\n\nWhat will you buy: "; 
	cin >> input;

	//Armor section of the shop
	if (input == "armor"){
		string input;
		cout << "Which type of armor would you like? I have:\n";
		cout << ironarmor << " set(s) of iron armor - 50g\n" << steelarmor << " set(s) of steel armor - 100g\nreturn\n";
		cout << "\nWhat will you buy: ";
		cin >> input;
		if (((input == "iron" || input == "IRON") && ironarmor > 0) && player.goldCheck(50)){
			//If someone buys armor it deletes that object from the shopkeep
			cout << "You've bought iron aromr.\n";
			inventory.push_back("iron armor");
			player.setGold(-50);
			player.setSpeed(1);
			int lower = 0;	
			for (int index = 0; lower < 1; index ++){
				if (shopkeep[index] == "ironarmor"){
					shopkeep.erase(shopkeep.begin() + index);
					lower += 1;
				}
			}
		}
		else if (((input == "steel" || input == "STEEL") && steelarmor > 0) && player.goldCheck(100)){
			//If someone buys armor it deletes that object from the shopkeep			
			cout << "You've bought steel armor.\n";
			inventory.push_back("steel armor");
			player.setGold(-100);
			player.setSpeed(1);
			int lower = 0;
			for (int index = 0; lower < 1; index ++){
				if (shopkeep[index] == "steelarmor"){
					shopkeep.erase(shopkeep.begin() + index);
					lower += 1;
				}
			}
		}
		else if (input == "return" || input == "RETURN"){
			return ;
		}
		else {
			cout << "You don't have enough gold for that.\n";
		}
	}

	//Sword section of the shop
	else if (input == "sword" || input == "swords"){
		string input;		
		cout << "Which type of sword would you like? I have:\n";
		cout << ironsword << " iron sword(s) - 50g\n" << steelsword << " steel sword(s) - 100g\nreturn\n";
		cout << "\nWhat will you buy: ";
		cin >> input;
		if (((input == "iron" || input == "IRON") && ironsword > 0) && player.goldCheck(50)){
			//If someone buys a sword it deletes that object from the shopkeep
			cout << "You've bought an iron sword.\n";
			inventory.push_back("iron sword");
			player.setGold(-50);
			player.setAttack(2);
			int lower = 0;
			for (int index = 0; lower < 1; index ++){
				if (shopkeep[index] == "ironsword"){
					shopkeep.erase(shopkeep.begin() + index);
					lower += 1;
				}
			}
		}
		else if (((input == "steel" || input == "STEEL")  && steelsword > 0) && player.goldCheck(100)){
			//If someone buys a sword it deletes that object from the shopkeep
			cout << "You've bought a steel sword.\n";
			inventory.push_back("steel sword");
			player.setGold(-100);
			player.setAttack(3);
			int lower = 0;
			for (int index = 0; lower < 1; index ++){
				if (shopkeep[index] == "steelsword"){
					shopkeep.erase(shopkeep.begin() + index);
					lower += 1;
				}
			}
		}
		else if (input == "return" || input == "RETURN"){
			return ;
		}
		else {
			cout << "You don't have enough gold for that.\n";
		}
	}

	//Potion section of the shop
	else if ((input == "potion" || input == "POTION") && player.goldCheck(15)){
		inventory.push_back("potion");
		cout << "You've bought a potion.\n";
		player.setGold(-15);
	}

	//Homeward bone seciton of the shop
	else if ((input == "bone" || input == "BONE") && player.goldCheck(10)){
		inventory.push_back("homewardbone");
		cout << "You've bought a homeward bone.\n";
		player.setGold(-10);
	}

	else {
		cout << "You don't have enough gold.\n";
	}
	//Conditional statements to see if people want to buy another thing
	cout << "Would you like to buy something else? (Yes/No)\n";
	cin >> again;

	if (again == "yes" || input == "y"){
		return ;
	}
	if (again == "no" || input == "n"){
		locate = 0;
		return ;
	}
}

//Function to let the player use potions and homeward bones in combat
void use(bool &defeated, vector <string> &inventory){

	int temp;
	int lower = 0;
	int potions = 0;
	int homewordBone = 0;
	string input; 

	//Checks how much of potions and homeward bones
	for (int index = 0; index < inventory.size(); index++){
		if (inventory[index] == "potion"){
			potions += 1;
		}
		else if (inventory[index] == "homewardbone"){
			homewordBone += 1;
		}
}

	//Asks users what they want to use
	cout << "What do you want to use? You have:\n" << potions;
	cout << " potions\n" << homewordBone << " homeword bones\n";
	cin >> input;

	//Potion section of the use function
	if (input == "potion" || input == "POTION"){
		if (potions > 0){
			for (int index = 0; lower < 1; index ++){
				if (inventory[index] == "potion"){
					inventory.erase(inventory.begin() + index);
					lower += 1;
				}
			}
			player.setHealth(10);
		}
		//If the player doesn't have a potion it outputs this
		else {
			cout << "You have no potions.\n";
		}
	}

	//Homeward bone section of the function
	else if (input == "homeward bone" || input == "bone"){
		if (homewordBone > 0){
			//Homeward bones sets the battle as done and in essence forces running away	
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

//List() outputs the inventory vector
void list(vector <string> inventory){
	if (inventory.size() == 0){
		cout << "Your inventory is currently empty.\n";
		return ;
	}
	//If inventory doesn't have anything in it it outputs this
	// to avoid a segmentation fault
	else {
		cout << "Your inventory:\n";
		for (int index = 0; index < inventory.size(); index++){
			cout << inventory[index] << endl;
		}
	}
}

//Asks for input and changes locate (location integer)  accordinglly
void go(int &locate){
	string input;
	cout << "Where would you like to go?\n";
	cin >> input;
	if (input == "north" || input == "NORTH"){
		//Shop is to the north		
		if (locate == 0){ 
			locate = 1;
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

	else {
		cout << "Please enter a valid input.\n";
	}

	return ;
}

void runGame(){
	cout << "\nIt is nighttime, you're in a graveyard, the full moon illuminates\n";
	cout << "your path, and finally you reach onto Trogdor's tomb. It is a giant\n";
	cout << "structure compared to the rest of the gravestones around you. As you\n";
	cout << "go to walk through the doorway, you realize a giant lock holds the\n";
	cout << "gate shut. If the legend is correct, the key should be being protected\n";
	cout << "in the mountains to the east.\nFor now you can't enter the tomb. Find the key and take what is yours!\n";
}

void mainMenu(char &input){
	string name;

	do{
		cout << "\n======= Grave of Trogdor =======\n";
		cout << "(S)tart\n(I)nstructions\n(L)ore\n(Q)uit\n\n";
		cin >> input;
		if (input == 'i' || input == 'I'){
			cout << "\nSimilar to old fashioned video games, this is a little RPG that takes\n";
			cout << "input commands.\nList of possible commands:\n";
			cout << "go 'direction' (If you want to go to the graveyard, type go graveyard)\nuse 'item'\nlist\nstats\n\nWhile in battle:\nattack\nrun\nuse\n";
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
