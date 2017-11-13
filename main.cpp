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
class monster{
        public:
                int health;
                int attack;
};

//Prototypes
void menu(char &);
void runGame();
character createCharacter(string, character &);
int randomNumber(unsigned int, unsigned int);

int main(){
        srand( time(NULL));
        char input;
        string name;
        character player;

        //Menu to get started
        menu(input);
        if (input == 'q' || input == 'Q'){
                return 0;
        }
        //Name for the player
        cout << "Please enter a character name:";
        cin >> name;

        //This function creates the object used for battling
        createCharacter(name, player);

  return 0;
}

character createCharacter(string name, character &player){
        int input;
        bool done = false;

        cout << "\nWhat class would you like?\n";
        cout << "(1)Fighter (5 atk 5 spd 10 hp)\n(2)Knight (7 atk 3 spd 10 hp)\n(3)Rouge (3 atk 7 spd 10 hp)\n";
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

void menu(char &input){
        string name;

        do{
                cout << "\n======= Grave of Trogdor =======\n";
                cout << "(S)tart\n(I)nstructions\n(L)ore\n(Q)uit\n\n";
                cin >> input;
                if (input == 'i' || input == 'I'){
                        cout << "\nSimilar to old fashioned video games, this is a little RPG that takes\n";
                        cout << "input commands. List of possible commands listed below:\n\n";
                        cout << "go north (or any other cardinal direction)\nsearch 'name'\nuse 'item'\nlist inventory\ntalk 'person'\n";
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
