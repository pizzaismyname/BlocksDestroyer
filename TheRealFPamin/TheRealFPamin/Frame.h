#pragma once
#include "wx\wx.h"
#include "wx\dcbuffer.h"

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

