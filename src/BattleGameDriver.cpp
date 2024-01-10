//============================================================================
// Name        : GroupProject.cpp
// Author      : Mike Kelso
// Version     :
// Copyright   : 
// Description : Hello World in C++, Ansi-style
//============================================================================





#include <iostream>
#include <cstring>
#include <iomanip>
#include <vector>

#include "EnemyType.h"
#include "HeroType.h"
using namespace std;


void PrintHealth(HeroType Hero){
//	Pre:	Hero has been created.
//	Post:	Hero's current health is printed to the console.


	std::cout << "Your hero's current health is: " << Hero.health << "\n";

}

void PrintGold(HeroType Hero){

//	Pre:	Hero has been created.
//	Post:	Hero's current gold is printed to the console.

	std::cout << "You currently have " << Hero.gold << " gold.\n" << endl;
}

HeroType MakePurchases (HeroType Hero){
	//	Pre:	Hero has been created. Hero's attribute values have been initialized.
	//			PrintHealth, PrintGold, and PrintStats functions have been defined.
	//	Post:	Hero is updated with new health and attribute values based off purchases made. Changed quantities are printed to the console.

	int selection;

	cout << "Enter: \n '0' to skip purchases \n '1' to buy health packs \n '2' to upgrade your attack (cost 50 gold) \n '3' to upgrade defense (cost 50 gold)  \n '4' to upgrade agility (cost 50 gold)  " << endl;

	std::cin >> selection;

	switch (selection)
	{

	// Player chooses to replenish health to 100
	case 1:
	{

		int healthCost = (100 - Hero.health) / 10;
		if(healthCost > Hero.gold){
			cout<< "You do not have enough money to replenish your health. \n" << endl;
			break;
		}
		else{
			Hero.gold -= healthCost;
			Hero.health = 100;
			PrintHealth(Hero);
			PrintGold(Hero);
		}
		return Hero;

	}
	//Player chooses to increase attack for 50 gold
	case 2:
	{

		if (Hero.gold < 50)
		{
			cout << "You do not have enough gold. \n" << endl;
			break;
		}

		Hero.gold -= 50;
		Hero.attributes["Attack"]++;
		Hero.PrintStats();
		return Hero;
	}

	//Player chooses to increase defense for 50 gold
	case 3:
	{
		if (Hero.gold < 50)
		{
			cout << "You do not have enough gold. \n" << endl;
			break;
		}
		Hero.gold -= 50;
		Hero.attributes["Defense"]++;
		Hero.PrintStats();
		return Hero;
	}


	//Player chooses to increase agility for 50 gold
	case 4:
	{
		if (Hero.gold < 50)
		{
			cout << "You do not have enough gold. \n" << endl;
			break;
		}
		Hero.gold -= 50;
		Hero.attributes["Agility"]++;
		Hero.PrintStats();
		return Hero;
	}


	//Any other input besides 1, 2, 3, or 4 is ignored
	default:
		cout << "Maybe next time. \n" << endl;
	}


	return Hero;
}


int getEvadeValue(HeroType Hero){
	// Function: Calculates value based off agility of of hero used to determine evasion of attacks
	//	Pre:	Hero has been created. Attribute values for the hero have been assigned.
	//	Post:	Integer value used to determine evasion is returned
	int evadeValue;
	evadeValue = Hero.attributes["Agility"] + (rand() % 20);
	return evadeValue;
}


HeroType battle (HeroType Hero, EnemyType Enemy){
	// Function: BATTLE!
	//	Pre:	 Hero and enemy have been created and their respective attributes have been set.
	//  		 PrintHealth and getEvadeValue functions have been defined.
	//	Post:	Hero's gold, health, and alive status is updated based off outcome of fight.

	bool Victory = false;
	bool Defeat = false;

	while (Hero.alive == true && Enemy.alive == true){
		//Enemy attack phase

		if (getEvadeValue(Hero) < 20){
			int damage = Enemy.attributes["Strength"] - Hero.attributes["Defense"];
			cout << "You were dealt " << damage << " damage by the enemy." << endl;
			Hero.health -= damage;
			PrintHealth(Hero);
		}
		else {
			cout << "The enemy's attack was evaded." << endl;
		}
		if (Hero.health <= 0){
			Hero.alive = false;
			Defeat = true;
			cout << "You died\n" << endl;
			break;
		}
		//Hero Attack Phase
		if (getEvadeValue(Hero) > 10){
			cout << "You dealt " << Hero.attributes["Strength"] << " damage to the enemy. " << endl;
			Enemy.health -= Hero.attributes["Strength"];
			cout << " The enemy has " << Enemy.health << " health remaining." << endl;
		}
		else {
			cout << "The enemy evaded your attack." << endl;
		}

		if (Enemy.health <= 0){
			Enemy.alive = false;
			Victory = true;
			Hero.gold += Enemy.difficulty * 5;
			cout << "You killed the enemy!" << endl;
			cout << "You gain " << Enemy.difficulty * 5 << " gold. \n" << endl;
		}

	}
	return Hero;

}


