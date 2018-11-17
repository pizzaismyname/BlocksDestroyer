#include "MyFrame.h"
#include "MainMenuWindow.h"
#include "HtpWindow.h"


MyFrame::MyFrame(const wxString &title)
	: wxFrame(NULL, wxID_ANY, title)
{
	boxSizer = new wxBoxSizer(wxVERTICAL);

	this->mainMenuWindow = new MainMenuWindow(this);
	this->mainMenuWindow->Show(false);
	this->boxSizer->Add(mainMenuWindow, 1, wxEXPAND, 0);

	this->htpWindow = new HtpWindow(this);
	this->htpWindow->Show(false);
	this->boxSizer->Add(htpWindow, 1, wxEXPAND, 0);

	SetSizer(boxSizer);
	showMainMenuWindow();
}

void MyFrame::showMainMenuWindow()
{
	this->mainMenuWindow->Show(true);
	this->htpWindow->Show(false);
	fitWindowSize();
}

void MyFrame::showHtpWindow()
{
	this->htpWindow->Show(true);
	this->mainMenuWindow->Show(false);
	this->SetSize(wxSize(1000, 700));
	fitWindowSize();
}

void MyFrame::fitWindowSize()
{
	this->boxSizer->Fit(this);
	this->boxSizer->SetSizeHints(this);
	this->SetSize(wxSize(1000, 700));
	this->Layout();
}


