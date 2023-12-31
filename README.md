# Modern cpp TUI
A Text based User Interface that will contain a collection of tools and utility used by the creators. It will be written in modern C++ and be cross-platform.

## Prerequisites (to be adjusted)
1. Install [Visual studio 2022](https://visualstudio.microsoft.com/vs/). During installation/in VS installer make sure to select:
	- Install C++, 
    - CMake support,
    - Clang Compiler

2. Install [Vulkan SDK](https://vulkan.lunarg.com/). Set the `VULKAN_SDK` environment variable to the Vulkan SDK installation directory.

3. Git clone this project using: `git clone --recurse-submodules -j8 https://github.com/joren-dev/modern-cpp-tui.git`

4. Run the `bootstrap-vcpkg.xxx`

5. Install dependencies using: `./vcpkg/vcpkg.exe install`


## Technical details
Here below I'll list some technical details that should be known before using this project.

### Where can I test the application without compiling?
Please refer to the [Release Page](https://github.com/joren-dev/modern-cpp-tui/releases).

### G-tests
It utilises google tests, they can be found in `src/gtests`. It is currently not integrated with anything, just works standalone when loading in the project in an IDE.
You're able to run the google tests by selecting gtest.exe as executable that you wish to build in the IDE of your choice.
