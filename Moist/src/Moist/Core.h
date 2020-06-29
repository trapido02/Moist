#pragma once

// If we are running on Windows
#ifdef MS_PLATFORM_WINDOWS
	#ifdef MS_BUILD_DLL
		#define MOIST_API __declspec(dllexport)
	#else
		#define MOIST_API __declspec(dllimport)
	#endif // MS_BUILD_DLL
#else
	#error Moist Engine only supports Windows!
#endif // MS_PLATFORM_WINDOWS
