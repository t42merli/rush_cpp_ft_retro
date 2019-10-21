#ifndef ENEMY_FLEET_CLASS
# define ENEMY_FLEET_CLASS
# include "Define.hpp"
#include "Enemy.class.hpp"

class Game;

class EnemyFleet {
public:
	EnemyFleet();
  	EnemyFleet(EnemyFleet const &copy);
	~EnemyFleet(void);

	EnemyFleet	&operator=(EnemyFleet const &src);
	void newFleet();
	bool isFleetDead() const;
	void moveFleet(int frame);
	void printFleet(WINDOW *win) const;
	void shoot(int frame, Game *game) const;
	Enemy *enemyFleet;
	int size;
private:
	void initializeFleet();

};

#endif
