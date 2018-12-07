#include "wx\wx.h"
#include "Frame.h"

class BlocksDestroyer : public wxApp
{
public:
	virtual bool OnInit();
};

IMPLEMENT_APP(BlocksDestroyer)
DECLARE_APP(BlocksDestroyer)

bool BlocksDestroyer::OnInit()
{
	Frame *frame = new Frame("BlocksDestroyer");
	frame->Show(true);
	return true;
}