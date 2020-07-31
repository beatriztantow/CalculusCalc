from conans import ConanFile, CMake, tools

class CalculadoraBatataConan(ConanFile):
    name = "CalculadoraBatata"
    version = "0.1"
    license = "AGPLv3+"
    generators = "cmake_find_package"
    settings = "build_type","os"
    options = {"UI": ["CLI","GUI","WEB"]}
    default_options={"UI":"CLI"}

    def build(self):
        cmake = CMake(self)
        cmake.definitions["UI"]=self.options.get_safe("UI")
        cmake.configure()
        cmake.build()
