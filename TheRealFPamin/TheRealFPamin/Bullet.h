#pragma once
#include "Object.h"
#include "vector"
using namespace std;

class Bullet :
	public Object
{
private:
	int l, t;
	int damage{1};
	bool alive = true;
	wxBitmap *bullet = nullptr;
	void loadBitmap();
	bool launched = false;
	wxTimer *timer;
	int *score;

public:
	Bullet(int x, int y, int w, int h, int *score, vector<Object*> *allObj);
	~Bullet();
	virtual void move();
	bool isAlive();
	wxBitmap getBitmap();
	void draw(wxBufferedPaintDC & pdc);
	int getDamage();
	void onTimer(wxTimerEvent &event);
	int checkCollision(Object * other);
};

