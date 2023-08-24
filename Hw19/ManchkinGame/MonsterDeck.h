
#pragma once
#include <vector>
#include <memory>

#include "Monster.h"
#include "MyAlgorithm.h"

class Monster;

class MonsterDeck
{
public:
	MonsterDeck();

	Monster* generateMonster();

private:
	std::vector<std::unique_ptr<Monster>> m_monstersDatabase;
	std::vector<StatusDeck> m_monsterStatus;
};