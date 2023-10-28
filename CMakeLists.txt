# CMakeList.txt : CMake project for neural_network, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

# Enable Hot Reload for MSVC compilers if supported.
if (POLICY CMP0141)
  cmake_policy(SET CMP0141 NEW)
  set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
endif()

project ("neural_network")
set(CMAKE_CXX_STANDARD 17)
file(GLOB_RECURSE MY_SOURCES CONFIGURE_DEPENDS "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp")
message(STATUS "My source ===== ${MY_SOURCES}")
message(STATUS "Include folder ====== ${CMAKE_SOURCE_DIR}/include/")
add_executable (neural_network  "src/neural_network.cpp" "${MY_SOURCES}")
target_include_directories(neural_network PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include/")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET neural_network PROPERTY CXX_STANDARD 20)
endif()

# TODO: Add tests and install targets if needed.
