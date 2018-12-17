#pragma once
#include "Object.h"
#include "wx\dcbuffer.h"
#include <ctime>
#include <cstdlib>
#include "PowerUp.h"
using namespace std;

class PowerUp;
class Ball;

class Block : public Object
{
protected:
	int l, t;
	int health;
	vector<Object*> *allObj; 
	vector<PowerUp*> *allPowerUps;
	Ball *ball;
	PowerUp *powerUp;
	int blockLv;
	wxBitmap *block = nullptr;
	wxBitmap *weekBlock = nullptr;
	virtual void loadBitmap();
	int getRandNum(int x);
public:
	
	Block(int x, int y, int l, int t, int w, int h, int lv, vector <PowerUp*> *allPowerUps, vector<Object*> *allObj);
	~Block();
	void check();
	int checkCollision(Object* other);
	
	int getL();
	int getT();
	
	void beingHit(Object* other);
	bool isAlive();
	void draw(wxBufferedPaintDC &pdc);
	void launchPwrUp();
	wxBitmap getBitmap();
};