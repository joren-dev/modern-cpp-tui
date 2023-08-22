# CMakeList.txt : CMake subdir for gtests

cmake_minimum_required (VERSION 3.12)

# Enable Hot Reload for MSVC compilers if supported.
if (POLICY CMP0141)
  cmake_policy(SET CMP0141 NEW)
  set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
endif()

# Add tests source files and those they test.
add_executable(
  gtests 
  "gtest_example.cpp"
  )

target_link_libraries(
  gtests
  GTest::gtest_main
)

target_include_directories(gtests
        PRIVATE "${CMAKE_SOURCE_DIR}/include")

# Setting compiler's C++ version
if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET gtests PROPERTY CXX_STANDARD 20)
endif()

target_include_directories(tui_client
        PRIVATE "${CMAKE_SOURCE_DIR}/include")

# Unit testing
include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)

# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()

include(GoogleTest)
gtest_discover_tests(gtests)
