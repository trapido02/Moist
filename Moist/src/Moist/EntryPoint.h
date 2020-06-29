#pragma once

// If we are running on Windows
#ifdef MS_PLATFORM_WINDOWS

extern Moist::Application* Moist::CreateApplication();

int main(int argc, char** argv) {
	auto app = Moist::CreateApplication();
	app -> Run();
	delete app;
}

#endif // MS_PLATFORM_WINDOWS