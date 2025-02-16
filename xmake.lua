add_rules("mode.debug", "mode.release")

add_repositories("liteldev-repo https://github.com/LiteLDev/xmake-repo.git")
add_repositories("miracleforest-repo https://github.com/MiracleForest/xmake-repo.git")

add_requires("levilamina 1.0.1", {configs = {target_type = "server"}})
add_requires("levibuildscript 0.3.0")
add_requires("ilistenattentively 0.2.3")

if not has_config("vs_runtime") then
    set_runtimes("MD")
end

target("NatPortFixer ")
    add_rules("@levibuildscript/linkrule")
    add_rules("@levibuildscript/modpacker")
    add_cxflags(
        "/EHa",
        "/utf-8", 
        "/W4",
        "/w44265",
        "/w44289",
        "/w44296",
        "/w45263", 
        "/w44738", 
        "/w45204"
    )
    add_defines(
        "NOMINMAX", 
        "UNICODE", 
        "_HAS_CXX17",
        "_HAS_CXX20",
        "_HAS_CXX23"
    )
    add_packages(
        "levilamina",
        "ilistenattentively"
    )
    set_exceptions("none")
    set_kind("shared")
    set_languages("cxx20")
    set_symbols("debug")
    add_files("src/**.cpp")
    add_includedirs("src")
    set_optimize("fastest")