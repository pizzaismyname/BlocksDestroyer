#include "Bullet.h"
#include "Board.h"
#include "Object.h"

BEGIN_EVENT_TABLE(Bullet, Object)
	EVT_TIMER(1004, Bullet::onTimer)
END_EVENT_TABLE()


void Bullet::loadBitmap()
{
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
	this->l = l;
	this->t = t;
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
	if (this->y + r >= maxY) {
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

void Bullet::onTimer(wxTimerEvent & event)
{
	move();
}


