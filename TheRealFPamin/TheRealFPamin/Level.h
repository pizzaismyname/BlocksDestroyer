#pragma once
#include <vector>
using namespace std;
struct Balok {

	int x, y, l, t, w, h, lv;
};


class Level
{
public:
	Level(int w, int h);
	~Level();

	Balok satu;
	vector <Balok> blocks;
};

