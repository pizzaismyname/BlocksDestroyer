#include "Block.h"
#include "Ball.h"
#include "wx\stdpaths.h"
#include "wx\filename.h"

void Block::loadBitmap()
{
	if (blockLv == 1) {
		
		wxImage image(wxT("assets\\01-Breakout-Tiles.png"), wxBITMAP_TYPE_PNG);
		image.Rescale(87, 32, wxIMAGE_QUALITY_NORMAL);
		block = new wxBitmap(image);
		
		wxImage image2(wxT("assets\\02-Breakout-Tiles.png"), wxBITMAP_TYPE_PNG);
		
		image2.Rescale(87, 32, wxIMAGE_QUALITY_NORMAL);
		weekBlock = new wxBitmap(image2);
	}
	else if (blockLv == 2) {
			wxImage image(wxT("assets\\03-Breakout-Tiles.png"), wxBITMAP_TYPE_PNG);
			image.Rescale(87, 32, wxIMAGE_QUALITY_NORMAL);
			block = new wxBitmap(image);

			wxImage image2(wxT("assets\\04-Breakout-Tiles.png"), wxBITMAP_TYPE_PNG);
			image2.Rescale(87, 32, wxIMAGE_QUALITY_NORMAL);
			weekBlock = new wxBitmap(image2);
		}
	
	else if (blockLv == 3) {
		
			wxImage image(wxT("assets\\05-Breakout-Tiles.png"), wxBITMAP_TYPE_PNG);
			image.Rescale(87, 32, wxIMAGE_QUALITY_NORMAL);
			block = new wxBitmap(image);

			wxImage image2(wxT("assets\\06-Breakout-Tiles.png"), wxBITMAP_TYPE_PNG);
			image2.Rescale(87, 32, wxIMAGE_QUALITY_NORMAL);
			weekBlock = new wxBitmap(image2);
		
	}
}

Block::Block(int x, int y, int l, int t, int w, int h, int lv, int *score, vector <PowerUp*> *allPowerUps, vector<Object*> *allObj)
 : Object(x, y, w, h, allObj)
{	
	this->score = score;
	//this->powerUp = powerUp;
	powerUp = new PowerUp(x, y, maxX, maxY, score, this, allObj);
	allPowerUps->push_back(powerUp);
	srand(time(0));
	this->type = 1;
	this->blockLv = lv;
	vX = 0;
	vY = 0;
	dirX = 0;
	dirY = 0;
	this->l = l;
	this->t = t;
	this->health = lv;
	this->loadBitmap();
}

Block::~Block()
{
}

void Block::check()
{
}

int Block::checkCollision(Object * other)
{
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
	static int a = 0;
	Ball* ball = (Ball*)other;
	health -= ball->getDamage();
	if (getRandNum(5) == 1) {
		launchPwrUp();
	}
	return;
}

bool Block::isAlive()
{
	if (health <= 0) { 
		if (powerUp != nullptr && powerUp->launched == false) powerUp->alive=false;
		return false;
	
	}
	return true;
}

void Block::draw(wxBufferedPaintDC &pdc)
{	
	pdc.DrawBitmap(getBitmap(), wxPoint(x - l / 2, y - t / 2), true);
}

void Block::launchPwrUp()
{
	powerUp->launch();
}

wxBitmap Block::getBitmap()
{	
	if (health == 1) {
		return *weekBlock;
	}
	return *block;
}

int Block::getRandNum(int x)
{
	srand((unsigned)time(0));
	int i;
	i = (rand() % x) + 1;
	return i;
}



