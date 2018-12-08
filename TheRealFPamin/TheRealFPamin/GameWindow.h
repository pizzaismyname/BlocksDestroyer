#pragma once
#include "wx\wx.h"
#include "Frame.h"

//#include "iostream"
#include<vector>
using namespace std;

class Ball;
class Block;
class Board;
class Object;

class GameWindow :
	public wxWindow
{
protected:
	int w, h;
	wxTimer *timer;
	Ball *ball;
	Block *block;
	Board *board;
	bool gameOver = false;
	vector <Object*> allObj;
	vector <Block*> allBlocks;

	DECLARE_EVENT_TABLE()
public:
	GameWindow(wxFrame *parent);
	~GameWindow();
	void onTimer(wxTimerEvent &event);
	void onPaint(wxPaintEvent &event);
	void onKeyDown(wxKeyEvent &event);
	void onKeyUp(wxKeyEvent &event);
	void gameIsOver();
	void gameIsNotOver();
	void resetBallBoard();
};

