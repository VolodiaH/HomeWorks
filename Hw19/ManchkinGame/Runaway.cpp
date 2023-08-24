
#include "Runaway.h"
#include "Munchkin.h"

void Runaway_LevelDowngrade::apply(Munchkin* munchkin)
{
	munchkin->updateLevelBy(-m_levelToDowngrade);
}

void Runaway_LevelDowngradeIf::apply(Munchkin* munchkin)
{
	if (munchkin->getLevel() >= m_minimalMunchkinLevelToApply)
	{
		Runaway_LevelDowngrade::apply(munchkin);
	}
}

void Runaway_ModifierFromHandRemoval::apply(Munchkin* munchkin)
{
	munchkin->removeModifierFromHand();
}

void Runaway_ItemEquipedRemoval::apply(Munchkin* munchkin)
{
	munchkin->removeItemEquippedByBiggestPower();
}
