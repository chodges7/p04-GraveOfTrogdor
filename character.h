#ifndef _CHARACTER_H_
#define _CHARACTER_H_

#include<string>

class character{
	public:
		void createCharacter(std::string name);
		void stats();

	private:
		int health;
		int speed;
		int attack;
		int gold;
};

#endif
