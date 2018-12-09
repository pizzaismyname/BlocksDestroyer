#pragma once
#include "Object.h"
#include "wx\dcbuffer.h"
#include "wx\wx.h"

class Bullet;

class Board :
	public Object
{
protected:
	int l, t, health{3};
	wxBitmap *board1 = nullptr;
	wxBitmap *board2 = nullptr;
	wxBitmap *board3 = nullptr;
	wxBitmap *board = nullptr;
	virtual void loadBitmap();
	wxTimer *timer;
	Bullet *bullet;
	DECLARE_EVENT_TABLE()
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
	void onTimer(wxTimerEvent & event);

	void shoot();
	
	wxBitmap getBitmap();
	~Board();
};

