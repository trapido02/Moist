#pragma once

#include "Core.h"
#include "spdlog/spdlog.h"
#include "spdlog/fmt/ostr.h"

namespace Moist {

	class MOIST_API Log {
	public:
		static void Init();

		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }

	private:
		static std::shared_ptr < spdlog::logger> s_CoreLogger;
		static std::shared_ptr < spdlog::logger> s_ClientLogger;
	};

}


// Define core log macros
#define MS_CORE_FATAL(...)::Moist::Log::GetCoreLogger()->fatal(__VA_ARGS__)
#define MS_CORE_ERROR(...)::Moist::Log::GetCoreLogger()->error(__VA_ARGS__)
#define MS_CORE_WARN(...)::Moist::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define MS_CORE_INFO(...)::Moist::Log::GetCoreLogger()->info(__VA_ARGS__)
#define MS_CORE_TRACE(...)::Moist::Log::GetCoreLogger()->trace(__VA_ARGS__)

// Define client log macros
#define MS_FATAL(...)::Moist::Log::GetClientLogger()->fatal(__VA_ARGS__)
#define MS_ERROR(...)::Moist::Log::GetClientLogger()->error(__VA_ARGS__)
#define MS_WARN(...)::Moist::Log::GetClientLogger()->warn(__VA_ARGS__)
#define MS_INFO(...)::Moist::Log::GetClientLogger()->info(__VA_ARGS__)
#define MS_TRACE(...)::Moist::Log::GetClientLogger()->trace(__VA_ARGS__)