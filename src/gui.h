#pragma once

#include <wx/wx.h>

namespace Gui {
	class Application : public wxApp {
	public:
		bool OnInit() override;
	};

	class MainWindow : public wxFrame {
	public:
		MainWindow();
	};
}