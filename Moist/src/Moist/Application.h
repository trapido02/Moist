#pragma once

#include "Core.h"

namespace Moist {

	class MOIST_API Application {
	public:
		Application();
		virtual ~Application();

		void Run();
	};

	Application* CreateApplication();

}