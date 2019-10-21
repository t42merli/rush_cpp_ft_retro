#include "Define.hpp"
#include "Star.class.hpp"


Star::Star()
{
	randStat();
}

Star::Star(Star const &copy)
{
	*this = copy;
	return;
}

Star::~Star(void)
{
	return;
}

void	Star::randStat() {
	std::srand(std::time(NULL) * rand());

	this->pos[0] = WIN_SIZEX + std::rand() % 30;
	this->pos[1] = std::rand() % (WIN_SIZEY) + 1;
	this->speed = std::rand() % 5 + 1;
	this->color = std::rand() % 3 + 3;
}

Star	&Star::operator=(Star const &src) {
	this->pos[0] = src.pos[0];
	this->pos[1] = src.pos[1];
	this->speed = src.speed;
	return *this;
}

void	Star::move(WINDOW *win, int frame)
{
	if (this->pos[0] < 0)
		this->randStat();
	if (frame % speed == 0)
		this->pos[0] -= 1;
	wattron(win, COLOR_PAIR(this->color));
	mvwprintw(win, this->pos[1], this->pos[0], "*");
	wattroff(win, COLOR_PAIR(this->color));
}
