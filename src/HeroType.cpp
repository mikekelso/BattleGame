/*
 * hero.cpp
 *
 *  Created on: Nov 28, 2023
 *      Author: mmich
 */
#include "HeroType.h"
#include <unordered_map>
#include <iostream>

HeroType::HeroType(){
	HeroRole = 0;

}

HeroType::HeroType(int selection){
	HeroRole = selection;

}


void HeroType::GenerateStats(){
	//Warrior
	if (HeroRole == 0){

		attributes.insert({"Strength", 10});
		attributes.insert({"Defense", 3});
		attributes.insert({"Agility", 4});

	}
	//Archer
	else if (HeroRole ==1){

		attributes.insert({"Strength", 6});
		attributes.insert({"Defense", 1});
		attributes.insert({"Agility", 10});

	}
	//Sorceress
	else if (HeroRole == 2){

		attributes.insert({"Strength", 8});
		attributes.insert({"Defense", 2});
		attributes.insert({"Agility", 8});

	}


}


void HeroType::PrintStats(){
	std::cout << "Your hero's attributes: \n \n" ;
	for (auto iter: attributes){
		std::cout << iter.first << " " << iter.second << "\n";
	}
}







