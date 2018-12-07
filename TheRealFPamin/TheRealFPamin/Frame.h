#pragma once
#include "wx\wx.h"

class GameWindow;

class Frame :
	public wxFrame
{
private:
	wxWindow* window;
public:
	Frame(const wxString &title);
	~Frame();
};

