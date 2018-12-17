#include "Level.h"




Level::Level(int w, int h)
{
	satu.x = 100;
	satu.y = 100;
	satu.l = 100;
	satu.t = 50;
	satu.w = w;
	satu.h = h;
	satu.lv = 3;

	blocks.push_back(satu);

	satu.x = 300;
	satu.y = 100;
	satu.l = 100;
	satu.t = 50;
	satu.w = w;
	satu.h = h;
	satu.lv = 2;

	blocks.push_back(satu);

	satu.x = 500;
	satu.y = 100;
	satu.l = 100;
	satu.t = 50;
	satu.w = w;
	satu.h = h;
	satu.lv = 3;

	blocks.push_back(satu);
	
	satu.x = 700;
	satu.y = 100;
	satu.l = 100;
	satu.t = 50;
	satu.w = w;
	satu.h = h;
	satu.lv = 2;

	blocks.push_back(satu);
	
	satu.x = 900;
	satu.y = 100;
	satu.l = 100;
	satu.t = 50;
	satu.w = w;
	satu.h = h;
	satu.lv = 3;

	blocks.push_back(satu);

	satu.x = 1100;
	satu.y = 100;
	satu.l = 100;
	satu.t = 50;
	satu.w = w;
	satu.h = h;
	satu.lv = 2;

	blocks.push_back(satu);

	satu.x = 1300;
	satu.y = 100;
	satu.l = 100;
	satu.t = 50;
	satu.w = w;
	satu.h = h;
	satu.lv = 3;

	blocks.push_back(satu);

	/**/

	satu.x = 200;
	satu.y = 200;
	satu.l = 100;
	satu.t = 50;
	satu.w = w;
	satu.h = h;
	satu.lv = 2;

	blocks.push_back(satu);

	satu.x = 400;
	satu.y = 200;
	satu.l = 100;
	satu.t = 50;
	satu.w = w;
	satu.h = h;
	satu.lv = 2;

	blocks.push_back(satu);

	satu.x = 600;
	satu.y = 200;
	satu.l = 100;
	satu.t = 50;
	satu.w = w;
	satu.h = h;
	satu.lv = 3;

	blocks.push_back(satu);

	satu.x = 800;
	satu.y = 200;
	satu.l = 100;
	satu.t = 50;
	satu.w = w;
	satu.h = h;
	satu.lv = 3;

	blocks.push_back(satu);

	satu.x = 1000;
	satu.y = 200;
	satu.l = 100;
	satu.t = 50;
	satu.w = w;
	satu.h = h;
	satu.lv = 2;

	blocks.push_back(satu);

	satu.x = 1200;
	satu.y = 200;
	satu.l = 100;
	satu.t = 50;
	satu.w = w;
	satu.h = h;
	satu.lv = 2;

	blocks.push_back(satu);

	/**/

	satu.x = 100;
	satu.y = 300;
	satu.l = 100;
	satu.t = 50;
	satu.w = w;
	satu.h = h;
	satu.lv = 2;

	blocks.push_back(satu);

	satu.x = 300;
	satu.y = 300;
	satu.l = 100;
	satu.t = 50;
	satu.w = w;
	satu.h = h;
	satu.lv = 1;

	blocks.push_back(satu);

	satu.x = 500;
	satu.y = 300;
	satu.l = 100;
	satu.t = 50;
	satu.w = w;
	satu.h = h;
	satu.lv = 2;

	blocks.push_back(satu);

	satu.x = 700;
	satu.y = 300;
	satu.l = 100;
	satu.t = 50;
	satu.w = w;
	satu.h = h;
	satu.lv = 1;

	blocks.push_back(satu);

	satu.x = 900;
	satu.y = 300;
	satu.l = 100;
	satu.t = 50;
	satu.w = w;
	satu.h = h;
	satu.lv = 2;

	blocks.push_back(satu);

	satu.x = 1100;
	satu.y = 300;
	satu.l = 100;
	satu.t = 50;
	satu.w = w;
	satu.h = h;
	satu.lv = 1;

	blocks.push_back(satu);

	satu.x = 1300;
	satu.y = 300;
	satu.l = 100;
	satu.t = 50;
	satu.w = w;
	satu.h = h;
	satu.lv = 2;

	blocks.push_back(satu);

	/**/
	
	satu.x = 200;
	satu.y = 400;
	satu.l = 100;
	satu.t = 50;
	satu.w = w;
	satu.h = h;
	satu.lv = 1;

	blocks.push_back(satu);

	satu.x = 400;
	satu.y = 400;
	satu.l = 100;
	satu.t = 50;
	satu.w = w;
	satu.h = h;
	satu.lv = 1;

	blocks.push_back(satu);

	satu.x = 600;
	satu.y = 400;
	satu.l = 100;
	satu.t = 50;
	satu.w = w;
	satu.h = h;
	satu.lv = 1;

	blocks.push_back(satu);

	satu.x = 800;
	satu.y = 400;
	satu.l = 100;
	satu.t = 50;
	satu.w = w;
	satu.h = h;
	satu.lv = 1;

	blocks.push_back(satu);

	satu.x = 1000;
	satu.y = 400;
	satu.l = 100;
	satu.t = 50;
	satu.w = w;
	satu.h = h;
	satu.lv = 1;

	blocks.push_back(satu);

	satu.x = 1200;
	satu.y = 400;
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
