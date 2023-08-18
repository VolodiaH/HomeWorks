#pragma once
#include <string>
#include <iostream>
#include <vector>
#include <list>

class Weapon
{
public:
    Weapon() = default;
    Weapon(std::string title, const int damage, const int range);

    Weapon(Weapon &&weapon) noexcept;

    friend std::ostream &operator<<(std::ostream &os, const Weapon &weapon);

private:
    std::string m_title;
    int m_damage{};
    int m_range{};

};

class Player;
class Team
{
public:
	explicit Team(std::string title);

    std::string title() const;

    void addPlayer(Player *player);
    void removePlayer(Player *player);

private:
    std::string m_title;
    std::list<Player *> m_players;
};

class Player
{

public:
    enum class PlayerType {
        Assault,
        Support,
        Sniper,
        Medic };

    Player(std::string name, const int health, const PlayerType type);

    void addWeapon(Weapon &weapon);

    std::string name() const { return m_name; }
    void setTeam(Team *team) { m_team = team; }

    friend std::ostream &operator<<(std::ostream &os, const Player &player);

    static constexpr int FullHp{ 100 };

private:
    
    const std::string &getType(PlayerType type) const;

    std::string m_name;
    int m_health{ FullHp };
    PlayerType m_type{ PlayerType::Assault};
    std::vector<Weapon> m_weapons;
    Team *m_team{ nullptr };

	const std::string m_types[4]={ "Assault",
                                 "Support",
                                 "Sniper",
                                 "Medic" };

};

std::ostream &operator<<(std::ostream &os, const Player &player);
std::ostream &operator<<(std::ostream &os, const Weapon &weapon);
