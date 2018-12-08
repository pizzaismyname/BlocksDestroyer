#include "Board.h"


Board::Board(int x, int y, int w, int h, vector<Object*> *allObj)
	: Object(x, y, w, h, allObj)
{
	type = 3;
	l = 100;
	t = 20;
	vX = 0;
	dirX = 0;
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




Board::~Board()
{
}

void Board::draw(wxBufferedPaintDC & pdc)
{
	pdc.SetBrush(wxBrush(wxColour(r, g, b)));
	pdc.SetPen(wxPen(wxColour(r, g, b)));
	pdc.DrawRectangle(this->x - l / 2, this->y - t / 2, l, t);
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
