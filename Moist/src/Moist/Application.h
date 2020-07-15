#pragma once

#include "Core.h"

#include "Window.h"
#include "Moist/LayerStack.h"
#include "Moist/Events/Event.h"
#include "Moist/Events/ApplicationEvent.h"


namespace Moist {

	class MOIST_API Application {
	public:
		Application();
		virtual ~Application();

		void Run();
		
		void OnEvent(Event&);

		void PushLayer(Layer* layer);
		void PushOverlay(Layer* layer);
	private:
		bool OnWindowClose(WindowCloseEvent& e);

		std::unique_ptr<Window> m_Window;
		bool m_Running = true;
		LayerStack m_LayerStack;
	};

	Application* CreateApplication();

}