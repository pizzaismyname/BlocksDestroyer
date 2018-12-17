#include "CreditWindow.h"
#include "wx/stdpaths.h"
#include "wx/filename.h" 

BEGIN_EVENT_TABLE(CreditWindow, wxWindow)
	EVT_PAINT(CreditWindow::OnPaint)	
	EVT_BUTTON(3002, CreditWindow::goMainMenu)
END_EVENT_TABLE()


CreditWindow::CreditWindow(Frame *parent)
	: wxWindow(parent, wxID_ANY)
{
	parent->GetSize(&w, &h);
	this->SetSize(wxSize(w, h));

	this->SetBackgroundColour(wxColour(*wxBLACK));
	this->parent = parent;
	this->loadBitmap();


	
	mainMenuBtn = new wxBitmapButton(this, 3002, *mainMenuImg, wxPoint(600, 700), wxDefaultSize, wxBORDER_NONE);
	mainMenuBtn->SetBitmapCurrent(*mainMenuImg2);

	mainMenuBtn->Show(true);


	checkPage();
	/*htpBtn->Show(true);
	prevBtn->Show(true);*/
}


CreditWindow::~CreditWindow()
{	
	delete mainMenuBtn;
	delete background;
}

void CreditWindow::OnPaint(wxPaintEvent &event)
{
	wxPaintDC pdc(this);
	pdc.DrawBitmap(*background, wxPoint(0, 0), true);

}

void CreditWindow::goMainMenu(wxCommandEvent & event)
{
	parent->ShowMenuWindow();
}

void CreditWindow::checkPage()
{
	Refresh();
}

void CreditWindow::loadBitmap()
{
	wxImage image3(wxT("background/8.png"), wxBITMAP_TYPE_PNG);
	image3.Rescale(w, h, wxIMAGE_QUALITY_NORMAL);
	background = new wxBitmap(image3);

	wxImage image6(wxT("assets-menu/button_back-to-menu.png"), wxBITMAP_TYPE_PNG);
	mainMenuImg = new wxBitmap(image6);

	wxImage image7(wxT("assets-menu/button_back-to-menu_clicked.png"), wxBITMAP_TYPE_PNG);
	mainMenuImg2 = new wxBitmap(image7);
}
