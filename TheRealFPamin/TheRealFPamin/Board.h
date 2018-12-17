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
	wxTimer *timer2;
	wxTimer *revControlTimer;
	wxTimer *shootSkillTimer;
	Bullet *bullet;

	int reverse = 1;

	vector<Bullet*> *allBullets;
	DECLARE_EVENT_TABLE()
	friend class PowerUp;
public:
	Board(int x, int y, int w, int h, vector<Object*> *allObj, vector<Bullet*> *allBullets);
	int getHealth();
	void setHealth(int health);
	bool isAlive();
	void draw(wxBufferedPaintDC &pdc);
	void move();
	void moveLeft();
	void moveRight();
	void stopMove();
	void beingHit(Object * other);
	void onTimer(wxTimerEvent & event);
	void onTimer2(wxTimerEvent & event);
	void onRevControlTimer(wxTimerEvent & event);
	void onShootSkillTimer(wxTimerEvent & event);
	bool isHit = false;
	int getL();
	int getT();
	int powerUpType = 0;
	void poweredUp(int x);
	bool gunActive = false;
	bool skillActive = false;
	bool isSkillActive();
	void shoot();

	void activateGun();

	void deactivateGun();
	
	wxBitmap getBitmap();
	~Board();
};

