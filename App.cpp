#include "App.h"
#include "MainFrame.h"
#include "functions.h"
#include <wx/wx.h>
#include <algorithm>
#include <cctype>
#include <limits>


wxIMPLEMENT_APP(App);





bool App::OnInit() {
	wxApp* app = new wxApp();
	MainFrame* frame = new MainFrame("Mainframe");

	frame->SetClientSize(800, 600);
	frame->Center();
	frame->Show();

	return true;
}

