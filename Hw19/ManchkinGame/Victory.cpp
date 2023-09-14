
#include "Victory.h"

#include "Modifier.h"
#include "ModifierDeck.h"
#include "Munchkin.h"
#include "Monster.h"

void VictoryAdditionalCards::apply(Monster *monster, Munchkin *munchkin)
{
    const unsigned monsterLvl = monster->getLevel();

    size_t countCards{1};

    if(monsterLvl > 20)
        countCards = 4;
    if(monsterLvl > 10)
        countCards = 3;
    if(monsterLvl > 8)
        countCards = 2;

    std::vector<Modifier *> modifiers;
    modifiers.reserve(countCards );

    for (size_t i{}; i < countCards; ++i)
        modifiers.emplace_back(ModifierDeck::instance().generateModifier());

    munchkin->addModifiers(modifiers);

}
