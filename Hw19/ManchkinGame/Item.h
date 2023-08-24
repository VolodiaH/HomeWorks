
#pragma once
#include <format>

#include "Tribe.h"
#include <string>

class Item
{
public:
	Item(const std::string &name, int power, const std::string &desc): m_power{power}, m_name{name}, m_description(desc){}
    virtual ~Item() = default;
	virtual int getPower(Tribe monsterTribeModifier) const { return m_power; }

	void setName(const std::string& name) { m_name = name; }
	const std::string getName() const { return m_name; }
    void setDescription(const std::string& desc) { m_description = desc; }
	const std::string getDescription() const { return m_description; }
	virtual std::string getFullInfo() const = 0;

	virtual void enemyDefeated() const {/* Special logic for defeating enemy */}
	virtual int getBasePower() const { return m_power; }

private:
	const int m_power = 0;
	std::string m_name;
	std::string m_description;
	//other fields like description, image, category
};

class Weapon : public Item
{
public:
	Weapon(const std::string &name, int power, const std::string &desc) : Item(name, power, desc){}

	std::string getFullInfo() const override
	{
		return  std::format(" \"{}\", power: {}, skills: {}, description: {} \n", getName(), getBasePower(), skills(), getDescription());
	}

private:
	virtual std::string skills() const { return "None"; }

};

class UndeadWeapon : public Weapon
{
public:
	UndeadWeapon(const std::string& name, int power, const std::string &desc) : Weapon(name, power, desc) {}

	int getPower(Tribe monsterTribeModifier) const override
	{
		switch (monsterTribeModifier)	
		{
		case Tribe::Undead:
			return getBasePower() * 2;
		case Tribe::Human:
		case Tribe::Zombie:
		default:
			return getBasePower();
		}
	}

private:
	std::string skills() const override { return "x2 vs UNDEADS!"; }
};

class FireWeapon : public Weapon
{
public:
	FireWeapon(const std::string &name, int power, const std::string &desc = "") : Weapon(name, power, desc) {}

	int getPower(Tribe monsterTribeModifier) const override
	{
		switch (monsterTribeModifier)
		{
		case Tribe::Undead:
		case Tribe::Human:
		case Tribe::Zombie:
		case Tribe::God:
			return getBasePower() * 3;
		}
		return 0;
	}

private:
	std::string skills() const override { return "Deals 3x damage to every Race, but useless against Demons"; }
};

class SoulWeapon : public Weapon
{
public:
	SoulWeapon(const std::string &name, int power, const std::string &desc = "") : Weapon(name, power, desc) {}

	int getPower(Tribe monsterTribeModifier) const override
	{
		return getBasePower() + m_Souls;
	}
	void enemyDefeated() const override
	{
		++m_Souls;
	}

private:
	std::string skills() const override { return std::format("Increases its damage with every defeated enemy's soul - Current souls: {}" , m_Souls); }

	mutable int m_Souls{};
};

class HolySword : public Weapon
{
public:
	HolySword(const std::string &name, int power, const std::string &desc = "") : Weapon(name, power, desc) {}

	int getPower(Tribe monsterTribeModifier) const override
	{
		switch (monsterTribeModifier)
		{
		    case Tribe::Zombie:
			    return getBasePower() * 1000;
		    case Tribe::Undead:
		    case Tribe::Human:
		    case Tribe::God:
		    case Tribe::Demons:
		    default:
			    return getBasePower();
		}
	}

private:
	std::string skills() const override { return "Effectively kills Zombies"; }
};
