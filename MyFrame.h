#pragma once
#include "wx\wx.h"

class MainMenuWindow;
class HtpWindow;
class GameWindow;
class MyFrame :
	public wxFrame
{
private:
	MainMenuWindow *mainMenuWindow;
	HtpWindow *htpWindow;
	GameWindow *gameWindow;
	wxBoxSizer *boxSizer;
public:
	MyFrame(const wxString &title);
	void showHtpWindow();
	void showMainMenuWindow();
	void showGameWindow();
	void fitWindowSize();
};

