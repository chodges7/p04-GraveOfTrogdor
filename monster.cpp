#include"monster.h"

using namespace std;

int Monster::goldOut(){
	return gold;
}

int Monster::attackOut(){
	return attack;
}

void Monster::setHealth(int delta){
	health += delta;
	return ;
}

int Monster::speedOut(){
	return speed;
}

bool Monster::attackCheck(int check){
	if (attack == check){
		return true;
	}
	else {
		return false;
	}
}

bool Monster::checkDead(){
	if (health <= 0){
		return true;
	}
	else if (health > 0){
		return false;
	}
}
void Monster::bunny(){
	health = 5;
	attack = 2;
	speed = 2;
	gold = 10;
	return ;
}

void Monster::scorpion(){
	health = 10;
	attack = 5;
	speed = 5;
	gold = 20;
	return ;
}

void Monster::troll(){
	health = 35;
	attack = 7;
	speed = 5;
	gold = 5;
	return ;
}
