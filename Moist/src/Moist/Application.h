#pragma once

#include "Core.h"
#include "Events/Event.h"
#include "Moist/Events/ApplicationEvent.h"

#include "Window.h"

namespace Moist {

	class MOIST_API Application {
	public:
		Application();
		virtual ~Application();

		void OnEvent(Event&);
		void Run();

	private:
		bool OnWindowClose(WindowCloseEvent& e);

		std::unique_ptr<Window> m_Window;
		bool m_Running = true;
	};

	Application* CreateApplication();

}