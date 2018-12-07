#pragma once
#include "Object.h"

class Board :
	public Object
{
protected:
	int l, t;
public:
	Board(int x, int y, int w, int h, vector<Object*> *allObj);

	void draw(wxBufferedPaintDC &pdc);
	void move();
	void moveLeft();
	void moveRight();
	void stopMove();
	void beingHit();
	~Board();
};

