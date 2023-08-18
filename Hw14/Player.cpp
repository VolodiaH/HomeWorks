#include "Player.h"

Weapon::Weapon(std::string title, const int damage, const int range):
    m_title{std::move(title)},
    m_damage{damage},
    m_range{range}
{
}

Weapon::Weapon(Weapon &&weapon) noexcept :
m_title(std::move(weapon.m_title)),
m_damage(weapon.m_damage),
m_range(weapon.m_range)
{
    weapon.m_damage = 0;
    weapon.m_range = 0;
}

std::ostream &operator<<(std::ostream &os, const Weapon &weapon)
{
    os << "Title: " << weapon.m_title << "\n";
    os << "Damage: " << weapon.m_damage << "\n";
    os << "Range: " << weapon.m_range << "\n";

    return os;
}

Team::Team(std::string title):
    m_title{std::move(title)}
{
}

std::string Team::title() const
{
	return m_title;
}

void Team::addPlayer(Player* player)
{
    player->setTeam(this);
    m_players.push_back(player);
}

void Team::removePlayer(Player* player)
{
    const auto it = std::ranges::find_if(m_players, player);

    if (it != std::end(m_players))
    {
        (*it)->setTeam(nullptr);
        m_players.erase(it);
    }
}

Player::Player(std::string name, const int health, const PlayerType type):
    m_name{std::move(name)},
    m_health{health},
    m_type{type}
{
}

void Player::addWeapon(Weapon &weapon)
{
    m_weapons.emplace_back(std::move(weapon));
}

const std::string& Player::getType(PlayerType type) const 
{
    return m_types[static_cast<int>(type)];
}

std::ostream &operator<<(std::ostream &os, const Player &player)
{
    os << "Name: " << player.m_name << "\n";
    os << "Health: " << player.m_health << "\n";
    os << "Type: " << player.getType(player.m_type) << "\n";
    os << "Weapon: " << "\n";

    for (auto &w : player.m_weapons)
        os << w;


    if (player.m_team)
        os << "Team: " << player.m_team->title() << "\n";
    else
        os << "No Team" << "\n";

    os << "\n\n";

    return os;
}
