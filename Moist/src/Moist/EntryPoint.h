#pragma once

// If we are running on Windows
#ifdef MS_PLATFORM_WINDOWS

extern Moist::Application* Moist::CreateApplication();

int main(int argc, char** argv) {
	// Initialize logger
	Moist::Log::Init();
	// Create Moist application (Startup)
	auto app = Moist::CreateApplication();
	// Run the Moist application (Runtime)
	app -> Run();
	// Delete the Moist application (Shutdown)
	delete app;
}

#endif // MS_PLATFORM_WINDOWS