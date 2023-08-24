
#include "MonsterDeck.h"

#include <random>

#include "Runaway.h"
#include "Victory.h"

MonsterDeck::MonsterDeck()
{
	m_monstersDatabase.emplace_back(std::make_unique<Monster>( "Crazy Joe", 4 ));
	m_monstersDatabase.emplace_back(std::make_unique<Monster>( "Small Spider", 1 ));
	m_monstersDatabase.emplace_back(std::make_unique<Monster>( "Spider", 2 ));
	m_monstersDatabase.emplace_back(std::make_unique<Monster>( "Goblin", 2 ));
	m_monstersDatabase.emplace_back(std::make_unique<Monster>( "BigSpider", 3 ));
	m_monstersDatabase.emplace_back(std::make_unique<Monster>( "Gundabad Warg", 5 ));
	m_monstersDatabase.emplace_back(std::make_unique<Monster>( "Ogr", 12 ));
	m_monstersDatabase.emplace_back(std::make_unique<Monster>( "Azog", 13 ));
	m_monstersDatabase.emplace_back(std::make_unique<Monster>( "Nazgul", 15 , Tribe::Demons, new Runaway_LevelDowngradeIf{ 2, 3 }));
	m_monstersDatabase.emplace_back(std::make_unique<Monster>( "Ork", 6 ));
	m_monstersDatabase.emplace_back(std::make_unique<Monster>( "Ork", 6 ));
	m_monstersDatabase.emplace_back(std::make_unique<Monster>( "Uruk-hai", 6 ));
	m_monstersDatabase.emplace_back(std::make_unique<Monster>( "Warg", 3 ));
	m_monstersDatabase.emplace_back(std::make_unique<Monster>( "Vampire", 3, Tribe::Undead, new Runaway_LevelDowngrade{1} ));
	m_monstersDatabase.emplace_back(std::make_unique<Monster>( "Shiva destructor", 200, Tribe::God, new Runaway_LevelDowngradeIf{ 2, 5 } , new VictoryAdditionalCards));
	m_monstersDatabase.emplace_back(std::make_unique<Monster>( "Sauron", 300, Tribe::God, new Runaway_LevelDowngradeIf{ 2, 7 } , new VictoryAdditionalCards));

	std::random_device rd;
	std::mt19937 gen{ rd() };
	std::ranges::shuffle(m_monstersDatabase, gen);

	m_monsterStatus.assign(m_monstersDatabase.size(), StatusDeck::Free);
}

Monster* MonsterDeck::generateMonster() {
	
	return algorithm::getItem(m_monstersDatabase, m_monsterStatus);
}