#ifndef ENEMYTYPE_H_
#define ENEMYTYPE_H_

/*
 * villian.h
 *
 *  Created on: Nov 28, 2023
 *      Author: mmich
 */



#include <unordered_map>
#include <string>
class EnemyType{
public:

	bool alive = true;
	int difficulty = 1;
	int health;

	// unordered map data structure used to store strength and HP attributes of Enemy objects
	std::unordered_map<std::string, int> attributes;


	EnemyType(int level);
	// Function: Enemy constructor that sets difficulty of enemy.
	// Post: Enemy object is created and its difficulty is set.

	void GenerateStats();
	//Pre: unordered map object is declared.
	//Post: HP, Strength, and health values for enemy are set based off enemy dificulty level

	void PrintStats();
	// Pre: Enemy attributes unorder_map has been declared. Strength and HP attributes have been added and set
	// (GenerateStats performs this function).
	//Post:Both the enemy's HP and Attack attribute values are printed to the console.

};


#endif /* ENEMYTYPE_H_ */
