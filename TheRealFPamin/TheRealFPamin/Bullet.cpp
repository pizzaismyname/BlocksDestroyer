#include "Bullet.h"
#include "Board.h"
#include "Object.h"
#include "Block.h"



void Bullet::loadBitmap()
{	
	wxLogNull nolog;
	wxImage image(wxT("assets\\61-Breakout-Tiles.png"), wxBITMAP_TYPE_PNG);
	image.Rescale(5, 10, wxIMAGE_QUALITY_NORMAL);
	bullet = new wxBitmap(image);
}

Bullet::Bullet(int x, int y, int w, int h, vector<Object*> *allObj)
	:Object(x, y, w, h, allObj)
{
	this->type = 4;
	vX = 0;
	vY = 1;
	dirX = 0;
	dirY = -1;
	l = 5;
	t = 10;

	loadBitmap();

	timer = new wxTimer(this, 1004);
	timer->Start(1);
}


Bullet::~Bullet()
{
	delete timer;
}

void Bullet::move()
{
	this->y += (this->vY * this->dirY);
	if (this->y + (this->vY * this->dirY) <= 0) {
		alive = false;
	}
}

bool Bullet::isAlive()
{
	return alive;
}

wxBitmap Bullet::getBitmap()
{
	return *bullet;
}


void Bullet::draw(wxBufferedPaintDC &pdc)
{
	pdc.DrawBitmap(getBitmap(), wxPoint(x - l / 2, y - t / 2), true);
}



int Bullet::checkCollision(Object * other)
{
	if (other->getType() == 1){

		Block* that = (Block*)other;

		int kananBalok = that->getX() + that->getL() / 2;
		int kiriBalok = that->getX() - that->getL() / 2;
		int atasBalok = that->getY() - that->getT() / 2;
		int bawahBalok = that->getY() + that->getT() / 2;

		int atasPeluru = y - t / 2;

		if (atasPeluru<= bawahBalok && y >= bawahBalok && x >= kiriBalok && x <= kananBalok) {
			that->beingHit(this);
			alive = false;
			return 0;
		}
	}
	return 0;
}
