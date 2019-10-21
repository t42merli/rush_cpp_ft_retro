#ifndef GAME_CLASS
#define GAME_CLASS
#include "Define.hpp"
#include "Missile.class.hpp"
#include "EnemyFleet.class.hpp"
#include "Player.class.hpp"
#include "Star.class.hpp"

class Game
{
public:
	Game();
	Game(Game const &copy);
	~Game(void);

	WINDOW *win;

	Game &operator=(Game const &src);
	int update(int input, int frame);
	void AddMissile(int x, int y, bool ally, int type = 0);
	std::string displayScore();
	int score;

private:
	void collisionCheck();
	void fillMap(Entity *ent);
	void collide(Entity *ent1, Entity *ent2);
	void initMap();

	time_t startTime;
	Player *player;
	EnemyFleet *fleet;
	Missile *missiles;
	Star *stars;
	Entity *map[WIN_SIZEX][WIN_SIZEY];
	void newFleet();
	void printMissiles() const;
	void moveMissiles(int frame);
};

#endif
