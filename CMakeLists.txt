# CMakeList.txt : CMake project for bestellijst-houtmaatje, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.12)

# Enable Hot Reload for MSVC compilers if supported.
if (POLICY CMP0141)
  cmake_policy(SET CMP0141 NEW)
  set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
endif()

project ("modern-cpp-tui")

# Add source files to this project's executable.
add_executable(tui_client "src/main.cpp" "src/handler/input_handler.cpp" "src/handler/command_handler.cpp" "src/core/commands/base_command.cpp" "src/core/commands/help_command.cpp")

find_package(glfw3 CONFIG REQUIRED)
target_link_libraries(tui_client PRIVATE glfw)

find_package(glm CONFIG REQUIRED)
target_link_libraries(tui_client PRIVATE glm::glm)

find_package(Vulkan REQUIRED)
target_link_libraries(tui_client PRIVATE Vulkan::Vulkan)

# Setting compiler's C++ version
if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET tui_client PROPERTY CXX_STANDARD 23)
endif()

target_include_directories(tui_client
        PRIVATE "${CMAKE_SOURCE_DIR}/include")

add_subdirectory(gtests)
