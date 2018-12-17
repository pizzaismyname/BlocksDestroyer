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
	EVT_KEY_DOWN(GameWindow::onChar)
	EVT_KEY_UP(GameWindow::onKeyUp)
	EVT_KEY_UP(GameWindow::onUpChar)
	EVT_BUTTON(3001, GameWindow::goResumeGame)
	EVT_BUTTON(3002, GameWindow::goMainMenu)
	EVT_BUTTON(3003, GameWindow::goRestart)
	EVT_BUTTON(3004, GameWindow::goWin)
END_EVENT_TABLE()

GameWindow::GameWindow(Frame *parent)
	: wxWindow(parent, -1)
{
	this->parent = parent;
	parent->GetSize(&w, &h);
	this->SetSize(wxSize(w, h));

	timer = new wxTimer(this, 1000);
	timer->Start(1);

	board = new Board(700, 700, w, h, &score ,&allObj, &allBullets);
	ball = new Ball(700, 680, w, h, &score, &allObj);
	Level *lv = new Level(w, h);
	
	loadBitmap();

	resumeBtn = new wxBitmapButton(this, 3001, *resumeImg, wxPoint(800, 300), wxDefaultSize, wxBORDER_NONE);
	mainMenuBtn = new wxBitmapButton(this, 3002, *mainMenuImg, wxPoint(100, 300), wxDefaultSize, wxBORDER_NONE);
	restartBtn = new wxBitmapButton(this, 3003, *restartImg, wxPoint(500, 300), wxDefaultSize, wxBORDER_NONE);

	resumeBtn->SetBitmapCurrent(*resumeHoverImg);
	mainMenuBtn->SetBitmapCurrent(*mainMenuHoverImg);
	restartBtn->SetBitmapCurrent(*restartHoverImg);
	

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
	static bool btnShow = false;
	if (!paused) {
		
		
			resumeBtn->Show(false);
			mainMenuBtn->Show(false);
			restartBtn->Show(false);
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

			
			/*if (allBlocks.empty()) {
				winGame();
				
			}*/
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
	}
	else {
		if (!btnShow) {
			resumeBtn->Show(true);
			mainMenuBtn->Show(true);
			restartBtn->Show(true);
		}
	}
	Refresh(0);
}

void GameWindow::onPaint(wxPaintEvent & event)
{	
	

	if (!paused) {
		if (gameOver) {
			wxBufferedPaintDC pdc(this);
			pdc.DrawBitmap(*gameOverScreen, wxPoint(0, 0), true);
			pdc.DrawText(wxString::Format("S C O R E  :  %d ", score), wxPoint(10, 10));
			restartBtn->Show(true);
			mainMenuBtn->Show(true);
		}
		else if (gameWin) {
			wxBufferedPaintDC pdc(this);
			pdc.DrawBitmap(*winScreen, wxPoint(0, 0), true);
			pdc.DrawText(wxString::Format("S C O R E  :  %d ", score), wxPoint(10, 10));
			mainMenuBtn->Show(true);
		}
		else {
			if (allBlocks.empty()) {
				winGame();
			}
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
					if (it->isLaunched())
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
	}
	else {
		wxBufferedPaintDC pdc(this);
		//wxPaintDC pdc(this);
		pdc.DrawBitmap(*pauseScreen, wxPoint(0, 0), true);

		/*resumeBtn->Show = true ;
		mainMenuBtn->Show=true;*/
	}
}

void GameWindow::onKeyDown(wxKeyEvent & event)
{
	if (!paused) {
		int key = event.GetKeyCode();
		if (key == 27) event.Skip();
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
}

void GameWindow::onKeyUp(wxKeyEvent & event)
{	
	if (!paused) {
		int key = event.GetKeyCode();
		if (key == 27) event.Skip();
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
}

void GameWindow::onChar(wxKeyEvent & event)
{
	if (!paused) {
		int key = event.GetKeyCode();
		if (key == 27) {
			pauseGame();
		}
	}
}

void GameWindow::onUpChar(wxKeyEvent & event)
{
	
}

void GameWindow::gameIsOver() {
	if (board->isAlive()) {
		board->setHealth(board->getHealth() - 1);
		resetBallBoard();
		return;
	}
	else {
		gameOver = true;
		timer->Stop();
		timer->StartOnce();
		timer->StartOnce();
	}
	
	
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

void GameWindow::pauseGame() {
	timer->Stop();
	paused = true;
	timer->StartOnce();
	timer->StartOnce();
	/*wxBufferedPaintDC pdc(this);
	wxPaintDC pdc(this);
	pdc.DrawBitmap(*pauseScreen, wxPoint(0, 0), true);*/
}


void GameWindow::resumeGame() {
	paused = false;
	timer->Start();
	
}	


void GameWindow::winGame()
{	
	timer->Stop();
	gameWin = true;
	timer->StartOnce();
	timer->StartOnce();

}

void GameWindow::loadBitmap()
{
	wxLogNull nolog;
	wxImage image(wxT("background\\6.png"), wxBITMAP_TYPE_PNG);
	pauseScreen = new wxBitmap(image.Scale(w,h));

	wxImage image2(wxT("assets-menu/button_resume.png"), wxBITMAP_TYPE_PNG);
	resumeImg = new wxBitmap(image2);

	wxImage image3(wxT("assets-menu/button_resume_clicked.png"), wxBITMAP_TYPE_PNG);
	resumeHoverImg = new wxBitmap(image3);

	wxImage image4(wxT("assets-menu/button_back-to-menu.png"), wxBITMAP_TYPE_PNG);
	mainMenuImg = new wxBitmap(image4);

	wxImage image5(wxT("assets-menu/button_back-to-menu_clicked.png"), wxBITMAP_TYPE_PNG);
	mainMenuHoverImg= new wxBitmap(image5);

	wxImage image6(wxT("assets-menu/button_retry.png"), wxBITMAP_TYPE_PNG);
	restartImg = new wxBitmap(image6);

	wxImage image7(wxT("assets-menu/button_retry_clicked.png"), wxBITMAP_TYPE_PNG);
	restartHoverImg = new wxBitmap(image7);

	wxImage image8(wxT("background/5.png"), wxBITMAP_TYPE_PNG);
	gameOverScreen = new wxBitmap(image8.Scale(w,h));
	
	wxImage image9(wxT("background/4.png"), wxBITMAP_TYPE_PNG);
	winScreen = new wxBitmap(image9.Scale(w, h));
}



void GameWindow::goResumeGame(wxCommandEvent &event) {
	resumeGame();
}
void GameWindow::goMainMenu(wxCommandEvent &event) {
	parent->ShowMenuWindow();
}

void GameWindow::goRestart(wxCommandEvent &event) {
	parent->ShowGameWindow();
}

void GameWindow::goWin(wxCommandEvent & event)
{
}
