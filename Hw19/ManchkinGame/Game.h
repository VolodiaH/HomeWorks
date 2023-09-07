
#pragma once
#include "Munchkin.h"
#include "ItemDeck.h"
#include "MonsterDeck.h"
#include "ModifierDeck.h"

class Game
{
public:
	Game() : m_itemsDeck(ItemDeck::instance()), m_modifiersDeck(ModifierDeck::instance()){}
	void run();

private:
	void generateMunchkinInitialCards();
	Monster* generateMonster();

private:
	Munchkin m_munchkin;
	ItemDeck &m_itemsDeck ;
	ModifierDeck &m_modifiersDeck;
	MonsterDeck m_monstersDeck;
};