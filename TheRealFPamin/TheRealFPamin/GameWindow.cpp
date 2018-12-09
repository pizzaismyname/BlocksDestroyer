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

	board = new Board(700, 700, w, h, &allObj);
	ball = new Ball(700, 680, w, h, &allObj);
	bullet = new Bullet(450, 450, w, h, &allObj);
	//block = new Block(700, 360, w, h, &allObj);
	Level *lv = new Level(w, h);
	
	generateLV(lv);

	//allBlocks.push_back(new Block(lv->satu.x, lv->satu.y, lv->satu.l, lv->satu.t, lv->satu.w, lv->satu.h, lv->satu.lv, &allObj));
	/*allBlocks.push_back(new Block(700, 200, 500, 200, w, h, 3, &allObj));*/
	//allBlocks.push_back(new Block(300, 100, 300, 200, w, h, 1, &allObj));

}


GameWindow::~GameWindow()
{
	delete timer;
	//delete block;
	for (auto it : allBlocks) {
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

		for (auto it = allBlocks.begin(); it != allBlocks.end(); it++) {
			ball->checkCollision(*it);
			if (!(*it)->isAlive()) {
				delete *it;
				it = allBlocks.erase(it);
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
	bullet->draw(pdc);
	ball->draw(pdc);
	board->draw(pdc);
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
			board->shoot();
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
	ball->setY(700);
	board->setX(700);
	board->setY(680);
}

void GameWindow::generateLV(Level *lv)
{	
	for (auto it : lv->blocks) {
		allBlocks.push_back(new Block(it.x, it.y, it.l, it.t, it.w, it.h, it.lv, &allObj));
	}
}

