#pragma once
#include "Frame.h"
#include "wx\wx.h"
class PauseWindow :
	public wxWindow
{
private:
	int w, h;
	Frame *parent;

	wxBitmap *mainMenuImg = nullptr;
	wxBitmap *mainMenuHoverImg = nullptr;
	wxBitmap *howToPlayImg = nullptr;
	wxBitmap *nextImg = nullptr;
	wxBitmap *nextHoverImg = nullptr;
	wxBitmap *prevImg = nullptr;
	wxBitmap *prevHoverImg = nullptr;
	wxBitmap *htpPage1Img = nullptr;
	wxBitmap *htpPage2Img = nullptr;
	wxBitmap *htpPage3Img = nullptr;
	wxBitmap *htpPage4Img = nullptr;

	wxStaticBitmap *htpTextStatic;
	wxBitmapButton *mainMenuBtn;
	wxBitmapButton *nextBtn;
	wxBitmapButton *prevBtn;

	int page = 1;
	void loadBitmap();
	DECLARE_EVENT_TABLE()
public:
	PauseWindow(Frame *parent);
	~PauseWindow();

	void OnPaint(wxPaintEvent &event);
	void goNextPage(wxCommandEvent &event);
	void goPrevPage(wxCommandEvent &event);
	void goMainMenu(wxCommandEvent &event);
	void checkPage();
};