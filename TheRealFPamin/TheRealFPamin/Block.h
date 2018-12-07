#pragma once
#include "Object.h"

class Block : public Object
{
private:
	int l, t;
	int health;
	vector<Object*> *allObj;
public:
	
	Block(int x, int y, int w, int h, vector<Object*> *allObj);
	~Block();
	void check();
	int checkCollision(Object* other);
	
	int getL();
	int getT();
	
	void beingHit(Object* other);
	bool isAlive();
	void draw(wxBufferedPaintDC &pdc);

};