#include "Ball.h"
#include "Board.h"
#include "Block.h"
#include "GameWindow.h"


Ball::Ball(int x, int y, int w, int h, int *score, vector<Object*> *allObj)
	: Object(x, y, w, h, allObj)
{
	this->r = 10;
	this->type = 2;
	vX = 3;
	vY = 3;
	dirX = 1;
	dirY = -1;
	this->score = score;
}



Ball::~Ball()
{
}

void Ball::draw(wxBufferedPaintDC & pdc)
{
	pdc.SetBrush(wxBrush(wxColour(r, g, b)));
	pdc.SetPen(wxPen(wxColour(r, g, b)));
	pdc.DrawCircle(this->x, this->y, r);
}

bool Ball::isLaunched()
{
	return launched;
}

void Ball::launch()
{
	launched = true;
}

void Ball::unLaunch()
{
	launched = false;
}

void Ball::move(GameWindow *window)
{
	this->x += (this->vX * dirX);
	if (this->x - r <= 0 || this->x + r >= maxX) {
		dirX *= -1;
	}
	this->y += (this->vY * this->dirY);
	if (this->y - r <= 0) {
		dirY *= -1;
	}
	if (this->y + r >= maxY) {
		dirY *= -1;
		window->gameIsOver();
	}
}

void Ball::follow(Board * board)
{
	x = board->getX();
	y = board->getY() - 32;
}


double Ball::distance(int x, int y)
{
	double dist;
	dist = sqrt(pow(this->x - x, 2) + pow(this->y - y, 2));
	return dist;
}

void Ball::check()
{

}

int Ball::checkCollision(Object * other)
{	


	if (other->getType() == 1) {
		
		Block* that = (Block*)other;

		int kananBola = this->getX() + r;
		int kiriBola = this->getX() - r;
		int bawahBola = this->getY() + r;
		int atasBola = this->getY() - r;

		int kananBalok = that->getX() + that->getL() / 2;
		int kiriBalok = that->getX() - that->getL() / 2;
		int atasBalok = that->getY() - that->getT() / 2;
		int bawahBalok = that->getY() + that->getT() / 2;



		if (kananBola >= kiriBalok && this->getX() <= kiriBalok && this->getY() >= atasBalok && this->getY() <= bawahBalok) {
			changeDirX();
			that->beingHit(this);
			*score += 100;
			return 0;
		}
		else if (kiriBola <= kananBalok && this->getX() >= kananBalok && this->getY() >= atasBalok && this->getY() <= bawahBalok) {
			changeDirX();
			that->beingHit(this);
			*score += 100;
			return 0;
		}
		else if (atasBola <= bawahBalok && this->getY() >= bawahBalok && this->getX() >= kiriBalok && this->getX() <= kananBalok) {
			changeDirY();
			that->beingHit(this);
			*score += 100;
			return 0;
		}
		else if (bawahBola >= atasBalok && this->getY() <= atasBalok && this->getX() >= kiriBalok && this->getX() <= kananBalok) {
			changeDirY();
			that->beingHit(this);
			*score += 100;
			return 0;
		}
		else {
			double kiat = this->distance(kiriBalok, atasBalok);
			double kaat = this->distance(kananBalok, atasBalok);
			double kiba = this->distance(kiriBalok, bawahBalok);
			double kaba = this->distance(kananBalok, bawahBalok);

			if (kiat <= (double)this->r) {
				this->x -= 5;
				this->y -= 5;
				changeDirY();
				changeDirX();
				that->beingHit(this);

				return 0;
			}
			else if (kaat <= (double)this->r) {
				this->x += 5;
				this->y -= 5;
				changeDirY();
				changeDirX();
				that->beingHit(this);

				return 0;
			}
			else if (kiba <= (double)this->r) {
				this->x -= 5;
				this->y += 5;
				changeDirY();
				changeDirX();
				that->beingHit(this);

				return 0;
			}
			else if (kaba <= (double)this->r) {
				this->x += 5;
				this->y += 5;
				changeDirY();
				changeDirX();
				that->beingHit(this);
				return 0;
			}
		}

	}
	if (other->getType() == 3) {
		Board* that = (Board*)other;

		int kananBola = this->getX() + r;
		int kiriBola = this->getX() - r;
		int bawahBola = this->getY() + r;
		int atasBola = this->getY() - r;

		int kananBalok = that->getX() + that->getL() / 2;
		int kiriBalok = that->getX() - that->getL() / 2;
		int atasBalok = that->getY() - that->getT() / 2;
		int bawahBalok = that->getY() + that->getT() / 2;



		if (kananBola >= kiriBalok && this->getX() <= kiriBalok && this->getY() >= atasBalok && this->getY() <= bawahBalok) {
			changeDirX();
			that->beingHit(this);
			return 0;
		}
		else if (kiriBola <= kananBalok && this->getX() >= kananBalok && this->getY() >= atasBalok && this->getY() <= bawahBalok) {
			changeDirX();
			that->beingHit(this);
			return 0;
		}
		else if (atasBola <= bawahBalok && this->getY() >= bawahBalok && this->getX() >= kiriBalok && this->getX() <= kananBalok) {
			changeDirY();
			that->beingHit(this);
			return 0;
		}
		else if (bawahBola >= atasBalok && this->getY() <= atasBalok && this->getX() >= kiriBalok && this->getX() <= kananBalok) {
			changeDirY();
			that->beingHit(this);
			return 0;
		}
		else {
			double kiat = this->distance(kiriBalok, atasBalok);
			double kaat = this->distance(kananBalok, atasBalok);
			double kiba = this->distance(kiriBalok, bawahBalok);
			double kaba = this->distance(kananBalok, bawahBalok);

			if (kiat <= (double)this->r) {
				this->x -= 5;
				this->y -= 5;
				changeDirY();
				changeDirX();
				that->beingHit(this);

				return 0;
			}
			else if (kaat <= (double)this->r) {
				this->x += 5;
				this->y -= 5;
				changeDirY();
				changeDirX();
				that->beingHit(this);

				return 0;
			}
			else if (kiba <= (double)this->r) {
				this->x -= 5;
				this->y += 5;
				changeDirY();
				changeDirX();
				that->beingHit(this);

				return 0;
			}
			else if (kaba <= (double)this->r) {
				this->x += 5;
				this->y += 5;
				changeDirY();
				changeDirX();
				that->beingHit(this);
				return 0;
			}
		}

	}
	return 0;
}

int Ball::getR()
{
	return r;
}

void Ball::setDirX(int dirX)
{
	this->dirX = dirX;
}

void Ball::setDirY(int dirY)
{
	this->dirY = dirY;
}

void Ball::setVx(int x)
{
	this->vX = x;
}

void Ball::setVy(int y)
{
	this->vY = y;
}

double Ball::gradien(int x, int y, int x1, int y1)
{
	double atas = y1 - y;
	double bawah = x1 - x;
	return (double)atas / bawah;
}

int Ball::getDamage()
{
	return damage;
}