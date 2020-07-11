#pragma once

#include "Core.h"
#include "Events/Event.h"

namespace Moist {

	class MOIST_API Application {
	public:
		Application();
		virtual ~Application();

		void Run();
	};

	Application* CreateApplication();

}