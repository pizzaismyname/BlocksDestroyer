#pragma once
#include "wx\wx.h"
class Bullet
{
protected:
	int damage;
	int speed;
	bool hapus;
	int width;
	int height;
	wxBitmap *bulletPtr = nullptr;
	void loadBitmap();
	int x;
	int y;
public:
	Bullet();
	Bullet(int x, int y);
	~Bullet();

	wxBitmap getBitmap();
	int getDamage();
	int getSpeed();
	int getWidth();
	int getHeight();
	bool getDiHapus();
	int getX();
	int getY();

	virtual void move();
	virtual void hit();
};

