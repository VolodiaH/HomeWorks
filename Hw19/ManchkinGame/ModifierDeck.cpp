
#include "ModifierDeck.h"

#include <algorithm>

#include "Modifier.h"
#include "MyAlgorithm.h"

ModifierDeck::ModifierDeck()
{
	m_modifiersDatabase.emplace_back(new SimpleModifier{ 3 });
	m_modifiersDatabase.emplace_back(new SimpleModifier{ 3 });
	m_modifiersDatabase.emplace_back(new SimpleModifier{ 2 });
	m_modifiersDatabase.emplace_back(new SimpleModifier{ 2});
	m_modifiersDatabase.emplace_back(new SimpleModifier{ 4});
	m_modifiersDatabase.emplace_back(new SimpleModifier{ 1});
	m_modifiersDatabase.emplace_back(new SimpleModifier{ 1});
	m_modifiersDatabase.emplace_back(new SimpleModifier{ 1});
	m_modifiersDatabase.emplace_back(new SimpleModifier{ 1});
	m_modifiersDatabase.emplace_back(new DoubleMunchkinLevel{});
	m_modifiersDatabase.emplace_back(new DoubleMunchkinLevel{});
	m_modifiersDatabase.emplace_back(new HalvesMonsterLevel{ Tribe::Undead });
	m_modifiersDatabase.emplace_back(new HalvesMonsterLevel{ Tribe::God });

}

ModifierDeck& ModifierDeck::instance()
{
	static ModifierDeck modifierDeck;
	return modifierDeck;
}

Modifier* ModifierDeck::generateModifier() 
{
	// It will be always unique. because we create it in run-time!(Evil laughter)
	m_modifiersDatabase.emplace_back(createRandomModifier());
	return m_modifiersDatabase.back().get();
}

Modifier* ModifierDeck::createRandomModifier()
{
	int randClas = algorithm::randomNumber(1,4);

    switch (randClas)
    {
        case 1:
        {
			return new DoubleMunchkinLevel();
        }
        case 2:
        {
            int randTribe = algorithm::randomNumber(0, static_cast<int>(Tribe::Demons));
			return new HalvesMonsterLevel(static_cast<Tribe>(randTribe));
        }case 3:
        {
			return new ThanosGauntlet();
        }
		default:
			return new SimpleModifier(algorithm::randomNumber(1, 10));
    }

}
