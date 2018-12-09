#include "Frame.h"
#include "GameWindow.h"

Frame::Frame(const wxString &title)
	: wxFrame(NULL, -1, title)
{

	wxImageHandler *pngLoader = new wxPNGHandler();
	wxImage::AddHandler(pngLoader);

	this->ShowFullScreen(true);
	window = new GameWindow(this);
}


Frame::~Frame()
{
	delete window;
}
