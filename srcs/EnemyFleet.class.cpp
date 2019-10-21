#include "Define.hpp"
#include "EnemyFleet.class.hpp"
#include <fstream>

EnemyFleet::EnemyFleet() : size(rand() % (4) + 2)
{

	this->enemyFleet = new Enemy[this->size];
	this->initializeFleet();
}

EnemyFleet::EnemyFleet(EnemyFleet const &copy) : enemyFleet(copy.enemyFleet)
{
	return;
}

EnemyFleet::~EnemyFleet(void)
{
	delete[] this->enemyFleet;
	return;
}

EnemyFleet &EnemyFleet::operator=(EnemyFleet const &src)
{
	this->enemyFleet = src.enemyFleet;
	return *this;
}

bool EnemyFleet::isFleetDead() const
{
	int i = 0;
	while (i < this->size)
	{
		if (this->enemyFleet[i].isAlive())
			return false;
		i++;
	}
	return true;
}

void EnemyFleet::newFleet()
{
	delete[] this->enemyFleet;
	this->size = rand() % 4 + 1;
	this->enemyFleet = new Enemy[this->size];
	this->initializeFleet();
}

void EnemyFleet::initializeFleet()
{

	int i = 0;
	while (i < this->size)
	{
		this->enemyFleet[i].setValue(WIN_SIZEX - rand() % 17 - 3, i * WIN_SIZEY / this->size + 2, rand() % 3 + 1);
		i++;
	}
}

void EnemyFleet::printFleet(WINDOW *win) const
{
	int i = 0;
	while (i < this->size)
	{
		this->enemyFleet[i].printEntity(win);
		i++;
	}
}

void EnemyFleet::moveFleet(int frame)
{
	int i = 0;
	while (i < this->size)
	{
		if (this->enemyFleet[i].isAlive())
			this->enemyFleet[i].move(frame);
		i++;
	}
}

void EnemyFleet::shoot(int frame, Game *game) const
{
	int i = 0;
	while (i < this->size)
	{
		this->enemyFleet[i].shoot(frame, game);
		i++;
	}
}
