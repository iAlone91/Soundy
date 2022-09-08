workspace "Soundy"
    architecture "x64"

    configurations
    {
        "Debug",
        "Release",
        "Dist"
    }

outputdir = "{%cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "Soundy"
    location "Soundy"
    kind "ConsoleApp"
    language "c++"

    targetdir   ("bin/" .. outputdir .. "/%prj.name")
    objdir      ("bin-int/" .. outputdir .. "/%prj.name")

    files
    {
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.cpp",
    }

    includedirs
    {
        "%{prj.name}/vendor/sdl/include"
    }

    filter "system:windows"
        cppdialect "c++17"
        staticruntime "on"
        systemversion "latest"

        postbuildcommands
        {
           ("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/sandbox")
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