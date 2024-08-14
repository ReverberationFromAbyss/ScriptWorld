add_rules("mode.debug", "mode.release")

set_languages("c++latest")
set_policy("build.c++.modules", true)

local std_module_SOURCE_DIR = "..\\..\\..\\..\\..\\PKGs\\Store\\PLE\\llvm-mingw-20240619-ucrt-x86_64\\share\\libc++\\v1"
target("lua", function()
	set_kind("shared")
	add_defines("LUA_BUILD_AS_DLL")
	set_languages("c17")

	if is_kind("shared") and is_plat("windows") then
		add_rules("utils.symbols.export_all", { export_classes = true })
	end

	add_files("lib/lua/**.c")
end)

target("lua-header", function()
	set_kind("headeronly")
	add_rules("c")
	set_languages("c17")
	add_headerfiles("lib/lua/**.h")
end)

target("ScriptWorld", function()
	set_kind("binary")
	add_deps("lua")
	add_includedirs("lib/lua")
	add_links("lua")

	on_config(function(target)
		local _, toolname = target:tool("cxx")
		if toolname:find("clang", 1, true) then
			target:add(
				"cxxflags",
				"-stdlib=libc++",
				"-Wno-reserved-module-identifier",
				"-Wno-reserved-user-defined-literal"
			)
			target:add("ldflags", "-stdlib=libc++", "-Wl,-rpath='.'")
			target:add("files", std_module_SOURCE_DIR .. "\\std.cppm", std_module_SOURCE_DIR .. "\\std.compat.cppm")
			target:set("policy", "build.c++.modules.culling", false)
		end
		print(target:get("files"))
	end)

	add_files("src/**.cpp", "src/**.cc")
end)
