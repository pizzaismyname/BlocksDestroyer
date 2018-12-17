#pragma once
#include "wx\wx.h"
#include "wx\dcbuffer.h"

class GameWindow;

class Frame :
	public wxFrame
{
private:
	wxWindow* window = nullptr;
	wxWindow* window2 = nullptr;
public:
	Frame(const wxString &title);
	void ShowGameWindow();
	void ShowMenuWindow();
	void ShowHtpWindow();
	void ShowPauseWindow();
	~Frame();
};

