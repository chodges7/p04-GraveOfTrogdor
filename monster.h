#ifndef _MONSTER_H_
#define _MONSTER_H_

class Monster{
	public:
		bool checkDead();
		void bunny();
		void scorpion();
		void troll();

	private:
		int health;
		int attack;
		int speed;
		int gold;
};

#endif
