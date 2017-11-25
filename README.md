# p04-GraveOfTrogdor
Final project for CSCI 111

  Grave of Trogdor is a text based adventure RPG made entirely through C++. The goal of
the project is to help prepare me for designing a game in the future. Seeing as my minor 
is in video game design and my dream job is being a game programmer, I will need to start
designing games sometime; I might as well start sooner rather than later.

### Input/Output

  User input and output can be seen in [main.cpp at lines 668-700](/blob/master/main.cpp). 
There are several cout statements that explain the instructions, tell the lore, start and
quit the game. There is a cin statement taking input, and there is also a cerr statement 
in the else conditional in case something goes wrong with the input statement.

### Control Flow

  Control flow can be seen in [main.cpp at lines 627-653](/blob/master/main.cpp). There
is an if statement, an else if to check for other conditions, and an else condition to
catch all the other inputs that the user might throw at the player. This is so the user
can choose a class by inputing a number into the program.

### Iteration

  For the two types of iteration the do while loop can be found in [main.cpp at lines 79-82](/blob/master/main.cpp).
This do while loop repeats the menu function until the gameWon bool is set to true. 
Another type of iteration is the for loop which can be found in [main.cpp at lines 95-102](/blob/master/main.cpp).
This for loop checks though the player's inventory and adds how many potions to the potions
int.

### Data structure

  Data structure can be found as a vector in [main.cpp at line 53](/blob/master/main.cpp).
The data stucture used is a vector that is used throughout the program to let other
functions know what the player has in their inventory.

### Function

  There are more than three functions in this program. The first void return type function
can be found in [main.cpp at line 34](/blob/master/main.cpp). The first non-void return
type function is at [line 34](/blob/master/main.cpp). An example of pass-by-value can be
found at [line 41](/blob/master/main.cpp). Lastly, pass by reference can be found at
[line 36](/blob/master/main.cpp).

### File Input/Output



### Class


