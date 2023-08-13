#pragma once

class Weapon
{
public:
	//TODO: Feel free to add other properties
	//Or use another approach for damage calculation:
	//health, stamina, weight, level, speed or whatever you have in mind.
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
	float getPrecision(int distance) const override;
};

//TODO
class Pistol : public RangedWeapon
{
	float getPrecision(int distance) const override;
};

//TODO
class AssaultRifle : public RangedWeapon
{
	float getPrecision(int distance) const override;
};

class MeleeWeapon : public Weapon
{
	virtual int damage() const = 0;
	int getDamageRate(int distance) const override
	{
		return damage();
	}
	
};

class BareHand : public MeleeWeapon
{
	int damage() const override { return 1;}
};

class Axe : public MeleeWeapon
{
	int damage() const override { return 3; }
};

class AdamantiumClaws : public MeleeWeapon
{
	int damage() const override {return 25;}
};
