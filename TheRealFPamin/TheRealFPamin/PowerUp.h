#pragma once
#include "Object.h"
#include "vector"
#include "wx\wx.h"
using namespace std;

class Block;
//class Board;


class PowerUp :
	public Object
{
private:
	int l, t;
	int damage{ 1 };
	bool alive = true;
	wxBitmap *bullet = nullptr;
	void loadBitmap();
	Block *block;
	int *score;
	wxTimer *timer;
	DECLARE_EVENT_TABLE()
	bool launched = false;
	
	friend class Block;
public:
	PowerUp(int x, int y, int w, int h, int *score ,Block *block, vector<Object*> *allObj);
	~PowerUp();
	virtual void move();
	bool isAlive();
	wxBitmap getBitmap();
	void draw(wxBufferedPaintDC & pdc);

	int getRandNum(int x);

	void onTimer(wxTimerEvent &event);
	int checkCollision(Object * other);
	void follow();
	bool isLaunched();
	void launch();
	void shout();
	bool alreadyHit = false;
};

