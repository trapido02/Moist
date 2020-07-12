#include "mspch.h"
#include "Application.h"

#include "Moist/Events/ApplicationEvent.h"
#include "Moist/Log.h"

namespace Moist {

	// Constructor
	Application::Application() {
		m_Window = std::unique_ptr<Window>(Window::Create());
	}

	// Destructor
	Application::~Application() {

	}

	// Main application loop
	void Application::Run() {
		while (m_Running) {

			m_Window->OnUpdate();
		}
	}

}