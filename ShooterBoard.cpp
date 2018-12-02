#include "ShooterBoard.h"



ShooterBoard::ShooterBoard()
{
	this->loadBitmap();
}


ShooterBoard::~ShooterBoard()
{
}

void ShooterBoard::loadBitmap()
{
	wxImage image(wxT("assets\\53-Breakout-Tiles.png"), wxBITMAP_TYPE_PNG);
	image.Rescale(120, 32, wxIMAGE_QUALITY_NORMAL);
	board = new wxBitmap(image);

}