#pragma once
#include "wx\wx.h"
#include "MyFrame.h"

class MainMenuWindow :
	public wxWindow
{
private:
	wxBitmap *backgroundBitmap = nullptr;
	MyFrame *parent;
	void loadBackgroundBitmap();
	DECLARE_EVENT_TABLE()
public:
	MainMenuWindow(MyFrame *parent);
	~MainMenuWindow();

	void OnPaint(wxPaintEvent &event);
	void OnButtonClick(wxCommandEvent &event);
	void OnButtonClick2(wxCommandEvent &event);
	void OnButtonClick3(wxCommandEvent &event);

};

