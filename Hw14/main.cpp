#include "Player.h"
#include "Rectangle.h"

int main()
{
    {
        Rectangle rectangle1{ 15.5,75.6 };
        Rectangle rectangle2;

        std::cout << rectangle1.perimeter();
        std::cout << rectangle2.square();
    }

    {
        Player pl1( "Kate", Player::FullHp, Player::PlayerType::Assault);
        Player pl2( "Drew", Player::FullHp, Player::PlayerType::Assault);

        Team teamOrange("Orange");

        Weapon w1( "AR-15", 35, 100 );

        Weapon w2( "HK-416", 40, 100);

        Weapon w3( "HK-417", 55, 150);

        pl1.addWeapon(w3);
        pl1.addWeapon(w2);
    
        pl2.addWeapon(w1);

        teamOrange.addPlayer(&pl1);
        teamOrange.addPlayer(&pl2);

        std::cout << pl1 << pl2 << "\n";

        teamOrange.removePlayer(&pl2);

        std::cout << pl1 << pl2 << "\n";
    }
}