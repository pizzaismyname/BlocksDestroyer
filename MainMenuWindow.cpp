#include "MainMenuWindow.h"
#include "wx/filename.h"
#include "wx/stdpaths.h"

BEGIN_EVENT_TABLE(MainMenuWindow, wxWindow)
EVT_PAINT(MainMenuWindow::OnPaint)
EVT_BUTTON(1001, MainMenuWindow::OnButtonClick)
EVT_BUTTON(1002, MainMenuWindow::OnButtonClick2)
EVT_BUTTON(1003, MainMenuWindow::OnButtonClick3)
END_EVENT_TABLE()



MainMenuWindow::MainMenuWindow(MyFrame *parent)
	:wxWindow(parent, wxID_ANY)
{
	this->SetBackgroundColour(wxColour(*wxWHITE));
	wxImageHandler *jpegLoader = new wxJPEGHandler();
	wxImage::AddHandler(jpegLoader);

	this->loadBackgroundBitmap();
	this->parent = parent;

	wxButton *button = new wxButton(this, 1001, wxT("PLAY"), wxPoint(270, 130), wxDefaultSize);
	wxButton *button2 = new wxButton(this, 1002, wxT("HOW TO PLAY"), wxPoint(270, 260), wxDefaultSize);
	wxButton *button3 = new wxButton(this, 1003, wxT("EXIT"), wxPoint(270, 300), wxDefaultSize);
}


MainMenuWindow::~MainMenuWindow()
{
	delete backgroundBitmap;
}

void MainMenuWindow::loadBackgroundBitmap()
{
	wxImage image(wxT("assets/charblue.jpg"), wxBITMAP_TYPE_JPEG);
	backgroundBitmap = new wxBitmap(image);
}

void MainMenuWindow::OnButtonClick(wxCommandEvent &event)
{
	wxMessageBox(wxT("Event Klik Terjadi pada Tombol Play"));
}

void MainMenuWindow::OnButtonClick2(wxCommandEvent &event)
{
	parent->showHtpWindow();
}

void MainMenuWindow::OnButtonClick3(wxCommandEvent &event)
{
	wxMessageBox(wxT("Event Klik Terjadi pada Tombol Exit"));
}

void MainMenuWindow::OnPaint(wxPaintEvent &event)
{
	wxPaintDC pdc(this);
	if (backgroundBitmap != nullptr)
	{
		pdc.DrawBitmap(*backgroundBitmap, wxPoint(150, 100), true);
	}
}