#include "wx\wx.h"
#include "MyFrame.h"

class MyApp : public wxApp
{
public:
	virtual bool OnInit();
};

IMPLEMENT_APP(MyApp)
DECLARE_APP(MyApp)

bool MyApp::OnInit()
{
	MyFrame *frame = new MyFrame("Blocks Destroyer");
	frame->Show(true);

	return true;
}