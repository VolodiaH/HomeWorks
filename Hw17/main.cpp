#include <string>

#include "Weapon.h"
#include "PlayerClass.h"
#include "Player.h"

int main()
{
	//Game cycle
	Player player1("OnePunchMan", 3, new SniperRifle);
	Player player2("JohnCena",90 , new Axe, new DefenderClass);
	Player player3("Cpt. Price",100,  new AssaultRifle, new AttackerClass);
	Player player4("Wolverine", 78, new AdamantiumClaws, new AttackerClass);

	player3.attack(player1,400);
	player3.attack(player1,500);
	player1.attack(player2, 500);
	player1.attack(player2, 2000);
	player1.attack(player1, 300);
	player2.attack(player1, 100);
	player1.attack(player2, 500);

	player4.attack(player3,0);
	player4.attack(player3,0);
	player4.attack(player3,0);

	return 0;
}