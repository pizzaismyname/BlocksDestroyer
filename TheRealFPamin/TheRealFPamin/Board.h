#pragma once
#include "Object.h"

class Board :
	public Object
{
protected:
	int l, t, health{3};
public:
	Board(int x, int y, int w, int h, vector<Object*> *allObj);
	int getHealth();
	void setHealth(int health);
	bool isAlive();
	void draw(wxBufferedPaintDC &pdc);
	void move();
	void moveLeft();
	void moveRight();
	void stopMove();
	void beingHit();
	~Board();
};

