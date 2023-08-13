#pragma once
#include <string>

class PlayerClass
{
	//FEEL free to add other unique properties
public:
	virtual ~PlayerClass() = default;

	virtual float getDamageMultiplier() const = 0;
	virtual float getDefenseMultiplier() const = 0;
};

class DefaultClass : public PlayerClass
{
	float getDamageMultiplier() const override { return 1.0f; }
	float getDefenseMultiplier() const override { return 1.0f; }
};

class DefenderClass : public DefaultClass
{
	//Leave damage multiplier as is
	float getDefenseMultiplier() const override { return 1.2f; }
};

class AttackerClass: public DefaultClass
{
	float getDamageMultiplier() const override { return 1.2f; }
};
