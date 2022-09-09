workspace "Soundy"
    architecture "x64"

    configurations
    {
        "Debug",
        "Release",
        "Dist"
    }

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "Soundy"
    location "Soundy"
    kind "ConsoleApp"
    language "c++"

    targetdir   ("bin/" .. outputdir .. "/%{prj.name}")
    objdir      ("bin-int/" .. outputdir .. "/%{prj.name}")

    files
    {
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.cpp",
    }

    includedirs
    {
        "%{prj.name}/vendor/SDL2/include"
    }

    links
    {
        "Soundy/vendor/SDL2/bin/*.lib"
    }

    filter "system:windows"
        cppdialect "c++17"
        staticruntime "on"
        systemversion "latest"

        postbuildcommands 
        {
            "{COPY} %{prj.location}/vendor/SDL2/bin/*SDL2.dll ../bin/" .. outputdir .. "/%{prj.name}/"
        }

        filter "configurations:Debug"
            defines "DEBUG"
            symbols "On"

        filter "configurations:Release"
            defines "RELEASE"
            optimize "On"

        filter "configurations:Dist"
            defines "DIST"
            optimize "On"