#include "Define.hpp"
#include "Missile.class.hpp"
#include "Entity.class.hpp"
#include "Game.class.hpp"

Missile::Missile()
{
	this->alive = false;
}

Missile::Missile(Missile const &copy) : Entity(copy)
{
	return;
}

Missile::~Missile(void)
{
	return;
}

void Missile::init(int x, int y, bool ally, int type)
{
	this->rpz = "=";
	this->hitbox = 1;
	this->alive = true;
	this->pos[0] = x;
	this->pos[1] = y;
	this->isAlly = ally;
	this->speed = ally ? 16 : 32;
	this->direction[0] = 0;
	this->direction[1] = 0;
	if (ally)
	{
		this->direction[0] = 1;
		return;
	}
	if (type == 1)
		this->direction[0] = -1;
	if (type == 2 || type == 3)
		this->direction[0] = -2;
	if (type == 2)
		this->direction[1] = 1;
	if (type == 3)
		this->direction[1] = -1;
}

void Missile::getHit(Game *game)
{
	this->alive = false;
	game->score += 0;
}

Missile &Missile::operator=(Missile const &src)
{
	Entity::operator=(src);
	return *this;
}

int Missile::move(int frame)
{
	if (frame % this->speed != 0)
		return 1;
	this->pos[0] += this->direction[0];
	this->pos[1] += this->direction[1];
	if (this->pos[0] <= 0 || this->pos[0] >= WIN_SIZEX || this->pos[1] <= 0 || this->pos[1] >= WIN_SIZEY)
	{
		this->alive = false;
	}
	return 1;
}
