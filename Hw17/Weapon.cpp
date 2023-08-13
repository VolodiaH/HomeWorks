#include "Weapon.h"

float SniperRifle::getPrecision(int distance) const
{
	if (distance > 2000)
	{
		return 0.2f;
	}
	if (distance > 1000)
	{
		return 1.5f;
	}
	if (distance > 300)
	{
		return 5.0f;
	}
	return 1.0f;
}

float AssaultRifle::getPrecision(int distance) const
{
	if (distance > 500)
	{
		return 1.0f;
	}
	if (distance > 400)
	{
		return 1.5f;
	}
	if (distance > 300)
	{
		return 2.0f;
	}
	return 3.0f;
}

float Pistol::getPrecision(int distance) const
{
	if (distance > 100)
	{
		return 0.1f;
	}
	if (distance > 50)
	{
		return 0.7f;
	}
	if (distance > 15)
	{
		return 0.9f;
	}
	return 1.0f;
}
