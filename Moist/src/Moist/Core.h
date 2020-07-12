#pragma once

// If we are running on Windows
#ifdef MS_PLATFORM_WINDOWS
	#ifdef MS_BUILD_DLL
		#define MOIST_API __declspec(dllexport)
	#else
		#define MOIST_API __declspec(dllimport)
	#endif
#else
	#error Moist Engine only supports Windows!
#endif

#ifdef MS_ENABLE_ASSERTS
	#define MS_ASSERT(x, ...) { if(!(x)) { MS_ERROR("Assertion Failed: {1}", __VA_ARGS__); __debugbreak(); } }
	#define MS_CORE_ASSERT(x, ...) { if(!(x)) { MS_CORE_ERROR("Assertion Failed: {1}", __VA_ARGS__); __debugbreak();  } }
#else
	#define MS_ASSERT(x, ...)
	#define MS_CORE_ASSERT(x, ...)
#endif

#define BIT(x) (1 << x)