#ifndef _CHARACTER_H_
#define _CHARACTER_H_

#include<string>

class character{
	public:
		bool goldCheck(int);
		bool speedCheck(int);
		void createCharacter(std::string);
		void stats();
		void setHealth(int);
		void setGold(int);
		void setAttack(int);
		void setSpeed(int);

	private:
		int health;
		int speed;
		int attack;
		int gold;
};

#endif
