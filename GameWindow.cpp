#include "GameWindow.h"
#include "BaseBoard.h"
#include "ShooterBoard.h"
#include "wx\dcbuffer.h"
#include "wx\stdpaths.h"
#include "wx\filename.h"
#include "Bullet.h"

#define TIMER_ID 2000

BEGIN_EVENT_TABLE(GameWindow, wxWindow)
	EVT_KEY_DOWN(GameWindow::moveChar)
	EVT_PAINT(GameWindow::onPaint)
	EVT_TIMER(TIMER_ID, GameWindow::onTimer)
END_EVENT_TABLE()



GameWindow::GameWindow(MyFrame *parent)
	: wxWindow(parent, wxID_ANY)
{
	this->SetBackgroundColour(wxColour(*wxBLACK));
	this->parent = parent;

	timer = new wxTimer(this, TIMER_ID);
	timer->Start(50);
	loadPlayer();
	//loadShooterPlayer();
}


GameWindow::~GameWindow()
{
	delete player;
}

void GameWindow::moveChar(wxKeyEvent & evt)
{
	int keycode = evt.GetKeyCode();
	switch (keycode)
	{
	case 'A':
		//wxMessageBox(wxT('Keyboard A'));
		player->move('A');
		//shooterPlayer->move('A');
		break;
	case 'D':
		//wxMessageBox(wxT('Keyboard D'));
		player->move('D');
		//shooterPlayer->move('D');
		break;
	case ' ':
		generateBullet();
		//wxMessageBox(wxT('Keyboard spasi'));
	}
}



void GameWindow::onPaint(wxPaintEvent & evt)
{
	wxBufferedPaintDC pdc(this);
	pdc.SetBrush(wxColour(*wxWHITE));
	pdc.DrawRectangle(wxPoint(0, 0), wxSize(1000, 700));
	pdc.DrawBitmap(player->getBitmap(), wxPoint(player->getX(), player->getY()), true);
	//pdc.DrawBitmap(shooterPlayer->getBitmap(), wxPoint(shooterPlayer->getX(), shooterPlayer->getY()), true);
	for (size_t i = 0; i < blt.size(); i++)
	{
		pdc.DrawBitmap(blt[i]->getBitmap(), wxPoint(blt[i]->getX(), blt[i]->getY()), true);
	}
}

void GameWindow::onTimer(wxTimerEvent & event)
{	
	
	int jumtembak = blt.size();
	for (int i = 0; i < jumtembak; i++)
	{
		blt[i]->move();
	}
	for (int i = jumtembak - 1; i >= 0; i--)
	{	
		Bullet * blt2;
		if (blt[i]->getDiHapus()) {
			blt2 = blt[i];
			blt.erase(blt.begin() + i);
			delete blt2;
		}
	}


	Refresh();
}



void GameWindow::loadPlayer()
{
	player = new BaseBoard();
}

void GameWindow::loadShooterPlayer()
{
	shooterPlayer = new ShooterBoard();
}

void GameWindow::generateBullet()
{
	bnew = new Bullet(player->getX() + 50, player->getY());
	blt.push_back(bnew);
}