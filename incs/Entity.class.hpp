#ifndef ENTITY_CLASS
#define ENTITY_CLASS
#include "Define.hpp"

class Game;
class Entity
{
public:
	Entity(int x = 0, int y = 0, int hitbox = 0);
	Entity(Entity const &copy);
	virtual ~Entity(void);

	Entity &operator=(Entity const &src);
	void setDirection(int direction[2]);
	void printEntity(WINDOW *win) const;
	void move(int frame);
	virtual void getHit(Game *game);
	bool isAlive(void) const;
	bool isAlly;
	int pos[2];
	int hitbox;

protected:
	std::string rpz;
	//Object position on the grid
	//Object deplacement
	int speed;
	int direction[2]; //type à definir
	bool alive;
	int shootRate;
};

#endif
