#include "Application.h"

#include "Moist/Events/ApplicationEvent.h"
#include "Moist/Log.h"

namespace Moist {

	// Constructor
	Application::Application() {

	}

	// Destructor
	Application::~Application() {

	}

	// Main application loop
	void Application::Run() {
		WindowResizeEvent e(1280, 720);
		MS_TRACE(e);

		while (true);
	}

}