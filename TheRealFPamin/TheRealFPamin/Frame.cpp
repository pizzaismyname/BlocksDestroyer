#include "Frame.h"
#include "GameWindow.h"
#include "MenuWindow.h"
#include "HtpWindow.h"
#include "CreditWindow.h"

Frame::Frame(const wxString &title)
	: wxFrame(NULL, -1, title)
{
	wxImageHandler *pngLoader = new wxPNGHandler();
	wxImage::AddHandler(pngLoader);

	this->ShowFullScreen(true);
	ShowMenuWindow();
}

void Frame::ShowGameWindow()
{	
	//if(window!=nullptr)
	window->Destroy();
	window = new GameWindow(this);
}

void Frame::ShowMenuWindow()
{	
	if (window != nullptr)
	window->Destroy();
	window = new MenuWindow(this);
}

void Frame::ShowHtpWindow()
{
	window->Destroy();
	window = new HtpWindow(this);
}

void Frame::ShowCreditWindow()
{
	window->Destroy();
	window = new CreditWindow(this);
}




Frame::~Frame()
{
	delete window;
}
