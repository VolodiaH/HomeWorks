
#pragma once
#include <string>
#include <format>

//forwad declaration
class Munchkin;

class Runaway
{
public:
    virtual ~Runaway() = default;
    virtual void apply(Munchkin* munchkin) = 0;
	virtual std::string getFullInfo() { return ""; }
};

class Runaway_LevelDowngrade : public Runaway
{
public:
	explicit Runaway_LevelDowngrade(int level = 1) : m_levelToDowngrade(level) {}
	void apply(Munchkin* munchkin) override;
	std::string getFullInfo() override { return std::format("Downgrade by {}" , m_levelToDowngrade); }
	int getLevelToDowngrade() const {return m_levelToDowngrade; }
private:
	int m_levelToDowngrade{};
};

class Runaway_LevelDowngradeIf : public Runaway_LevelDowngrade
{
public:
	Runaway_LevelDowngradeIf(int level, int minimalMunchkinLevel) 
		: Runaway_LevelDowngrade(level), m_minimalMunchkinLevelToApply(minimalMunchkinLevel) {}

	void apply(Munchkin* munchkin) override;
	std::string getFullInfo() override { return std::format("Downgrade by {} if your level is bigger or equal {}", getLevelToDowngrade(), m_minimalMunchkinLevelToApply); }
private:
	int m_minimalMunchkinLevelToApply;
};

//Remove a card from hand(modifier) at random
class Runaway_ModifierFromHandRemoval : public Runaway
{
public:
	void apply(Munchkin* munchkin) override;
	std::string getFullInfo() override { return "Remove modifier from hand"; }
};

//Remove equiped item from Outfit with biggest base power
class Runaway_ItemEquipedRemoval : public Runaway
{
public:
	void apply(Munchkin* munchkin) override;
	std::string getFullInfo() override { return "Loose outfit item with the biggest base power"; }
};
