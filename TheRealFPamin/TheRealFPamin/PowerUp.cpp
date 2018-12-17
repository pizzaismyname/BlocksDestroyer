#include "PowerUp.h"
#include "Board.h"
#include "Object.h"
#include "Block.h"

BEGIN_EVENT_TABLE(PowerUp, Object)
EVT_TIMER(1004, PowerUp::onTimer)
END_EVENT_TABLE()


void PowerUp::loadBitmap()
{
	wxLogNull nolog;
	wxImage image(wxT("assets\\61-Breakout-Tiles.png"), wxBITMAP_TYPE_PNG);
	image.Rescale(5, 10, wxIMAGE_QUALITY_NORMAL);
	bullet = new wxBitmap(image);

}

PowerUp::PowerUp(int x, int y, int w, int h, Block *block, vector<Object*> *allObj)
	:Object(x, y, w, h, allObj)
{	
	this->block = block;
	this->type = 4;
	vX = 0;
	vY = 1;
	dirX = 0;
	dirY = -1;
	this->l = l;
	this->t = t;
	l = 5;
	t = 10;
	launched = false;
	loadBitmap();
	this->block = block;
	timer = new wxTimer(this, 1004);
	timer->Start(1);
}


PowerUp::~PowerUp()
{
	delete timer;
}

void PowerUp::move()
{
	if (launched) {
		this->y -= (this->vY * this->dirY);
		if (this->y - (this->vY * this->dirY) >= maxY) {
			alive = false;
		}
	}
}

bool PowerUp::isAlive()
{
	return alive;
}

wxBitmap PowerUp::getBitmap()
{
	return *bullet;
}


void PowerUp::draw(wxBufferedPaintDC &pdc)
{
	pdc.DrawBitmap(getBitmap(), wxPoint(x - l / 2, y - t / 2), true);
}

int PowerUp::getRandNum(int x)
{
	srand((unsigned)time(0));
	int i;
	i = (rand() % x) + 1;
	return i;
}

void PowerUp::onTimer(wxTimerEvent & event)
{
}

int PowerUp::checkCollision(Object * other)
{
	if (other->getType() == 3) {

		Board* that = (Board*)other;

		int kananBalok = that->getX() + that->getL() / 2;
		int kiriBalok = that->getX() - that->getL() / 2;
		int atasBalok = that->getY() - that->getT() / 2;
		int bawahBalok = that->getY() + that->getT() / 2;

		int atasPeluru = y - t / 2;
		int bawahPeluru = y + t / 2;
		if (alreadyHit == false) {
			if (atasPeluru <= bawahBalok && y >= bawahBalok && x >= kiriBalok && x <= kananBalok) {
				alreadyHit = true;
				alive = false;
				that->poweredUp(getRandNum(2));
				return 0;
			}
			if (bawahPeluru >= atasBalok && y <= atasBalok && x >= kiriBalok && x <= kananBalok) {
				alreadyHit = true;
				alive = false;
				that->poweredUp(getRandNum(2));
				return 0;
			}
		}
	}
	return 0;
}

void PowerUp::follow()
{
	x = block->getX();
	y = block->getY();
}

bool PowerUp::isLaunched()
{
	return launched;
}

void PowerUp::launch()
{
	launched = true;
}

void PowerUp::shout()
{
	wxMessageBox(wxT("hehehe"));
}