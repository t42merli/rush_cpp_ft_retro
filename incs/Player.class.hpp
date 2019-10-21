#ifndef PLAYER_CLASS
#define PLAYER_CLASS
#include "Define.hpp"
#include "Entity.class.hpp"

class Game;
class Player : public Entity
{
public:
	Player();
	Player(Player const &copy);
	~Player(void);

	Player &operator=(Player const &src);
	void move(int input);
	void printEntity(WINDOW *win);
	void getHit(Game *game);

	int hp;
	void shoot(int frame, Game *game) const;

private:
	void up(void);
	void down(void);
	void right(void);
	void left(void);
	int moved;
	void flicker(WINDOW *win) const;
};

#endif
