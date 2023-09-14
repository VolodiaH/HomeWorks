
#pragma once
#include <string>
#include <format>
#include "Monster.h"
#include "Munchkin.h"

class Modifier
{
public:
    virtual ~Modifier() = default;
    virtual void apply(Munchkin* munchkin, Monster* monster) = 0;
	virtual int getMunchkinModifier() const { return m_munchkinPowerChange; }
	virtual int getMonsterModifier() const { return m_monsterPowerChange; }

	virtual std::string getFullInfo() const { return ""; }

	void changeMunchkinPower(int power) { m_munchkinPowerChange = power; }
	void changeMonsterPower(int power) { m_monsterPowerChange = power; }

private:
	int m_munchkinPowerChange = 0;
	int m_monsterPowerChange = 0;
};

class SimpleModifier : public Modifier
{
public:
	explicit SimpleModifier(int powerBoost) : m_powerBoost(powerBoost) {}

	void apply(Munchkin* munchkin, Monster* monster) override
	{
		changeMunchkinPower(m_powerBoost);
	}

	std::string getFullInfo() const
	{
		// Code Smell | Major | cpp:S6185 Tags: clumsy since-c++20
		// "std::format" should be used instead of string concatenation and "std::to_string"
		return std::format("Munchkin power + {}",  std::to_string(m_powerBoost));
	}

private:
	int m_powerBoost;
};

class DoubleMunchkinLevel : public Modifier
{
public:
	void apply(Munchkin* munchkin, Monster* monster) override
	{
		changeMunchkinPower(munchkin->getLevel() * 2);
	}

	std::string getFullInfo() const override
	{
		return "Double Munchkin level!";
	}
};

class HalvesMonsterLevel : public Modifier
{
public:

	explicit HalvesMonsterLevel(Tribe tribe) : m_tribe{tribe} {}
	void apply(Munchkin* munchkin, Monster* monster) override
	{
		if(m_tribe == monster->getTribe())
			changeMunchkinPower(getMonsterModifier() - monster->getLevel() / 2);
	}

	std::string getFullInfo() const override { return "Cuts monster's power by 2 for tribe: " + getTribeString(m_tribe); } 

private:
	Tribe m_tribe;
};

class ThanosGauntlet : public Modifier
{
public:
	void apply(Munchkin *munchkin, Monster *monster) override
	{
		changeMunchkinPower(getMonsterModifier() - monster->getLevel() * 100);
	}
    std::string getFullInfo() const override { return "100% kill - with Thanos' Gauntlet with all stone of infinity"; } 
};