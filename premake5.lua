workspace "Moist"
	architecture "x64"
	startproject "Sandbox"

	configurations {
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "Moist"
	location "Moist"
	kind "SharedLib"
	language "C++"

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
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines {
			"MS_PLATFORM_WINDOWS",
			"MS_BUILD_DLL"
		}

		postbuildcommands {
			("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
		}

	filter "configurations:Debug"
		defines "MS_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "MS_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "MS_DIST"
		optimize "On"


project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"

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
		staticruntime "On"
		systemversion "latest"

		defines {
			"MS_PLATFORM_WINDOWS"
		}

	filter "configurations:Debug"
		defines "MS_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "MS_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "MS_DIST"
		optimize "On"