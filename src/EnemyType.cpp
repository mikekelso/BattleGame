/*
 * villian.cpp
 *
 *  Created on: Nov 28, 2023
 *      Author: mmich
 */
#include <unordered_map>
#include <iostream>
#include "EnemyType.h"

//constructor that sets difficulty of enemy
EnemyType::EnemyType(int level){
	difficulty = level;
}

//unordered map object , attributes, is populated with HP and Strength attributes
//which are set to values based of enemy's difficulty setting
void EnemyType::GenerateStats(){


	attributes.insert({"HP", (difficulty * 40)});
	attributes.insert({"Strength", (difficulty * 5)});
	health = attributes["HP"];

	}


// Both of the enmey's attributes are printed to the console
void EnemyType::PrintStats(){
	std::cout << "These enemies' stats: \n \n" ;
	for (auto iter: attributes){
		std::cout << iter.first << " " << iter.second << "\n";
	}
}



