#pragma once
#include "Object.h"
#include "wx\dcbuffer.h"

class Ball;

class Block : public Object
{
protected:
	int l, t;
	int health;
	vector<Object*> *allObj;
	Ball *ball;
	int blockLv;
	wxBitmap *block = nullptr;
	wxBitmap *weekBlock = nullptr;
	virtual void loadBitmap();
public:
	
	Block(int x, int y, int l, int t, int w, int h, int lv, vector<Object*> *allObj);
	~Block();
	void check();
	int checkCollision(Object* other);
	
	int getL();
	int getT();
	
	void beingHit(Object* other);
	bool isAlive();
	void draw(wxBufferedPaintDC &pdc);

	wxBitmap getBitmap();

};