#include "Board.h"
#include "wx\stdpaths.h"
#include "wx\filename.h"
#include "Bullet.h"


BEGIN_EVENT_TABLE(Board, Object)
	EVT_TIMER(1501, Board::onTimer)
	EVT_TIMER(1502, Board::onTimer2)
	EVT_TIMER(1503, Board::onRevControlTimer)
	EVT_TIMER(1504, Board::onShootSkillTimer)
END_EVENT_TABLE()


void Board::loadBitmap()
{
	wxLogNull nolog;
	wxImage image(wxT("assets\\50-Breakout-Tiles.png"), wxBITMAP_TYPE_PNG);
	image.Rescale(121, 32, wxIMAGE_QUALITY_NORMAL);
	board1 = new wxBitmap(image);
	board = board1;

	wxImage image2(wxT("assets\\51-Breakout-Tiles.png"), wxBITMAP_TYPE_PNG);
	image2.Rescale(121, 32, wxIMAGE_QUALITY_NORMAL);
	board2 = new wxBitmap(image2);

	wxImage image3(wxT("assets\\52-Breakout-Tiles.png"), wxBITMAP_TYPE_PNG);
	image3.Rescale(121, 32, wxIMAGE_QUALITY_NORMAL);
	board3 = new wxBitmap(image3);
}

Board::Board(int x, int y, int w, int h, int *score, vector<Object*> *allObj, vector<Bullet*> *allBullets)
	: Object(x, y, w, h, allObj), allBullets(allBullets)
{	
	this->score = score;
	type = 3;
	l = 121;
	t = 32;
	vX = 0;
	dirX = 0;



	loadBitmap();
	timer = new wxTimer(this, 1501);
	timer->Start(100);
	timer2 = new wxTimer(this, 1502);

	revControlTimer = new wxTimer(this, 1503);
	shootSkillTimer = new wxTimer(this, 1504);

	
}

int Board::getHealth()
{
	return health;
}

void Board::setHealth(int health)
{
	this->health = health;
}

bool Board::isAlive()
{	
	if (health <= 0) {
		return false;
	}
	return true;
}




wxBitmap Board::getBitmap()
{
	return *board;
}

Board::~Board()
{
	delete timer;
}

void Board::draw(wxBufferedPaintDC & pdc)
{
	pdc.DrawBitmap(getBitmap(), wxPoint(x - l / 2, y - t / 2), true);
}

void Board::move()
{
	if (vX != 0) {

		if (this->x - l / 2 - (this->vX) * reverse <= 8) {
			this->x += 1;
		}
		else if (this->x + l / 2 + (this->vX) * reverse >= maxX) {
			this->x -= 1;
		}
		else {
			this->x += (this->vX) * reverse;
		}
	}
}

void Board::moveLeft()
{
	vX = -5;
}

void Board::moveRight()
{
	vX = 5;
}

void Board::stopMove()
{
	vX = 0;
}

void Board::beingHit(Object * other)
{		
	return;
}

void Board::poweredUp(int x)
{	
	switch (x) {
	case 1 :
		reverse = -1;
		revControlTimer->StartOnce(5000);
		break;
	case 2:
		skillActive = true;
		shootSkillTimer->StartOnce(2000);
		break;
	case 3:
		break;
	}
	
}


void Board::onTimer(wxTimerEvent & event)
{
	static int counter = 1;
	if (counter == 1) {
		board = board1;
		counter = 2;
	}
	else if (counter == 2){
		board = board2;
		counter = 3;
	}
	else {
		board = board3;
		counter = 1;
	}
}

void Board::onTimer2(wxTimerEvent & event)
{
	shoot();
}

void Board::onRevControlTimer(wxTimerEvent & event)
{
	reverse = 1;

}

void Board::onShootSkillTimer(wxTimerEvent & event)
{
	skillActive = false;
	
	deactivateGun();
}

int Board::getL()
{
	return l;
}

int Board::getT()
{
	return t;
}



bool Board::isSkillActive()
{
	return skillActive;
}

void Board::shoot()
{	
	static int counter = 1;
	if (counter == 1) {
		bullet = new Bullet(x - l / 2, y, maxX, maxY, score, allObj);
		counter = 2;
	}
	else {
		bullet = new Bullet(x + l / 2, y, maxX, maxY, score, allObj);
		counter = 1;
	}

	allBullets->push_back(bullet);
}

void Board::activateGun() {
	if(skillActive)
	if (!gunActive) {
		timer2->Start(350);
		gunActive = true;
	}
}

void Board::deactivateGun() {
	if (gunActive) {
		timer2->Stop();
		gunActive = false;
	}
	
}