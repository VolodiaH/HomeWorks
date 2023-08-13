#include "Player.h"

void Player::setWeapon(Weapon *weapon)
{
	delete m_weapon;
	m_weapon = weapon;
}

void Player::setPlayerClass(PlayerClass *playerClass)
{
	delete m_class;
	m_class = playerClass;
}

void Player::attack(const Player &other, int distance)
{
	if (&other == this)
	{
		std::cout << "\n-------FRIENDLY FIRE!-------\n";
	}

	if (other.isEliminated())
	{
		std::cout << "Player " << other.getName() << " has been already eliminated!\n";
		return;
	}

	//#TODO: Optional: Add your own damage-related modifier
	const int damage = static_cast<int>(m_weapon->getDamageRate(distance) * m_class->getDamageMultiplier() / other.m_class->getDefenseMultiplier());
	m_health -= damage;

	std::cout << "Player " << getName() << " attacked Player " << other.getName() <<
		" with damage " << damage << std::endl;

	std::cout << "Health left: " << m_health << std::endl;

	if (m_health <= 0)
	{
		m_health = 0;
		std::cout << "Player " << other.getName() << " was eliminated!\n";
	}
}