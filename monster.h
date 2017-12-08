#ifndef _MONSTER_H_
#define _MONSTER_H_

class monster{
	public:
		int speedOut();
		int attackOut();		
		int goldOut();
		bool attackCheck(int);
		bool checkDead();
		void setHealth(int);		
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
