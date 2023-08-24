
#include "Victory.h"

#include "Monster.h"

int VictoryAdditionalCards::apply(Monster* monster)
{
    const unsigned monsterLvl = monster->getLevel();

    if(monsterLvl > 20)
        return 4;
    if(monsterLvl > 10)
        return 3;
    if(monsterLvl > 8)
        return 2;

    return 1;

}
