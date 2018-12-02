#include "Bullet.h"



Bullet::Bullet()
{
}

Bullet::~Bullet()
{
}

void Bullet::loadBitmap()
{
	wxImageHandler *pngLoader = new wxPNGHandler();
	wxImage::AddHandler(pngLoader);
	wxImage image(wxT("assets\\bullet.png"), wxBITMAP_TYPE_PNG);
	bulletPtr = new wxBitmap(image);
}

wxBitmap Bullet::getBitmap()
{
	return *bulletPtr;
}

Bullet::Bullet(int x, int y)
{
	this->x = x;
	this->y = y;
	hapus = false;
	loadBitmap();
}

int Bullet::getDamage() {
	return damage;
}

int Bullet::getSpeed()
{
	return this->speed;
}

int Bullet::getWidth()
{
	return this->width;
}

int Bullet::getHeight()
{
	return this->height;
}

bool Bullet::getDiHapus()
{
	return hapus;
}

int Bullet::getX()
{
	return this->x;
}

int Bullet::getY()
{
	return this->y;
}

void Bullet::hit()
{

}

void Bullet::move()
{
	if (x - 20 >= 0) {
		y -= 20;
	}
	else {
		hapus = true;
	}
}