// Main function


int main()
{
	HeroType Hero;
	int selection = 0;
	int difficulty = 0;
	int numberOfEnemies = 0;
	bool keepPlaying = true;

	//this is a vector of enemies. There will be between 1 and 3
	//enemy objects in this vector based off player's selection.
	std::vector<EnemyType> enemyLineUp;
	enemyLineUp.reserve(3);



	//switch with cases is used for player to choose hero type. Hero is then created and assigned
	//starting values

	std::cout << "Choose your hero. Enter: " << endl;

	std::cout << "1 for Warrior " << endl;
	std::cout << "2 for Archer " << endl;
	std::cout << "3 for Sorceress " << endl;

	std::cin >> selection;

	switch (selection)
	{


	//Warrior type is chosen.
	case 1:
	{
		cout << "You have chosen to be a Warrior." << endl;
		Hero = HeroType(0);
		Hero.GenerateStats();
		Hero.PrintStats();
		break;
	}


	//Archer type is chosen.
	case 2:

		cout << "You have chosen to be an Archer." << endl;
		Hero = HeroType(1);
		Hero.GenerateStats();
		Hero.PrintStats();
		break;


	//Sorceress type is chosen.
	case 3:
		cout << "You have chosen to be a Sorceress." << endl;
		Hero = HeroType(2);
		Hero.GenerateStats();
		Hero.PrintStats();
		break;


	//Invalid selection is not accepted.
	default:
		std::cout << "Invalid hero choice. Please try again. " <<
			endl;
		exit(0);
	}



	while (keepPlaying){

		//Players chooses a difficulty.
		cout << "\nChoose enemy difficulty (1-10)." << endl;
		cin >> difficulty;

		//correct invalid integer input
		if (difficulty > 10){
			difficulty = 10;
		}
		else if ( difficulty <= 0){
			difficulty = 1;
		}


		//choose number of enemies. Determines size of enemy array.
		cout << "How many enemies would you like to fight? Enter a number between 1 and 3." << endl;

		//correct invalid integer input.
		cin >> numberOfEnemies;
		if (numberOfEnemies > 3){
			numberOfEnemies = 3;
		}
		else if (numberOfEnemies < 1){
			numberOfEnemies = 1;
		}

		// A vector is used to store the enemies. The number of enemies chosen determines how many enemies
		// are added to the enemyLineUp vector.
		for (int i = 0; i< numberOfEnemies; i++)
			{
			EnemyType Enemy = EnemyType(difficulty) ;
			Enemy.GenerateStats();
			Enemy.PrintStats();
			enemyLineUp.emplace_back(Enemy);

			}

		//Loop to control sequential battles of each enemy in enemy lineup
		int battleCounter = 1;
		for (auto &enemy : enemyLineUp){
			cout << "You are fighting Opponent Number " << battleCounter << " Good Luck!\n" << endl;
			Hero = battle(Hero,enemy);
			if (!Hero.alive)
			{

				keepPlaying = false;
				enemyLineUp.clear();
				break;
			}

			battleCounter ++;
		}

		//after battle is over clear enemyLineUp vector to be ready for next battle sequence
		enemyLineUp.clear();






		//If hero survived battle, print health and gold to console, offer player purchase options, and
		// offer to let player play another round. If Hero is not alive game is over.
		if (Hero.alive == true){
			PrintHealth(Hero);
			PrintGold(Hero);
			Hero = MakePurchases(Hero);

			do
			{
				cout << "Do you wish to fight more opponents? Enter ' 0 ' for yes, ' 1 ' for no." << endl;
				cin >> selection;
				if (selection == 0)
					keepPlaying = true;
				else if (selection == 1)
					keepPlaying = false;
			} while (selection != 1 && selection != 0 );
		}


	}

	cout << "Thank you for playing!" << endl;





	return 0;
}








