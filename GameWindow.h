#pragma once
#include "wx\wx.h"
#include "MyFrame.h"
#include <vector>

using namespace std;
class Bullet;
class BaseBoard;
class ShooterBoard;

class GameWindow :
	public wxWindow
{
private:
	MyFrame *parent;
	DECLARE_EVENT_TABLE()
	BaseBoard *player;
	ShooterBoard *shooterPlayer;
	wxTimer *timer;
	Bullet* bnew;

	vector<Bullet*> blt;
public:
	void generateBullet();
	GameWindow(MyFrame *parent);
	~GameWindow();

	void moveChar(wxKeyEvent &evt);

	void onPaint(wxPaintEvent &evt);
	void onTimer(wxTimerEvent &event);
	void onTimer2(wxTimerEvent &event);

	void loadPlayer();
	void loadShooterPlayer();




};

