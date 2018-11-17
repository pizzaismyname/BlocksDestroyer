#include "HtpWindow.h"
#include "wx/stdpaths.h"
#include "wx/filename.h" 

BEGIN_EVENT_TABLE(HtpWindow, wxWindow)
EVT_PAINT(HtpWindow::OnPaint)
EVT_BUTTON(3001, HtpWindow::goNextPage)
EVT_BUTTON(3002, HtpWindow::goPrevPage)
EVT_BUTTON(3003, HtpWindow::goMainMenu)
END_EVENT_TABLE()


HtpWindow::HtpWindow(MyFrame *parent)
	: wxWindow(parent, wxID_ANY)
{
	this->SetBackgroundColour(wxColour(*wxBLACK));
	this->parent = parent;
	this->loadBitmap();

	nextBtn = new wxBitmapButton(this, 3001, *nextImg, wxPoint(800, 300), wxDefaultSize, wxBORDER_NONE);
	prevBtn = new wxBitmapButton(this, 3002, *prevImg, wxPoint(100, 300), wxDefaultSize, wxBORDER_NONE);
	mainMenuBtn = new wxBitmapButton(this, 3003, *mainMenuImg, wxPoint(380, 550), wxDefaultSize, wxBORDER_NONE);

	htpTextStatic = new wxStaticBitmap(this, wxID_ANY, *htpPage1Img, wxPoint(270, 100), wxDefaultSize, wxBORDER_NONE);

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

	delete htpTextStatic;
	delete mainMenuBtn;
	delete nextBtn;
	delete prevBtn;
}

void HtpWindow::OnPaint(wxPaintEvent &event)
{
	wxPaintDC pdc(this);
	pdc.DrawBitmap(*howToPlayImg, wxPoint(290, 10), true);
}

void HtpWindow::goNextPage(wxCommandEvent &event)
{
	this->page += 1;
	checkPage();
}

void HtpWindow::goPrevPage(wxCommandEvent &event)
{
	this->page -= 1;
	checkPage();
}

void HtpWindow::goMainMenu(wxCommandEvent &event)
{
	parent->showMainMenuWindow();
}

void HtpWindow::checkPage()
{


	if (page <= 1)
	{
		nextBtn->Show(true);
		prevBtn->Show(false);
	}
	else if (page >= 4)
	{
		nextBtn->Show(false);
		prevBtn->Show(true);
	}
	else
	{
		nextBtn->Show(true);
		prevBtn->Show(true);
	}

	if (page == 1) htpTextStatic->SetBitmap(*htpPage1Img);
	else if (page == 2) htpTextStatic->SetBitmap(*htpPage2Img);
	else if (page == 3) htpTextStatic->SetBitmap(*htpPage3Img);
	else if (page == 4) htpTextStatic->SetBitmap(*htpPage4Img);
	mainMenuBtn->Show(true);
	Refresh();
}

void HtpWindow::loadBitmap()
{
	wxImage image1(wxT("assets/mainMenuImg.jpg"), wxBITMAP_TYPE_JPEG);
	mainMenuImg = new wxBitmap(image1);

	wxImage image2(wxT("assets/mainMenuHoverImg.jpg"), wxBITMAP_TYPE_JPEG);
	mainMenuHoverImg = new wxBitmap(image2);

	wxImage image3(wxT("assets/howToPlayImg.jpg"), wxBITMAP_TYPE_JPEG);
	howToPlayImg = new wxBitmap(image3);

	wxImage image4(wxT("assets/nextImg.jpg"), wxBITMAP_TYPE_JPEG);
	nextImg = new wxBitmap(image4);


	wxImage image5(wxT("assets/nextHoverImg.jpg"), wxBITMAP_TYPE_JPEG);
	nextHoverImg = new wxBitmap(image5);

	wxImage image6(wxT("assets/prevImg.jpg"), wxBITMAP_TYPE_JPEG);
	prevImg = new wxBitmap(image6);

	wxImage image7(wxT("assets/prevHoverImg.jpg"), wxBITMAP_TYPE_JPEG);
	prevHoverImg = new wxBitmap(image7);

	wxImage image8(wxT("assets/htpPage1Img.jpg"), wxBITMAP_TYPE_JPEG);
	htpPage1Img = new wxBitmap(image8.Scale(450, 450));

	wxImage image9(wxT("assets/htpPage2Img.jpg"), wxBITMAP_TYPE_JPEG);
	htpPage2Img = new wxBitmap(image9.Scale(450, 450));

	wxImage image10(wxT("assets/htpPage3Img.jpg"), wxBITMAP_TYPE_JPEG);
	htpPage3Img = new wxBitmap(image10.Scale(450, 450));

	wxImage image11(wxT("assets/htpPage4Img.jpg"), wxBITMAP_TYPE_JPEG);
	htpPage4Img = new wxBitmap(image10.Scale(450, 450));

}
