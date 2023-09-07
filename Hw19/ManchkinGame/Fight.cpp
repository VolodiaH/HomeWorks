
#include "Fight.h"

#include <algorithm>

#include "Item.h"
#include "ItemDeck.h"
#include "Modifier.h"
#include "Munchkin.h"
#include "Monster.h"
#include "Runaway.h"
#include "Victory.h"
#include "ModifierDeck.h"

void Fight::start()
{
	m_result = FightResult::InProgress;

	calculateMunchkinPower();
	calculateMonsterPower();
}

void Fight::applyModifier(int choice)
{
	Modifier* modifier = m_munchkin->popModifier(choice);
	if (modifier == nullptr)
	{
		throw std::exception();
		return;
	}

	modifier->apply(m_munchkin, m_monster);

	m_MunchkinPower += modifier->getMunchkinModifier();
	m_monsterPower += modifier->getMonsterModifier();
}

void Fight::runawayFlow()
{
	Runaway* policy = m_monster->getRunawayPolicy();
	if(policy)
	    policy->apply(m_munchkin);

	m_result = FightResult::MonsterWon;
}

void Fight::victoryFlow()
{
	
	m_munchkin->updateLevelBy(1);

	m_munchkin->addItem(ItemDeck::instance().generateItem());

	Victory *policy = m_monster->getVictoryPolicy();
	if(policy)
		policy->apply(m_monster, m_munchkin);
	

	std::ranges::for_each(m_munchkin->getItems(), [](auto& item){ item->enemyDefeated();});

	m_result = FightResult::MunchkinWon;
}

void Fight::calculateMunchkinPower()
{
	m_MunchkinPower += m_munchkin->getLevel();
	for (auto &&item : m_munchkin->getItems())
	{
		int power = item->getPower(m_monster->getTribe());
		m_MunchkinPower += power;
	}
}

void Fight::calculateMonsterPower()
{
	m_monsterPower = m_monster->getLevel();
}
