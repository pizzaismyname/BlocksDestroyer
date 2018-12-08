#include "Block.h"
#include "Ball.h"

Block::Block(int x, int y, int w, int h, int lv, vector<Object*> *allObj)
 : Object(x, y, w, h, allObj) 
{
	this->type = 1;
	this->blockLv = lv;
	vX = 0;
	vY = 0;
	dirX = 0;
	dirY = 0;
	l = 500;
	t = 20;
	r = 60;
	g = 200;
	b = 20;
	this->health = 1;
}



Block::~Block()
{
}

void Block::check()
{

}

int Block::checkCollision(Object * other)
{

	/*if (other->getType() == 2) {
		Ball* that = (Ball*)other;
		double distance = that->distance(this->getX(), this->getY());
		if (distance <= (double)2 * that->getR()) {
			if (that->getX() < x) {
				wxMessageBox(wxT('Keyboard spasi'));
			}
			else if (that->getX() > x) {
				wxMessageBox(wxT('Keyboard spasi'));
			}
			else {
				wxMessageBox(wxT('Keyboard spasi'));
			}
			if (that->getY() < y) {
				wxMessageBox(wxT('Keyboard spasi'));
			}
			else if (that->getY() > y) {
				wxMessageBox(wxT('Keyboard spasi'));
			}
			else {
				wxMessageBox(wxT('Keyboard spasi'));
			}
		}
	}
	*/
	return 0;
}

int Block::getL()
{
	return l;
}

int Block::getT()
{
	return t;
}

void Block::beingHit(Object * other)
{
	Ball* ball = (Ball*)other;
	this->health -= ball->getDamage();
}

bool Block::isAlive()
{
	if (health <= 0) return false;
	return true;

}

void Block::draw(wxBufferedPaintDC &pdc)
{
	pdc.SetBrush(wxBrush(wxColour(r, g, b)));
	pdc.SetPen(wxPen(wxColour(r, g, b)));
	pdc.DrawRectangle(this->x - l / 2, this->y - t / 2, l, t);
}