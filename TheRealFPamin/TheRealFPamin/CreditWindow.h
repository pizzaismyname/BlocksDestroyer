#pragma once
#include "Frame.h"
#include "wx\wx.h"
class CreditWindow :
	public wxWindow
{
private:
	int w, h;
	Frame *parent;


	wxBitmap *background = nullptr;
	wxBitmap *mainMenuImg = nullptr;
	wxBitmap *mainMenuImg2 = nullptr;
	wxBitmapButton *mainMenuBtn;


	int page = 1;
	void loadBitmap();
	DECLARE_EVENT_TABLE()
public:
	CreditWindow(Frame *parent);
	~CreditWindow();

	void OnPaint(wxPaintEvent &event);
	void goMainMenu(wxCommandEvent &event);
	void checkPage();
};

