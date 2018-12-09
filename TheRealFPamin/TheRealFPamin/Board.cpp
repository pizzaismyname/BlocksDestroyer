#include "Board.h"
#include "wx\stdpaths.h"
#include "wx\filename.h"

BEGIN_EVENT_TABLE(Board, Object)
	EVT_TIMER(1501, Board::onTimer)
END_EVENT_TABLE()


void Board::loadBitmap()
{
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

Board::Board(int x, int y, int w, int h, vector<Object*> *allObj)
	: Object(x, y, w, h, allObj)
{
	type = 3;
	l = 100;
	t = 20;
	vX = 0;
	dirX = 0;



	loadBitmap();
	timer = new wxTimer(this, 1501);
	timer->Start(100);
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
	/*pdc.SetBrush(wxBrush(wxColour(r, g, b)));
	pdc.SetPen(wxPen(wxColour(r, g, b)));
	pdc.DrawRectangle(this->x - l / 2, this->y - t / 2, l, t);*/

	pdc.DrawBitmap(getBitmap(), wxPoint(x - l / 2, y - t / 2), true);
}

void Board::move()
{
	if (vX != 0) {

		if (this->x - l / 2 - (this->vX) <= 8) {
			this->x += 1;
		}
		else if (this->x + l / 2 + (this->vX) >= maxX) {
			this->x -= 1;
		}
		else {
			this->x += (this->vX);
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

void Board::beingHit()
{
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

void Board::shoot()
{

}
