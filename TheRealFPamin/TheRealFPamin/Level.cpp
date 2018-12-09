#include "Level.h"




Level::Level(int w, int h)
{
	
	satu.x = 700;
	satu.y = 200;
	satu.l = 100;
	satu.t = 50;
	satu.w = w;
	satu.h = h;
	satu.lv = 3;

	blocks.push_back(satu);

	satu.x = 500;
	satu.y = 100;
	satu.l = 100;
	satu.t = 50;
	satu.w = w;
	satu.h = h;
	satu.lv = 2;

	blocks.push_back(satu);
	
	satu.x = 400;
	satu.y = 100;
	satu.l = 100;
	satu.t = 50;
	satu.w = w;
	satu.h = h;
	satu.lv = 1;

	blocks.push_back(satu);

	satu.x = 300;
	satu.y = 100;
	satu.l = 100;
	satu.t = 50;
	satu.w = w;
	satu.h = h;
	satu.lv = 2;

	blocks.push_back(satu);


	satu.x = 200;
	satu.y = 101;
	satu.l = 100;
	satu.t = 50;
	satu.w = w;
	satu.h = h;
	satu.lv = 1;

	blocks.push_back(satu);

	satu.x = 100;
	satu.y = 302;
	satu.l = 100;
	satu.t = 50;
	satu.w = w;
	satu.h = h;
	satu.lv = 1;

	blocks.push_back(satu);

	satu.x = 100;
	satu.y = 303;
	satu.l = 100;
	satu.t = 50;
	satu.w = w;
	satu.h = h;
	satu.lv = 1;

	blocks.push_back(satu);

	satu.x = 100;
	satu.y =404;
	satu.l = 100;
	satu.t = 50;
	satu.w = w;
	satu.h = h;
	satu.lv = 1;

	blocks.push_back(satu);

	satu.x = 100;
	satu.y = 505;
	satu.l = 100;
	satu.t = 50;
	satu.w = w;
	satu.h = h;
	satu.lv = 1;

	blocks.push_back(satu);
}


Level::~Level()
{
}
