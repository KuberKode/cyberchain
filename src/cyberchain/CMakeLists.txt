# CMakeList.txt : CMake project for cyberchain, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

project ("cyberchain")

# Add source to this project's executable.
add_executable (cyberchain "cyberchain.cpp" "cyberchain.h" "./core/globals.h" "./core/data.h" "./core/data.cpp")

# TODO: Add tests and install targets if needed.
add_executable (data_test "./tests/data_test.cpp" "./core/globals.h" "./core/data.h" "./core/data.cpp")