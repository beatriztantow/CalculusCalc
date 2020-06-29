from conans import ConanFile, CMake, tools

class CalculadoraBatataConan(ConanFile):
    name = "CalculadoraBatata"
    version = "0.1"
    license = "AGPLv3+"
    generators = "cmake_find_package"
    requires = ["readline/8.0"]
    settings = "build_type","os"
    def build(self):
        cmake = CMake(self)
        cmake.configure()
        cmake.build()
