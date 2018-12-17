#include "MenuWindow.h"
#include "wx/stdpaths.h"
#include "wx/filename.h" 

BEGIN_EVENT_TABLE(MenuWindow, wxWindow)
	EVT_PAINT(MenuWindow::OnPaint)
	EVT_BUTTON(3001, MenuWindow::goHtpWindow)
	EVT_BUTTON(3002, MenuWindow::goExit)
	EVT_BUTTON(3003, MenuWindow::goGameWindow)
	EVT_BUTTON(3004, MenuWindow::goCreditWindow)
END_EVENT_TABLE()


MenuWindow::MenuWindow(Frame *parent)
	: wxWindow(parent, wxID_ANY)
{	
	parent->GetSize(&w, &h);
	this->SetSize(wxSize(w, h));
	wxImageHandler *jpegLoader = new wxJPEGHandler();
	wxImage::AddHandler(jpegLoader);
	wxImageHandler *pngLoader = new wxPNGHandler();
	wxImage::AddHandler(pngLoader);
	this->SetBackgroundColour(wxColour(*wxBLACK));
	this->parent = parent;
	this->loadBitmap();

	htpBtn = new wxBitmapButton(this, 3001, *htpImg, wxPoint(400, 500), wxDefaultSize, wxBORDER_NONE);
	exitBtn = new wxBitmapButton(this, 3002, *exitImg, wxPoint(600, 650), wxDefaultSize, wxBORDER_NONE);
	playBtn = new wxBitmapButton(this, 3003, *playImg, wxPoint(600, 350), wxDefaultSize, wxBORDER_NONE);
	creditBtn = new wxBitmapButton(this, 3004, *creditImg, wxPoint(800, 500), wxDefaultSize, wxBORDER_NONE);

	playBtn->SetBitmapCurrent(*playImg2);
	htpBtn->SetBitmapCurrent(*htpImg2);
	exitBtn->SetBitmapCurrent(*exitImg2);
	creditBtn->SetBitmapCurrent(*creditImg2);
	checkPage();
	/*htpBtn->Show(true);
	prevBtn->Show(true);*/
}


MenuWindow::~MenuWindow()
{
	
	delete playBtn;
	delete htpBtn;
	delete exitBtn;
	delete creditBtn;

	delete creditImg;

	delete playImg;
	delete playImg2;
	delete background;
	delete htpImg;
	delete htpImg2;
	delete exitImg;
	delete exitImg2;
	delete htpPage1Img;
	delete htpPage2Img;
}

void MenuWindow::OnPaint(wxPaintEvent &event)
{
	wxPaintDC pdc(this);
	pdc.DrawBitmap(*background, wxPoint(0, 0), true);
	
}

void MenuWindow::goHtpWindow(wxCommandEvent &event)
{
	parent->ShowHtpWindow();
}

void MenuWindow::goExit(wxCommandEvent & event)
{
	this->parent->Close(true);
}

void MenuWindow::goGameWindow(wxCommandEvent &event)
{
	parent->ShowGameWindow();
}

void MenuWindow::goCreditWindow(wxCommandEvent & event)
{
	parent->ShowCreditWindow();
}

void MenuWindow::checkPage()
{
	htpBtn->Show(true);
	exitBtn->Show(true);
	creditBtn->Show(true);
	
	playBtn->Show(true);
	Refresh();
}

void MenuWindow::loadBitmap()
{
	wxImage image1(wxT("assets-menu/button_play.png"), wxBITMAP_TYPE_PNG);
	playImg = new wxBitmap(image1);

	wxImage image2(wxT("assets-menu/button_play_clicked.png"), wxBITMAP_TYPE_PNG);
	playImg2 = new wxBitmap(image2);

	wxImage image3(wxT("background/1.png"), wxBITMAP_TYPE_PNG);
	image3.Rescale(w, h, wxIMAGE_QUALITY_NORMAL);
	background = new wxBitmap(image3);

	wxImage image4(wxT("assets-menu/button_how-to-play.png"), wxBITMAP_TYPE_PNG);
	htpImg = new wxBitmap(image4);

	wxImage image5(wxT("assets-menu/button_how-to-play_clicked.png"), wxBITMAP_TYPE_PNG);
	htpImg2 = new wxBitmap(image5);

	wxImage image6(wxT("assets-menu/button_quit.png"), wxBITMAP_TYPE_PNG);
	exitImg = new wxBitmap(image6);

	wxImage image7(wxT("assets-menu/button_quit_clicked.png"), wxBITMAP_TYPE_PNG);
	exitImg2 = new wxBitmap(image7);

	wxImage image8(wxT("assets-menu/button_credits.png"), wxBITMAP_TYPE_PNG);
	creditImg = new wxBitmap(image8);

	wxImage image9(wxT("assets-menu/button_credits_clicked.png"), wxBITMAP_TYPE_PNG);
	creditImg2 = new wxBitmap(image9);
}
