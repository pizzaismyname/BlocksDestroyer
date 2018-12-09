#pragma once
#include "wx\wx.h"
#include "wx\dcbuffer.h"
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

class Object : public wxEvtHandler
{
protected:
	int x, y, vX, vY, dirX, dirY, maxX, maxY, r, g, b, type;
	vector<Object*> *allObj;
	
public:
	
	Object(int x, int y, int w, int h, vector<Object*> *allObj);
	~Object();
	
	virtual void setVx(int x);
	virtual void setVy(int y);
	void changeDirX();
	void changeDirY();
	int getType();
	int getX();
	int getY();
	void setX(int x);
	void setY(int y);
	int getDirY();
	int getDirX();


	virtual void move();
	virtual void draw(int x, int y, int w, int h, vector<Object*> *allObj);

	virtual void check();
	virtual int checkCollision(Object* other);
	virtual bool isInside(int x, int y);
	virtual bool isNear(int x, int y);

	
};