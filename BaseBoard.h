#pragma once
#include "wx\wx.h"
#include "wx\dcbuffer.h"

class GameWindow;

class BaseBoard
{
protected:
	GameWindow * parent;

	int x{200};
	int y{200};
	int width;
	int height;
	wxBitmap *board = nullptr;
	virtual void loadBitmap();

public:
	BaseBoard();
	~BaseBoard();
	
	wxBitmap getBitmap();

	int getX();
	int getY();
	int getWidth();
	int getHeight();

	void move(char key);

};

