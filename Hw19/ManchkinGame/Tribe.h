
#pragma once
#include <string>

enum class Tribe
{
	Human,
	Undead,
	Zombie,
	God,
	Demons
};

inline std::string getTribeString(Tribe tribe)
{
    switch (tribe)
    {
    case Tribe::Human:
        return "Human";
    case Tribe::Undead:
        return "Undead";
    case Tribe::Zombie:
        return "Zombie";
    case Tribe::God:
        return "God";
    case Tribe::Demons:
        return "Demons";
    }
    return "";
}
