
#pragma once
#include <string>
#include <memory>

#include "Tribe.h"
#include "Runaway.h"
#include "Victory.h"

class Monster
{
public:
	Monster(const std::string& name, int level = 1, Tribe tribe = Tribe::Human, Runaway* policy = nullptr, Victory* vPolicy = nullptr)
		: m_level(level), m_tribe(tribe), m_name(name), m_RunawayPolicy(policy) , m_VictoryPolicy(vPolicy){}

	Tribe getTribe() const { return m_tribe; }
	unsigned getLevel() const { return m_level; }
	const std::string& getName() const { return m_name; }

	Runaway* getRunawayPolicy() const { return m_RunawayPolicy.get(); }
	Victory * getVictoryPolicy() const { return m_VictoryPolicy.get(); }

	std::string getFullInfo() const { return "Monster " + getName() + ", " + m_RunawayPolicy->getFullInfo(); }

	std::string getPolicyInfo() const
	{
	    if(m_RunawayPolicy)
			return m_RunawayPolicy->getFullInfo();

		return "";
	}

private:
	unsigned int m_level = 1;
	Tribe m_tribe = Tribe::Human;
	std::string m_name;

	std::unique_ptr<Runaway> m_RunawayPolicy = nullptr;
	std::unique_ptr<Victory> m_VictoryPolicy = nullptr;
};