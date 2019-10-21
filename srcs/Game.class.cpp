#include "Define.hpp"
#include "Game.class.hpp"

int Game::update(int input, int frame)
{
	if (input == 27)
		return -1;
	this->player->move(input);
	this->fleet->moveFleet(frame);
	this->moveMissiles(frame);
	this->player->shoot(frame, this);
	this->fleet->shoot(frame, this);
	this->newFleet();
	this->initMap();
	if (frame % 16 == 0)
	{
		wclear(this->win);
		for (int i = 0; i < 15; i++)
			this->stars[i].move(win, frame);
		box(this->win, ACS_VLINE, ACS_HLINE);
		mvwprintw(this->win, 0, 25, this->displayScore().c_str());
		this->player->printEntity(this->win);
		this->fleet->printFleet(this->win);
		this->printMissiles();
		wrefresh(this->win);
	}
	collisionCheck();
	return this->player->hp;
}

Game::Game()
{
	this->win = newwin(WIN_SIZEY, WIN_SIZEX, 1, 1);
	nodelay(this->win, true);
	keypad(this->win, true);
	this->player = new Player();
	this->fleet = new EnemyFleet();
	this->score = 0;
	this->startTime = time(NULL);
	this->stars = new Star[15];
	this->missiles = new Missile[100];
}

Game::Game(Game const &copy)
{
	*this = copy;
	return;
}

Game::~Game(void)
{
	delete[] this->missiles;
	delete[] this->stars;
	delete this->player;
	delete this->fleet;
	delwin(this->win);
}

Game &Game::operator=(Game const &src)
{
	this->player = src.player;
	this->fleet = src.fleet;
	this->stars = src.stars;
	this->startTime = src.startTime;
	this->score = src.score;
	return *this;
}

void Game::initMap()
{
	for (int i = 0; i < WIN_SIZEX; i++)
		for (int n = 0; n < WIN_SIZEY; n++)
			this->map[i][n] = NULL;
}

void Game::fillMap(Entity *ent)
{
	if (!ent->isAlive())
		return;
	for (int i = 0; i < ent->hitbox && i < WIN_SIZEX; i++)
	{
		for (int n = 0; n < ent->hitbox && i < WIN_SIZEY; n++)
		{
			if (this->map[ent->pos[0] + i][ent->pos[1] + n] != NULL)
				collide(ent, this->map[ent->pos[0] + i][ent->pos[1] + n]);
			this->map[ent->pos[0] + i][ent->pos[1] + n] = ent;
		}
	}
}

void Game::collisionCheck()
{
	for (int n = 0; n < 100; n++)
		if (this->missiles[n].isAlive())
			fillMap(&this->missiles[n]);
	fillMap(this->player);
	for (int i = 0; i < this->fleet->size; i++)
		fillMap(&this->fleet->enemyFleet[i]);
}

void Game::collide(Entity *ent1, Entity *ent2)
{
	if (ent1 == NULL || ent2 == NULL || !ent1->isAlive() || !ent2->isAlive() || ent1->isAlly == ent2->isAlly)
		return;

	ent1->getHit(this);
	ent2->getHit(this);
}

void Game::AddMissile(int x, int y, bool ally, int type)
{
	for (int n = 0; n != 100; n++)
	{
		if (!this->missiles[n].isAlive())
		{
			this->missiles[n].init(x, y, ally, type);
			return;
		}
	}
}

void Game::newFleet()
{
	if (this->fleet->isFleetDead())
		this->fleet->newFleet();
}

void Game::moveMissiles(int frame)
{
	int i = 0;
	while (i < 100)
	{
		if (this->missiles[i].isAlive()) {
			this->missiles[i].move(frame);
		}
		i++;
	}
}

void Game::printMissiles() const
{
	int i = 0;
	while (i < 100)
	{
		if (this->missiles[i].isAlive())
			this->missiles[i].printEntity(this->win);
		i++;
	}
}

std::string Game::displayScore()
{
	std::string Result;
	std::ostringstream convert;
	convert << "  Score : " << this->score << " - Player life : " << this->player->hp
			<< " - Time : " << time(NULL) - this->startTime << " s  ";
	Result = convert.str();
	return (Result);
}
