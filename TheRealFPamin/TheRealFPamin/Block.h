#pragma once
#include "Object.h"

class Ball;

class Block : public Object
{
private:
	int l, t;
	int health;
	vector<Object*> *allObj;
	Ball *ball;
	int blockLv;
public:
	
	Block(int x, int y, int w, int h, int lv, vector<Object*> *allObj);
	~Block();
	void check();
	int checkCollision(Object* other);
	
	int getL();
	int getT();
	
	void beingHit(Object* other);
	bool isAlive();
	void draw(wxBufferedPaintDC &pdc);

};