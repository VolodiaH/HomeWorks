#pragma once

enum class GameMode
{
	Exit,
	WordOfDay,
	Random,
	
};

class GameMenuPrinter
{
public:
	void showMenu() const;

};

class GameMenu
{
public:
	GameMode showMenuGetChoice() const ;

private:
	GameMenuPrinter m_printer;
};

