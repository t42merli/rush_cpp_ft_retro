#ifndef MISSILE_CLASS
#define MISSILE_CLASS
#include "Define.hpp"
#include "Entity.class.hpp"
class Missile : public Entity
{
public:
	Missile();
	Missile(Missile const &copy);
	~Missile(void);

	void init(int x = 0, int y = 0, bool ally = true, int type = 0);

	Missile &operator=(Missile const &src);
	void getHit(Game *game);
	int move(int frame);

private:
};

#endif
