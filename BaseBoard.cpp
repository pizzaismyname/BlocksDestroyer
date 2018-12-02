#include "BaseBoard.h"
#include "GameWindow.h"
#include "wx\stdpaths.h"
#include "wx\filename.h"


BaseBoard::BaseBoard()
{
	wxImageHandler *pngLoader = new wxPNGHandler();
	wxImage::AddHandler(pngLoader);
	this->loadBitmap();
}

wxBitmap BaseBoard::getBitmap()
{
	return *board;
}

void BaseBoard::move(char key)
{
	if (key == 'A')
	{
		this->x -= 10;
	}

	if (key == 'D')
	{
		this->x += 10;
	}
}




BaseBoard::~BaseBoard()
{
	delete board;
	//delete pngLoader;
}


void BaseBoard::loadBitmap()
{
	wxImage image(wxT("assets\\50-Breakout-Tiles.png"), wxBITMAP_TYPE_PNG);
	image.Rescale(120,32, wxIMAGE_QUALITY_NORMAL);
	board = new wxBitmap(image);
	
}

int BaseBoard::getHeight()
{
	return height;
}

int BaseBoard::getWidth()
{
	return width;
}

int BaseBoard::getX()
{
	return x;
}

int BaseBoard::getY()
{
	return y;
}