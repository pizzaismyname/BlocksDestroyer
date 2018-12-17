#include "HtpWindow.h"
#include "wx/stdpaths.h"
#include "wx/filename.h" 

BEGIN_EVENT_TABLE(HtpWindow, wxWindow)
EVT_PAINT(HtpWindow::OnPaint)
EVT_BUTTON(3001, HtpWindow::goNextPage)
EVT_BUTTON(3002, HtpWindow::goPrevPage)
EVT_BUTTON(3003, HtpWindow::goMainMenu)
END_EVENT_TABLE()


HtpWindow::HtpWindow(Frame *parent)
	: wxWindow(parent, wxID_ANY)
{
	parent->GetSize(&w, &h);
	this->SetSize(wxSize(w, h));

	this->SetBackgroundColour(wxColour(*wxBLACK));
	this->parent = parent;
	this->loadBitmap();

	nextBtn = new wxBitmapButton(this, 3001, *nextImg, wxPoint(1200, 400), wxDefaultSize, wxBORDER_NONE);
	prevBtn = new wxBitmapButton(this, 3002, *prevImg, wxPoint(100, 400), wxDefaultSize, wxBORDER_NONE);
	mainMenuBtn = new wxBitmapButton(this, 3003, *mainMenuImg, wxPoint(580, 670), wxDefaultSize, wxBORDER_NONE);

	

	mainMenuBtn->SetBitmapCurrent(*mainMenuHoverImg);
	nextBtn->SetBitmapCurrent(*nextHoverImg);
	prevBtn->SetBitmapCurrent(*prevHoverImg);
	checkPage();
}


HtpWindow::~HtpWindow()
{
	delete mainMenuImg;
	delete mainMenuHoverImg;
	delete howToPlayImg;
	delete nextImg;
	delete nextHoverImg;
	delete prevImg;
	delete prevHoverImg;
	delete htpPage1Img;
	delete htpPage2Img;
	delete htpPage3Img;
	delete htpPage4Img;

	delete mainMenuBtn;
	delete nextBtn;
	delete prevBtn;
}

void HtpWindow::OnPaint(wxPaintEvent &event)
{
	wxPaintDC pdc(this);
	if (page == 1)
	pdc.DrawBitmap(*howToPlayImg, wxPoint(0, 0), true);
	else
	pdc.DrawBitmap(*howToPlayImg2, wxPoint(0, 0), true);
}

void HtpWindow::goNextPage(wxCommandEvent &event)
{
	this->page = 2;
	checkPage();
}

void HtpWindow::goPrevPage(wxCommandEvent &event)
{
	this->page = 1;
	checkPage();
}

void HtpWindow::goMainMenu(wxCommandEvent &event)
{
	parent->ShowMenuWindow();
}

void HtpWindow::checkPage()
{


	if (page <= 1)
	{
		nextBtn->Show(true);
		prevBtn->Show(false);
	}
	else
	{
		nextBtn->Show(false);
		prevBtn->Show(true);
	}

	mainMenuBtn->Show(true);
	Refresh();
}

void HtpWindow::loadBitmap()
{
	wxImage image8(wxT("background/2.png"), wxBITMAP_TYPE_PNG);
	htpPage1Img = new wxBitmap(image8.Scale(w, h));

	wxImage image9(wxT("background/3.png"), wxBITMAP_TYPE_PNG);
	htpPage2Img = new wxBitmap(image9.Scale(w, h));

	wxImage image1(wxT("assets-menu/button_back-to-menu.png"), wxBITMAP_TYPE_PNG);
	mainMenuImg = new wxBitmap(image1);

	wxImage image2(wxT("assets-menu/button_back-to-menu_clicked.png"), wxBITMAP_TYPE_PNG);
	mainMenuHoverImg = new wxBitmap(image2);

	wxImage image3(wxT("background/2.png"), wxBITMAP_TYPE_PNG);
	howToPlayImg = new wxBitmap(image3.Scale(w,h));

	wxImage image20(wxT("background/3.png"), wxBITMAP_TYPE_PNG);
	howToPlayImg2 = new wxBitmap(image20.Scale(w, h));

	wxImage image4(wxT("assets-menu/button_right-arrow.png"), wxBITMAP_TYPE_PNG);
	nextImg = new wxBitmap(image4);

	wxImage image5(wxT("assets-menu/button_right-arrow_clicked.png"), wxBITMAP_TYPE_PNG);
	nextHoverImg = new wxBitmap(image5);

	wxImage image6(wxT("assets-menu/button_left-arrow.png"), wxBITMAP_TYPE_PNG);
	prevImg = new wxBitmap(image6);

	wxImage image7(wxT("assets-menu/button_left-arrow.png"), wxBITMAP_TYPE_PNG);
	prevHoverImg = new wxBitmap(image7);
}
