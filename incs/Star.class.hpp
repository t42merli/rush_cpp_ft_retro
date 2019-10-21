#ifndef STAR_CLASS
#define STAR_CLASS
#include "Define.hpp"

class Star
{
public:
	Star();
	Star(Star const &copy);
	~Star(void);

	Star &operator=(Star const &src);
	void randStat();
	void move(WINDOW *win, int frame);
private:
	int pos[2];
	int speed;
	int color;
};

#endif
