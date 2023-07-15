from conan import ConanFile
from conan.tools.cmake import CMakeToolchain, CMake, cmake_layout

class Linestar(ConanFile):
    name = "linestar"
    version = "0.0.1"
    license = "<License>"
    author = "21e8"
    url = "https://github.com/linestarlabs/linestar-cpp"
    description = "C++ client library for PLC Magnet Mover using Ethernet/IP communication"
    topics = ("plc", "apis", "controllers", "automation", "linestar")
    settings = "os", "compiler", "build_type", "arch"
    requires = ("boost/1.82.0")

    # Sources are located in the same place as this recipe, copy them to the recipe
    exports_sources = "CMakeLists.txt", "src/*", "include/*"

    def config_options(self):
        if self.settings.os == "Windows":
            del self.options.fPIC

    def layout(self):
        cmake_layout(self)

    def generate(self):
        tc = CMakeToolchain(self)
        tc.generate()

    def build(self):
        cmake = CMake(self)
        cmake.configure()
        cmake.build()

    def package(self):
        cmake = CMake(self)
        cmake.install()


    def build(self):
        cmake = CMake(self)
        cmake.configure()
        cmake.build()

    def package(self):
        self.copy("*.h", dst="include", src="src")
        self.copy("*linestar", dst="bin", keep_path=False)

    def package_info(self):
        self.cpp_info.libs = ["linestar"]

