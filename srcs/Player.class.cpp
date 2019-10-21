#include "Define.hpp"
#include "Player.class.hpp"
#include "Missile.class.hpp"
#include "Game.class.hpp"

Player::Player() : Entity(10, 20, 5), moved(0)
{
	this->rpz = " -|- \n / \\\n( o )\n \\ /\n -|-";
	this->isAlly = true;
	this->hp = 3;
}

Player::Player(Player const &copy) : Entity(copy)
{
	return;
}

Player::~Player(void)
{
	return;
}

Player &Player::operator=(Player const &src)
{
	Entity::operator=(src);
	return *this;
}

void Player::getHit(Game *game)
{
	this->hp -= 1;
	this->flicker(game->win);
	game->score -= 30;
}

void Player::printEntity(WINDOW *win)
{
	Entity::printEntity(win);
	this->moved = 0;
}

void Player::up(void)
{
	this->pos[1] = this->pos[1] + 1 + hitbox >= WIN_SIZEY
					   ? this->pos[1]
					   : this->pos[1] + 1;
}

void Player::down(void)
{
	this->pos[1] = this->pos[1] - 1 <= 0
					   ? this->pos[1]
					   : this->pos[1] - 1;
}

void Player::right(void)
{
	this->pos[0] = this->pos[0] + 1 + hitbox >= WIN_SIZEX
					   ? this->pos[0]
					   : this->pos[0] + 1;
}

void Player::left(void)
{
	this->pos[0] = this->pos[0] - 1 <= 0
					   ? this->pos[0]
					   : this->pos[0] - 1;
}

void Player::move(int input)
{
	int moves[4] = {258, 259, 260, 261};
	void (Player::*doMove[4])(void) = {&Player::up,
									   &Player::down,
									   &Player::left,
									   &Player::right};
	int i;

	i = 0;
	if (this->moved == 1)
		return;
	while (i < 4)
	{
		if (moves[i] == input)
		{
			moved = 1;
			(this->*doMove[i])();
		}
		i++;
	}
}

void Player::shoot(int frame, Game *game) const
{
	if (frame % this->shootRate != 0)
		return;
	game->AddMissile(this->pos[0] + this->hitbox, this->pos[1] + this->hitbox / 2, true, 0);
}

void Player::flicker(WINDOW *win) const
{
	int i;
	int j = 0;
	std::stringstream s(this->rpz);
	std::string output;

	while (j < 5)
	{
		i = 0;

		wattron(win, COLOR_PAIR(j % 2 == 0 ? 2 : 1));
		while (!s.eof())
		{
			getline(s, output);
			mvwprintw(win, this->pos[1] + i, this->pos[0], output.c_str());
			i++;
		}
		wattroff(win, COLOR_PAIR(j % 2 == 0 ? 1 : 2));
		s.seekg(0);
		wrefresh(win);
		napms(100);
		j++;
	}
}