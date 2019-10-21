#ifndef ENEMY_CLASS
#define ENEMY_CLASS
#include "Define.hpp"
#include "Entity.class.hpp"

class Game;
class Enemy : public Entity
{
public:
	Enemy(int x = 0, int y = 0);
	Enemy(Enemy const &copy);
	~Enemy(void);

	Enemy &operator=(Enemy const &src);
	void setValue(int x, int y, int type);
	virtual void getHit(Game *game);
	void printEntity(WINDOW *win) const;
	void shoot(int frame, Game *game) const;

private:
	int type;
};

#endif
