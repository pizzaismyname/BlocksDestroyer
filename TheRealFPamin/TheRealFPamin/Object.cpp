#include "Object.h"



void Object::draw(int x, int y, int w, int h, vector<Object*>* allObj)
{
}

Object::Object(int x, int y, int w, int h, vector<Object*> *allObj)
	: x(x), y(y), maxX(w), maxY(h), allObj(allObj)
{
	r = 50;
	g = 50;
	b = 50;
	vX = 1;
	vY = 1;
	dirX = 1;
	dirY = 1;
}


Object::~Object()
{
}

void Object::move() {

}

void Object::setVx(int x) {
	vX = x;
}

void Object::setVy(int y) {
	vY = y;
}

int Object::getType() {
	return type;
}

int Object::getX()
{
	return x;
}

int Object::getY()
{
	return y;
}

int Object::getDirY()
{
	return dirY;
}

int Object::getDirX()
{
	return dirX;
}

void Object::changeDirX()
{
	dirX *= -1;
}

void Object::changeDirY()
{
	dirY *= -1;
}



int Object::checkCollision(Object * other)
{
	return 0;
}

bool Object::isInside(int x, int y)
{
	return false;
}

bool Object::isNear(int x, int y)
{
	return false;
}

void Object::check()
{
}