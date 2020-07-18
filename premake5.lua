workspace "Moist"
	architecture "x64"
	startproject "Sandbox"

	configurations {
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

IncludeDir = {}
IncludeDir["GLFW"] = "Moist/vendor/GLFW/include"
IncludeDir["Glad"] = "Moist/vendor/Glad/include"
IncludeDir["ImGui"] = "Moist/vendor/imgui"

include "Moist/vendor/GLFW"
include "Moist/vendor/Glad"
include "Moist/vendor/imgui"

project "Moist"
	location "Moist"
	kind "SharedLib"
	language "C++"
	staticruntime "off"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	pchheader "mspch.h"
	pchsource "Moist/src/mspch.cpp"

	files {
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs {
		"%{prj.name}/src",
		"%{prj.name}/vendor/spdlog/include",
		"%{IncludeDir.GLFW}",
		"%{IncludeDir.Glad}",
		"%{IncludeDir.ImGui}"
	}

	links {
		"GLFW",
		"Glad",
		"ImGui",
		"opengl32.lib"
	}

	filter "system:windows"
		cppdialect "C++17"
		systemversion "latest"

		defines {
			"MS_PLATFORM_WINDOWS",
			"MS_BUILD_DLL",
			"GLFW_INCLUDE_NONE"
		}

		postbuildcommands {
			("{COPY} %{cfg.buildtarget.relpath} \"../bin/" .. outputdir .. "/Sandbox/\"")
		}

	filter "configurations:Debug"
		defines "MS_DEBUG"
		runtime "Debug"
		symbols "On"

	filter "configurations:Release"
		defines "MS_RELEASE"
		runtime "Release"
		optimize "On"

	filter "configurations:Dist"
		defines "MS_DIST"
		runtime "Release"
		optimize "On"


project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"
	staticruntime "off"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files {
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs {
		"Moist/vendor/spdlog/include",
		"Moist/src"
	}

	links {
		"Moist"
	}

	filter "system:windows"
		cppdialect "C++17"
		systemversion "latest"

		defines {
			"MS_PLATFORM_WINDOWS"
		}

	filter "configurations:Debug"
		defines "MS_DEBUG"
		runtime "Debug"
		symbols "On"

	filter "configurations:Release"
		defines "MS_RELEASE"
		runtime "Release"
		optimize "On"

	filter "configurations:Dist"
		defines "MS_DIST"
		runtime "Release"
		optimize "On"