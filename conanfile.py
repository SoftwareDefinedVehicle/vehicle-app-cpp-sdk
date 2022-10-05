# Copyright (c) 2022 Robert Bosch GmbH
#
# This program and the accompanying materials are made available under the
# terms of the Apache License, Version 2.0 which is available at
# https://www.apache.org/licenses/LICENSE-2.0.
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS, WITHOUT
# WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied. See the
# License for the specific language governing permissions and limitations
# under the License.
#
# SPDX-License-Identifier: Apache-2.0

from conans import ConanFile, tools
from conan.tools.cmake import CMakeToolchain, CMake, cmake_layout
import subprocess

class VehicleAppCppSdkConan(ConanFile):
    name = "vehicle-app-sdk"
    version = "0.1"
    license = "Apache-2.0"
    url = "https://github.com/eclipse-velocitas/vehicle-app-cpp-sdk"
    description = "The Vehicle App SDK for c++ allows to create Vehicle Apps from the Velocitas development model in the c++ programming language."
    requires = "openssl/1.1.1q", "libcurl/7.84.0", "nlohmann_json/3.11.2", "paho-mqtt-cpp/1.2.0", "grpc/1.48.0", "protobuf/3.21.4", "cpr/1.9.0", "fmt/9.1.0"
    build_requires = "protobuf/3.21.4"
    generators = "cmake"
    author = "Robert Bosch GmbH"


    scm = {
        "type": "git",  # Use "type": "svn", if local repo is managed using SVN
        "subfolder": "VehicleAppCppSdk",
        "url": "auto",
        "revision": "auto"
     }

    # Binary configuration
    settings = "os", "compiler", "build_type", "arch"
    options = {"shared": [True, False], "fPIC": [True, False]}
    default_options = {"shared": False, "fPIC": True}

    # Sources are located in the same place as this recipe, copy them to the recipe
    exports_sources = "build.sh", "build/conanbuildinfo.cmake", "CMakeLists.txt", "sdk/*", "examples/*", "conanfile.py", ".conan/profiles/*"

    def config_options(self):
        if self.settings.os == "Linux":
            del self.options.fPIC

    def configure(self):
        self.options["grpc"].csharp_plugin = False
        self.options["grpc"].node_plugin = False
        self.options["grpc"].objective_c_plugin = False
        self.options["grpc"].php_plugin = False
        self.options["grpc"].python_plugin = False
        self.options["grpc"].ruby_plugin = False

        

    def layout(self):
        cmake_layout(self, src_folder="sdk")

    def generate(self):
        #tc = CMakeToolchain(self)
        #tc.generate()
        # commented out since we rely on our build script to set up cmake
        pass

    def build(self):
        build_type = self.settings.get_safe("build_type", default="Release").lower()
        option = "-r" if build_type == "release" else "-d"
        subprocess.call(f"cd ../.. && ./build.sh {option} --no-examples --no-app", shell=True)

    def package(self):
        subprocess.call("pwd", shell=True)
        self.copy("sdk/include/*.h", src="..", keep_path=True)
        self.copy("*.h", src="../build/gens", dst="sdk/include", keep_path=True)
        self.copy("libvehicle-app-sdk.a", src="../build/lib", dst="lib", keep_path=False)

    def package_info(self):
        self.cpp_info.libs = ["VehicleAppCppSdk"]

    def imports(self):
        self.copy("license*", src=".", dst="./licenses", folder=True, ignore_case=True)