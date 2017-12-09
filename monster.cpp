#include"monster.h"

using namespace std;

int monster::goldOut(){
	return gold;
}

int monster::attackOut(){
	return attack;
}

void monster::setHealth(int delta){
	health += delta;
	return ;
}

int monster::speedOut(){
	return speed;
}

bool monster::attackCheck(int check){
	if (attack == check){
		return true;
	}
	else {
		return false;
	}
}

bool monster::checkDead(){
	if (health <= 0){
		return true;
	}
	else if (health > 0){
		return false;
	}
}
void monster::bunny(){
	health = 5;
	attack = 2;
	speed = 2;
	gold = 10;
	return ;
}

void monster::scorpion(){
	health = 10;
	attack = 4;
	speed = 5;
	gold = 30;
	return ;
}

void monster::troll(){
	health = 35;
	attack = 7;
	speed = 5;
	gold = 5;
	return ;
}
