#pragma once
#include "BaseBoard.h"
class ShooterBoard :
	public BaseBoard
{
protected:
	virtual void loadBitmap();
public:
	ShooterBoard();
	~ShooterBoard();
};

