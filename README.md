# p04-GraveOfTrogdor
### Final project for CSCI 111

  Grave of Trogdor is a text based adventure RPG made entirely through C++. The goal of
the project is to help prepare me for designing a game in the future. Seeing as my minor 
is in video game design and my dream job is being a game programmer, I will need to start
designing games sometime; I might as well start sooner rather than later.

### Input/Output

  User input and output can be seen in [main.cpp at lines 578-601](/main.cpp). 
There are several cout statements that explain the instructions, tell the lore, start and
quit the game. There is a cin statement taking input, and there is also a cerr statement 
in the else conditional in case something goes wrong with the input statement.

### Control Flow

  Control flow can be seen in [character.cpp at lines 99-125](/character.cpp). There
is an if statement, an else if to check for other conditions, and an else condition to
catch all the other inputs that the user might throw at the player. This is so the user
can choose a class by inputing a number into the program.

### Iteration

  For the two types of iteration the do while loop can be found in [main.cpp at lines 66-69](/main.cpp).
This do while loop repeats the menu function until the gameWon bool is set to true. 
Another type of iteration is the for loop which can be found in [main.cpp at lines 179-186](/main.cpp).
This for loop checks though the player's inventory and adds how many potions to the potions
int variable.

### Data structure

  Data structure can be found as a vector in [main.cpp at line 35](/main.cpp).
The data stucture used is a vector that is used throughout the program to let other
functions know what the player has in their inventory (ex: potions, swords, and armor).

### Function

  There are more than three functions in this program. One of the void return type functions
can be found in [main.cpp at line 17](/main.cpp), which allows the player to
travel between areas. One of the non-void return type function is in [main.cpp at line 13](/main.cpp). 
Which returns a random number between any two numbers you give the function.An example of 
pass-by-value can be found in [main.cpp at line 19](/main.cpp). Which passes
in the inventory vector so the function can list out what the player has in their inventory.
Lastly, pass by reference can be found in [main.cpp at line 14](/main.cpp). If the
referenced value returns as a 'q' or 'Q' then the program will stop. 

### File Input/Output

  File input/output can be found in [main.cpp at line 58](/main.cpp). Throughout the 
function the killLog.txt file is open so whenever the player kills a monster, it will be
logged in the kill log.

### Class

  Classes can be found in the multiple class files found in the repository; including
[character.h](/character.h), [monster.h](/monster.h), and their respective .cpp files.
These files help the program run by creating specialty objects the program can use to 
represent both the player and monsters used.
