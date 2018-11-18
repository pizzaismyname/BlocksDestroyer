#include "wx/wx.h"
#include "MyFrame.h"

BEGIN_EVENT_TABLE(MyFrame, wxFrame)
	EVT_BUTTON(wxID_ANY, MyFrame::OnButtonClick)
END_EVENT_TABLE()

MyFrame::MyFrame(const wxString &title)
	: wxFrame(NULL, wxID_ANY, title)
{
	this->SetInitialSize(wxSize(1366, 666));
	wxPanel *panel = new wxPanel(this, wxID_ANY);
	wxButton *buttonPlay = new wxButton(panel, wxID_ANY, wxT("Play!"), wxPoint(652, 200), wxDefaultSize);
	wxButton *buttonHowTo = new wxButton(panel, wxID_ANY, wxT("How To Play"), wxPoint(652, 300), wxDefaultSize);
	wxButton *buttonExit = new wxButton(panel, wxID_ANY, wxT("Exit"), wxPoint(652, 400), wxDefaultSize);
}

void MyFrame::OnButtonClick(wxCommandEvent & event)
{
	wxMessageBox(wxT("Main yuk"));
}
