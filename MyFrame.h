#pragma once
#include "wx/wx.h"
class MyFrame :
	public wxFrame
{
public:
	MyFrame(const wxString &title);
	void OnButtonClick(wxCommandEvent &event);
private:
	DECLARE_EVENT_TABLE()
};
