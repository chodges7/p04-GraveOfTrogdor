#ifndef _MONSTER_H_
#define _MONSTER_H_

class Monster{
	public:
		static void bunny(Monster &);
		static void scorpion(Monster &);
		static void troll (Monster &);

	private:
		int health;
		int attack;
		int speed;
		int gold;
};

#endif
