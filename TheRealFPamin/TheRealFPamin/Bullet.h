#pragma once
#include "Object.h"
#include "vector"
using namespace std;

//class Board;


class Bullet :
	public Object
{
private:
	int l, t;
	int damage{1};
	bool alive = true;
	wxBitmap *bullet = nullptr;
	void loadBitmap();
	//Board board;
	bool launched = false;
	wxTimer *timer;
	DECLARE_EVENT_TABLE()
public:
	Bullet(int x, int y, int w, int h, vector<Object*> *allObj);
	~Bullet();
	virtual void move();
	bool isAlive();
	wxBitmap getBitmap();
	void draw(wxBufferedPaintDC & pdc);
	
	void onTimer(wxTimerEvent &event);
};

