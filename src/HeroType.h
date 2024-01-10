#ifndef HERO_H_
#define HERO_H_

/*
 * hero.h
 *
 *  Created on: Nov 28, 2023
 *      Author:
 */
#include <unordered_map>
#include <string>



class HeroType{
public:
	//unordered map that organizes attack, defense, and agility attributes for hero.
	std::unordered_map<std::string, int> attributes;

	//Hero's have 100 health and start with 0 gold
	int health = 100;
	int gold =0;


	bool alive = true;

	//constructor
	HeroType();

	//constructor that makes hero of chosen type
	HeroType(int);


	void GenerateStats();
	//Function: Attributes defined in unordered map are assigned values based off chosen hero type
	// Pre: unordered map, attributes, has been declared.
	// Post: Attack, Defense, and Agility attributes are added to unordered map and their corresponding
	// 		 values are set.


	void PrintStats();
	//Pre:		Unordered map, attributes, has been created and attack, defense, and agility have been added and
				//their values set (GenerateStats performs this function).
	//Post: 	Each attribute and its corresponding value are printed to the console.



private:
	//Hero type: 1 for warrior, 2 for archer, 3 for sorceress
	int HeroRole;


};


#endif /* HERO_H_ */
