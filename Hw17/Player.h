#pragma once
#include <string>
#include<iostream>
#include "PlayerClass.h"
#include "Weapon.h"

class Player
{
public:
	Player(const std::string &name = "Auto Generated NameId", const int level, Weapon *weapon = new BareHand, PlayerClass *playerClass = new DefaultClass)
		: m_name(name), m_level{level}, m_weapon(weapon), m_class(playerClass) {}
	~Player()
	{
		delete m_class;
		delete m_weapon;
	}


	std::string getName() const { return m_name; }
	int getBaseDamage(int distance) { return m_weapon->getDamageRate(distance); }

	void setWeapon(Weapon *weapon);
	void setPlayerClass(PlayerClass *playerClass);
	void setHealth(int health) { m_health = health; }
	bool isEliminated() const { return m_health <= 0; }

	void attack(const Player &other, int distance);

private:
	int m_health = 100;
	std::string m_name;
	size_t m_level;
	PlayerClass *m_class = nullptr;
	Weapon *m_weapon = nullptr;
};