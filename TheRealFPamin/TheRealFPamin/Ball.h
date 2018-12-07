#pragma once
#include "Object.h"
#include <cmath>
#include "GameWindow.h"

class Board;

class Ball :
	public Object
{
private:
	int r;
	bool launched = false;
	vector<Object*> *allObj;
	int damage = 1;
public:
	Ball(int x, int y, int w, int h, vector<Object*> *allObj);

	~Ball();
	void draw(wxBufferedPaintDC &pdc);
	bool isLaunched();
	void launch();
	void unLaunch();
	void move(GameWindow *window);
	void follow(Board *board);
	double distance(int x, int y);
	void check();
	int checkCollision(Object* other);
	int getR();
	void setDirX(int dirX);
	void setDirY(int dirY);
	void setVx(int x);
	void setVy(int y);
	double gradien(int x, int y, int x1, int y1);
	int getDamage();
};

