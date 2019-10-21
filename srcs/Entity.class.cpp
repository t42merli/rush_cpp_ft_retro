#include "Define.hpp"
#include "Entity.class.hpp"
#include "Game.class.hpp"

Entity::Entity(int x, int y, int hitbox) : hitbox(hitbox), speed(16), alive(true), shootRate(500)
{
	this->pos[0] = x;
	this->pos[1] = y;
	this->direction[0] = 0;
	this->direction[1] = 0;
}

Entity::Entity(Entity const &copy)
{
	*this = copy;
	return;
}

Entity::~Entity(void)
{
	return;
}

void Entity::setDirection(int direction[2])
{
	this->direction[0] = direction[0];
	this->direction[1] = direction[1];
}

Entity &Entity::operator=(Entity const &src)
{
	this->pos[0] = src.pos[0];
	this->pos[1] = src.pos[1];
	this->speed = src.speed;
	this->direction[0] = src.direction[0];
	this->direction[1] = src.direction[1];
	this->rpz = src.rpz;
	this->isAlly = src.isAlly;
	return *this;
}

void Entity::move(int frame)
{
	if (frame % this->speed != 0)
		return;
	this->pos[0] += this->direction[0];
	this->pos[1] += this->direction[1];
	if (this->pos[0] <= 0 || this->pos[1] <= 0 || this->pos[1] >= WIN_SIZEY)
	{
		this->alive = false;
	}
}

void Entity::printEntity(WINDOW *win) const
{
	int i = 0;
	std::stringstream s(this->rpz);
	std::string output;

	wattron(win, COLOR_PAIR(this->isAlly ? 1 : 2));
	while (!s.eof())
	{
		getline(s, output);
		mvwprintw(win, this->pos[1] + i, this->pos[0], output.c_str());
		i++;
	}
	wattroff(win, COLOR_PAIR(this->isAlly ? 1 : 2));
}

bool Entity::isAlive() const
{
	return this->alive;
}

void Entity::getHit(Game *game)
{
	game->score += 3;
}
