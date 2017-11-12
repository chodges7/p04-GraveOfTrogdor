#include<iostream>
#include<fstream>
#include<vector>
#include<string>
#include<ctime>
#include<cstdlib>

using namespace std;

//Prototypes
void menu();
void runGame();

int main(){
        srand( time(NULL));
        menu();
        return 0;
}


void menu(){
char input;
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

                }
                else if (input == 'q' || input == 'Q'){
                        cout << "Have a nice day\n";
                }
                else{
                        cerr << "Please enter a valid character.\n";
                } 
        }
        while (input != 'q' && input != 'Q');
}
