#pragma once

class Weapon
{
public:
	virtual std::string getName() const = 0;
	virtual int getDamageRate(int distance) const = 0;
	virtual ~Weapon() = default;
};

class RangedWeapon : public Weapon
{
public:
	int getDamageRate(int distance) const override { return static_cast<int>(getPrecision(distance) * 10); }

private:
	virtual float getPrecision(int distance) const { return 1.0f; }
};

class SniperRifle : public RangedWeapon
{
	std::string getName() const override { return "SniperRifle"; }
	float getPrecision(int distance) const override;
};

class Pistol : public RangedWeapon
{
	std::string getName() const override { return "Pistol"; }
	float getPrecision(int distance) const override;
};

class Shoutgan : public RangedWeapon
{
	std::string getName() const override { return "Shoutgan"; }
	float getPrecision(int distance) const override;
};

class AssaultRifle : public RangedWeapon
{
	std::string getName() const override { return "AssaultRifle"; }
	float getPrecision(int distance) const override;
};

class MeleeWeapon : public Weapon
{
	std::string getName() const override { return "MeleeWeapon"; }
	virtual int damage() const = 0;
	int getDamageRate(int distance) const override
	{
		return damage();
	}
	
};

class BareHand : public MeleeWeapon
{
	std::string getName() const override { return "BareHand"; }
	int damage() const override { return 1;}
};

class Axe : public MeleeWeapon
{
	std::string getName() const override { return "Axe"; }
	int damage() const override { return 3; }
};

class AdamantiumClaws : public MeleeWeapon
{
	std::string getName() const override { return "AdamantiumClaws"; }
	int damage() const override {return 25;}
};
