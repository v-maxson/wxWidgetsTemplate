#include "gui.h"
#include "app_data.h"

bool Gui::Application::OnInit() {
	auto* window = new MainWindow;
	window->Show(true);
	
	return true;
}

Gui::MainWindow::MainWindow() 
	: wxFrame(nullptr, wxID_ANY, AppData::APP_NAME) {

}
