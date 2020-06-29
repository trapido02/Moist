#pragma once

// If we are running on Windows
#ifdef MS_PLATFORM_WINDOWS

extern Moist::Application* Moist::CreateApplication();

int main(int argc, char** argv) {
	Moist::Log::Init();
	MS_CORE_WARN("Initialized log!");
	MS_INFO("Hello.");

	auto app = Moist::CreateApplication();
	app -> Run();
	delete app;
}

#endif // MS_PLATFORM_WINDOWS