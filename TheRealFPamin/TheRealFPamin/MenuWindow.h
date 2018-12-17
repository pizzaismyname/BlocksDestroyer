#pragma once
#include "Frame.h"
#include "wx\wx.h"
class MenuWindow :
	public wxWindow
{
private:
	int w, h;
	Frame *parent;

	wxBitmap *playImg = nullptr;
	wxBitmap *playImg2 = nullptr;
	wxBitmap *background = nullptr;
	wxBitmap *htpImg = nullptr;
	wxBitmap *htpImg2 = nullptr;
	wxBitmap *exitImg = nullptr;
	wxBitmap *exitImg2 = nullptr;
	wxBitmap *creditImg = nullptr;
	wxBitmap *creditImg2 = nullptr;
	wxBitmap *htpPage1Img = nullptr;
	wxBitmap *htpPage2Img = nullptr;
	wxBitmap *htpPage3Img = nullptr;
	wxBitmap *htpPage4Img = nullptr;

	wxStaticBitmap *htpTextStatic;
	wxBitmapButton *playBtn;
	wxBitmapButton *htpBtn;
	wxBitmapButton *exitBtn;
	wxBitmapButton *creditBtn;

	int page = 1;
	void loadBitmap();
	DECLARE_EVENT_TABLE()
public:
	MenuWindow(Frame *parent);
	~MenuWindow();

	void OnPaint(wxPaintEvent &event);
	void goHtpWindow(wxCommandEvent &event);
	void goExit(wxCommandEvent &event);
	void goGameWindow(wxCommandEvent &event);
	void goCreditWindow(wxCommandEvent &event);
	void checkPage();
};

