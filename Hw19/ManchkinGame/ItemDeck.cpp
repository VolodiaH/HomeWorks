
#include "ItemDeck.h"

#include <algorithm>
#include <random>
#include <fstream>

#include "Item.h"

constexpr size_t StartItemsCount = 4;

ItemDeck::ItemDeck()
{
	DeckData cards;
	std::fstream file("deck.txt", std::fstream::in);
	if(file)
	{
		while(!file.eof())
		{
			std::string line;
			std::getline(file, line);

			if(line.empty())
				continue;

			auto card = algorithm::split(line, ";");
			if(card.size() >= 4)
				cards.emplace_back(card);
		}
	}

	createItems(cards);
	m_itemsStatus.assign(m_itemsDataBase.size(), StatusDeck::Free);
	
}

ItemDeck& ItemDeck::instance()
{
	static ItemDeck itemDeck;
	return itemDeck;
}

std::vector<Item*> ItemDeck::generateItems()
{
	std::random_device rd;
	std::mt19937 gen{ rd() };
	std::ranges::shuffle(m_itemsDataBase, gen);

	std::vector<Item*> items;

	std::for_each(m_itemsDataBase.begin(), m_itemsDataBase.begin() + StartItemsCount, [&items](auto &ptr)
	{
	    items.push_back(ptr.get());
	});
	std::for_each(m_itemsStatus.begin(), m_itemsStatus.begin() + StartItemsCount, [](auto &ptr)
	{
	    ptr = StatusDeck::InUse;
	});

	return items;
}

Item* ItemDeck::generateItem()
{
	return algorithm::getUnUsedItem(m_itemsDataBase, m_itemsStatus);
}

void ItemDeck::createItems(const DeckData &cards)
{
    for(const Card &card: cards)
		m_itemsDataBase.emplace_back(createItem(card));
}

Item* ItemDeck::createItem(const Card& card) const
{
    if(card.at(0) == "Weapon")
        return new Weapon{card.at(1),std::stoi(card.at(2)), card.at(3) };

	if(card.at(0) == "UndeadWeapon")
		return new UndeadWeapon{ card.at(1),std::stoi(card.at(2)), card.at(3) };

    if(card.at(0) == "FireWeapon")
		return new FireWeapon{ card.at(1),std::stoi(card.at(2)) , card.at(3) };

    if(card.at(0) == "SoulWeapon")
		return new SoulWeapon{ card.at(1),std::stoi(card.at(2)) , card.at(3) };

    if(card.at(0) == "HolySword")
		return new HolySword{ card.at(1),std::stoi(card.at(2)) , card.at(3) };

	return new Weapon{"Weapon", 1, "Broken knife"};
}
