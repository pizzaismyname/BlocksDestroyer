#pragma once
#include "wx\wx.h"
#include "Frame.h"
#include "Bullet.h"
#include "PowerUp.h"
#include<vector>
using namespace std;

class Ball;
class Block;
class Board;
class Object;
class Level;
class Bullet;
class PowerUp;

class GameWindow :
	public wxWindow
{
protected:
	Frame *parent;
	int w, h;
	wxTimer *timer;
	Ball *ball;
	Block *block;
	Board *board;
	Bullet *bullet;
	PowerUp *powerUp;
	bool gameOver = false;
	vector <Object*> allObj;
	vector <Block*> allBlocks;
	vector <Bullet*> allBullets; 
	vector <PowerUp*> allPowerUps;
	bool paused = false;
	int score;

	
	wxBitmap *pauseScreen = nullptr;
	wxBitmap *gameOverScreen = nullptr;
	void loadBitmap();

	wxBitmap *resumeImg = nullptr;
	wxBitmap *mainMenuImg = nullptr;
	wxBitmap *resumeHoverImg = nullptr;
	wxBitmap *mainMenuHoverImg = nullptr;
	wxBitmap *restartImg = nullptr;
	wxBitmap *restartHoverImg = nullptr;

	wxBitmapButton *resumeBtn;
	wxBitmapButton *mainMenuBtn;
	wxBitmapButton *restartBtn;

	DECLARE_EVENT_TABLE()
public:
	void pauseGame();
	void resumeGame();
	GameWindow(Frame *parent);
	~GameWindow();
	void onTimer(wxTimerEvent &event);
	void onPaint(wxPaintEvent &event);
	void onKeyDown(wxKeyEvent &event);
	void onChar(wxKeyEvent &event);
	void onUpChar(wxKeyEvent & event);
	void onKeyUp(wxKeyEvent &event);
	void gameIsOver();
	void gameIsNotOver();
	void resetBallBoard();
	void generateLV(Level *lv);


	void goResumeGame(wxCommandEvent &event);
	void goMainMenu(wxCommandEvent &event);
	void goRestart(wxCommandEvent &event);
};

