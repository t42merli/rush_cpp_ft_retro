#include "Define.hpp"
#include "Enemy.class.hpp"
#include "Missile.class.hpp"
#include "Game.class.hpp"

Enemy::Enemy(int x, int y) : Entity(x, y, 3)
{
	this->isAlly = 0;
	this->speed = 100;
	this->shootRate = rand() % 1500 + 500;
	this->direction[0] = -1;
	this->direction[1] = 0;
}

void Enemy::setValue(int x, int y, int type)
{
	this->pos[0] = x;
	this->pos[1] = y;
	this->type = type;
	if (type == 1)
		this->rpz = "/+\\\n-| \n\\+/";
	if (type == 2)
		this->rpz = "\\ /\n<8>\n/ \\";
	if (type == 3)
		this->rpz = " |/\n<||\n |\\";
}

Enemy::Enemy(Enemy const &copy) : Entity(copy)
{
	return;
}

Enemy::~Enemy(void)
{
	return;
}

void Enemy::getHit(Game *game)
{
	this->alive = false;
	game->score += this->type * 0.2 * 78;
}

Enemy &Enemy::operator=(Enemy const &src)
{
	Entity::operator=(src);
	return *this;
}

void Enemy::printEntity(WINDOW *win) const
{
	if (this->alive)
		Entity::printEntity(win);
}

void Enemy::shoot(int frame, Game *game) const
{
	if (frame % this->shootRate != 0 || !this->alive)
		return;
	game->AddMissile(this->pos[0] + 1, this->pos[1] + 1, false, this->type);

}
