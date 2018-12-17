#include "GameWindow.h"
#include "wx\dcbuffer.h"
#include "Block.h"
#include "Ball.h"
#include "Board.h"
#include "Level.h"

BEGIN_EVENT_TABLE(GameWindow, wxWindow)
	EVT_TIMER(1000, GameWindow::onTimer)
	EVT_PAINT(GameWindow::onPaint)
	EVT_KEY_DOWN(GameWindow::onKeyDown)
	EVT_KEY_UP(GameWindow::onKeyUp)
END_EVENT_TABLE()

GameWindow::GameWindow(wxFrame *parent)
	: wxWindow(parent, -1)
{
	parent->GetSize(&w, &h);
	this->SetSize(wxSize(w, h));

	timer = new wxTimer(this, 1000);
	timer->Start(1);

	board = new Board(700, 700, w, h, &score ,&allObj, &allBullets);
	ball = new Ball(700, 680, w, h, &score, &allObj);
	Level *lv = new Level(w, h);
	
	generateLV(lv);
	SetFocus();
}


GameWindow::~GameWindow()
{
	delete timer;
	for (auto it : allBlocks) {
		delete it;
	}

	for (auto it : allBullets) {
		delete it;
	}

	for (auto it : allPowerUps) {
		delete it;
	}

	delete ball;
	delete board;
}

void GameWindow::onTimer(wxTimerEvent & event)
{

	if (ball->isLaunched()) {
		ball->move(this);
		ball->checkCollision(board);

		for (auto it : allBullets) {
			for (auto it2 : allBlocks) {
				it->checkCollision(it2);
			}
		}


		for (auto it = allBlocks.begin(); it != allBlocks.end(); it++) {
			ball->checkCollision(*it);
			if (!(*it)->isAlive()) {
				delete *it;
				it = allBlocks.erase(it);
				break;
			}
		}

		for (auto it = allBullets.begin(); it != allBullets.end(); it++) {
			if ((*it)->isAlive() == false) {
				delete *it;
				it = allBullets.erase(it);
				break;
			}
		}

		if (allBlocks.empty()) {
			timer->Stop();
		}
	}
	else {
		ball->follow(board);
	}
	board->move();
	
	for (auto it = allPowerUps.begin(); it != allPowerUps.end(); it++) {
		(*it)->checkCollision(board);
		if ((*it)->isAlive() == false) {
			delete *it;
			it = allPowerUps.erase(it);
			break;
		}
	}

	if (!allBullets.empty()) {
		for (auto it : allBullets) {
			it->move();
		}
	}

	if (!allPowerUps.empty()) {
		for (auto it : allPowerUps) {
			it->move();
		}
	}

	Refresh(0);
}

void GameWindow::onPaint(wxPaintEvent & event)
{
	wxBufferedPaintDC pdc(this);
	pdc.SetBackground(wxBrush(wxColour(0, 0, 0)));
	pdc.DrawRectangle(wxPoint(0, 0), wxSize(w, h));
	
	for (auto it : allBlocks) {
		it->draw(pdc);
	}

	if (!allBullets.empty()) {
		for (auto it : allBullets) {
			it->draw(pdc);
		}
	}

	if (!allPowerUps.empty()) {
		for (auto it : allPowerUps) {
			if(it->isLaunched())
			it->draw(pdc);
		}
	}

	ball->draw(pdc);
	board->draw(pdc);

	wxFont font(18, wxFONTFAMILY_TELETYPE, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD); //default-bold
	pdc.SetFont(font);
	pdc.SetTextForeground(*wxBLUE);
	pdc.DrawText(wxString::Format("S C O R E  :  %d ", score), wxPoint(10, 10));
	pdc.DrawText(wxString::Format("H P :  %d ", board->getHealth()), wxPoint(500, 10));
	pdc.SetTextForeground(*wxGREEN);
	pdc.DrawText(wxString::Format("PRESS ESC TO EXIT ", board->getHealth()), wxPoint(500, 700));
}

void GameWindow::onKeyDown(wxKeyEvent & event)
{
	int key = event.GetKeyCode();
	switch (key)
	{
	case 'A':
		board->moveLeft();
		break;
	case 'D':
		board->moveRight();
		break;
	case ' ':
		if (!ball->isLaunched()) {
			ball->launch();
		}
		else {
			board->activateGun();
		}
		break;
	}
}

void GameWindow::onKeyUp(wxKeyEvent & event)
{
	int key = event.GetKeyCode();
	switch (key)
	{
	case 'A':
		board->stopMove();
		break;
	case 'D':
		board->stopMove();
		break;
	case ' ':
		board->deactivateGun();
		break;
	}
}


void GameWindow::gameIsOver() {
	if (board->isAlive()) {
		board->setHealth(board->getHealth() - 1);
		resetBallBoard();
		return;
	}
	
	gameOver = true;
	timer->Stop();
}
void GameWindow::gameIsNotOver() {
	gameOver = false;
}

void GameWindow::resetBallBoard()
{
	ball->unLaunch();
	ball->setX(700);
	ball->setY(600);
	board->setX(700);
	board->setY(700);
}

void GameWindow::generateLV(Level *lv)
{	
	for (auto it : lv->blocks) {
		allBlocks.push_back(new Block(it.x, it.y, it.l, it.t, it.w, it.h, it.lv, &score ,&allPowerUps, &allObj));
	}
}

