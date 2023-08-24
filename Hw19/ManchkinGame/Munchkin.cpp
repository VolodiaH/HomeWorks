
#include "Munchkin.h"
#include "Modifier.h"
#include "MyAlgorithm.h"

void Munchkin::updateLevelBy(int levels)
{
    if (m_level + levels <= 0)
    {
        m_level = 1;
    }
    else
    {
	    m_level += levels; 
    }

}

void Munchkin::addItem(Item* item)
{
    m_items.emplace_back(item);
}

void Munchkin::addItems(std::vector<Item*> items)
{
    m_items = std::move(items);
}

const std::vector<Item*>& Munchkin::getItems() const
{
    return m_items;
}

void Munchkin::removeModifierFromHand()
{
    if (!m_modifiers.empty())
    {
        const int size = static_cast<int>(m_modifiers.size()) - 1;
        const int rand = algorithm::randomNumber(0, size);

        if (rand != size)
            std::swap(m_modifiers[rand], m_modifiers[size]);
        m_modifiers.pop_back();
    }
}

void Munchkin::removeItemEquipped()
{
    if (!m_items.empty())
    {
        const int size = static_cast<int>(m_items.size()) - 1;
        const int rand = algorithm::randomNumber(0, size);

        if(rand != size)
            std::swap(m_items[rand], m_items[size]);
        m_items.pop_back();
    }
}

void Munchkin::removeItemEquippedByBiggestPower()
{
    if(!m_items.empty())
    {
        auto it = std::ranges::max_element(m_items, [](auto &left, auto &right){ return left->getBasePower() < right->getBasePower(); });
        m_items.erase(it);
    }
}

Modifier* Munchkin::popModifier(int idx)
{
    if (idx >= m_modifiers.size() || idx < 0)
    {
        return nullptr;
    }

    Modifier* modifier = m_modifiers[idx];
    m_modifiers.erase(m_modifiers.begin() + idx);
    return modifier;

}

