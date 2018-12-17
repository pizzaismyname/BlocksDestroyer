#pragma once
#include "wx\wx.h"
#include "wx\dcbuffer.h"

class GameWindow;

class Frame :
	public wxFrame
{
private:
	wxWindow* window = nullptr;
public:
	Frame(const wxString &title);
	void ShowGameWindow();
	void ShowMenuWindow();
	void ShowHtpWindow();
	~Frame();
};

