#ifndef _MONSTER_H_
#define _MONSTER_H_

class Monster{
	public:
		static void bunny();
		static void scorpion();
		static void troll();
		bool checkDead();

	private:
		int health;
		int attack;
		int speed;
		int gold;
};

#endif
