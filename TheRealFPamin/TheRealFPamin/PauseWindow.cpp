#include "PauseWindow.h"
#include "wx/stdpaths.h"
#include "wx/filename.h" 

BEGIN_EVENT_TABLE(PauseWindow, wxWindow)
	EVT_PAINT(PauseWindow::OnPaint)
	EVT_BUTTON(3001, PauseWindow::goNextPage)
	EVT_BUTTON(3002, PauseWindow::goPrevPage)
	EVT_BUTTON(3003, PauseWindow::goMainMenu)
END_EVENT_TABLE()

PauseWindow::PauseWindow(Frame *parent)
	: wxWindow(parent, wxID_ANY)
{
	parent->GetSize(&w, &h);
	this->SetSize(wxSize(w, h));
	
	this->SetBackgroundColour(wxColour(*wxBLACK));
	this->parent = parent;
	this->loadBitmap();

	nextBtn = new wxBitmapButton(this, 3001, *nextImg, wxPoint(800, 300), wxDefaultSize, wxBORDER_NONE);
	prevBtn = new wxBitmapButton(this, 3002, *prevImg, wxPoint(100, 300), wxDefaultSize, wxBORDER_NONE);
	mainMenuBtn = new wxBitmapButton(this, 3003, *mainMenuImg, wxPoint(380, 550), wxDefaultSize, wxBORDER_NONE);

	mainMenuBtn->SetBitmapCurrent(*mainMenuHoverImg);
	nextBtn->SetBitmapCurrent(*nextHoverImg);
	prevBtn->SetBitmapCurrent(*prevHoverImg);
	checkPage();
	nextBtn->Show(true);
	prevBtn->Show(true);
}


PauseWindow::~PauseWindow()
{
	delete mainMenuImg;
	delete mainMenuHoverImg;
	delete howToPlayImg;
	delete nextImg;
	delete nextHoverImg;
	delete prevImg;
	delete prevHoverImg;

	delete mainMenuBtn;
	delete nextBtn;
	delete prevBtn;
}

void PauseWindow::OnPaint(wxPaintEvent &event)
{
	wxPaintDC pdc(this);
	pdc.DrawBitmap(*howToPlayImg, wxPoint(0, 0), true);

}

void PauseWindow::goNextPage(wxCommandEvent &event)
{
	parent->ShowHtpWindow();
}

void PauseWindow::goPrevPage(wxCommandEvent & event)
{
	this->parent->Close(true);
}

void PauseWindow::goMainMenu(wxCommandEvent &event)
{
	parent->ShowGameWindow();
}

void PauseWindow::checkPage()
{
	nextBtn->Show(true);
	prevBtn->Show(true);

	mainMenuBtn->Show(true);
	Refresh();
}

void PauseWindow::loadBitmap()
{
	wxImage image1(wxT("assets-menu/button_play.png"), wxBITMAP_TYPE_PNG);
	mainMenuImg = new wxBitmap(image1);

	wxImage image2(wxT("assets-menu/button_play_clicked.png"), wxBITMAP_TYPE_PNG);
	mainMenuHoverImg = new wxBitmap(image2);

	wxImage image3(wxT("background/1.png"), wxBITMAP_TYPE_PNG);
	image3.Rescale(w, h, wxIMAGE_QUALITY_NORMAL);
	howToPlayImg = new wxBitmap(image3);

	wxImage image4(wxT("assets-menu/button_how-to-play.png"), wxBITMAP_TYPE_PNG);
	nextImg = new wxBitmap(image4);


	wxImage image5(wxT("assets-menu/button_how-to-play_clicked.png"), wxBITMAP_TYPE_PNG);
	nextHoverImg = new wxBitmap(image5);

	wxImage image6(wxT("assets-menu/button_quit.png"), wxBITMAP_TYPE_PNG);
	prevImg = new wxBitmap(image6);

	wxImage image7(wxT("assets-menu/button_quit_clicked.png"), wxBITMAP_TYPE_PNG);
	prevHoverImg = new wxBitmap(image7);
}