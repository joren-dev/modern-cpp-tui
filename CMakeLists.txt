﻿# CMakeList.txt : CMake project for bestellijst-houtmaatje, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.12)

# Enable Hot Reload for MSVC compilers if supported.
if (POLICY CMP0141)
  cmake_policy(SET CMP0141 NEW)
  set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
endif()

project ("modern-cpp-tui")

message(STATUS "Attempting to locate Vulkan SDK using manual path......")
set(VULKAN_SDK "C:/VulkanSDK")
set(VULKAN_VERSION "1.3.261.0")
set(VULKAN_PATH "${VULKAN_SDK}/${VULKAN_VERSION}")
message(STATUS "Using manual specified path: ${VULKAN_PATH}")

# Check if manual set path exists
if(NOT EXISTS "${VULKAN_PATH}")
	message("Error: Unable to locate this Vulkan SDK path VULKAN_PATH: ${VULKAN_PATH}, please specify correct path.")
endif()

# vulkan-1 library for build Vulkan application.
set(VULKAN_LIB_LIST "vulkan-1")

if(${CMAKE_SYSTEM_NAME} MATCHES "Windows")
	# Include Vulkan header files from Vulkan SDK
	include_directories(AFTER ${VULKAN_PATH}/Include)

	# Link directory for vulkan-1
	link_directories(${VULKAN_PATH}/Bin;${VULKAN_PATH}/Lib;)
endif()

# Add source files to this project's executable.
add_executable(tui_client "src/main.cpp")


# Link the debug and release libraries to the project
target_link_libraries( tui_client ${VULKAN_LIB_LIST} )

# Setting compiler's C++ version
if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET tui_client PROPERTY CXX_STANDARD 23)
endif()

target_include_directories(tui_client
        PRIVATE "${CMAKE_SOURCE_DIR}/include")

add_subdirectory(gtests)