#pragma once
#include "wx\wx.h"

class MainMenuWindow;
class HtpWindow;

class MyFrame :
	public wxFrame
{
private:
	MainMenuWindow *mainMenuWindow;
	HtpWindow *htpWindow;
	wxBoxSizer *boxSizer;
public:
	MyFrame(const wxString &title);
	void showHtpWindow();
	void showMainMenuWindow();
	void fitWindowSize();
};

