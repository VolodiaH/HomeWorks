
#pragma once
#include <vector>
#include <string>
#include <memory>

#include "Item.h"
#include "MyAlgorithm.h"

class ItemDeck
{
public:
	ItemDeck();

	std::vector<Item*> generateItems();
	Item* generateItem();

private:
	using Card = std::vector<std::string>;
	using DeckData = std::vector<Card>;

	void createItems(const DeckData &cards);
	Item *createItem(const Card &card) const ;

	std::vector<std::unique_ptr<Item>> m_itemsDataBase;
	std::vector<StatusDeck> m_itemsStatus;
};