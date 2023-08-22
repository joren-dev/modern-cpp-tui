#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>

// Testing purposes
#include <vulkan/vulkan.hpp>
#include "test.hpp"

#include <iostream>

int main( )
{
    std::cout << test( );

    glfwInit( );

    glfwWindowHint( GLFW_CLIENT_API, GLFW_NO_API );
    GLFWwindow* window = glfwCreateWindow( 800, 600, "Vulkan window", nullptr, nullptr );

    uint32_t extensionCount = 0;
    vkEnumerateInstanceExtensionProperties( nullptr, &extensionCount, nullptr );

    std::cout << extensionCount << " extensions supported\n";

    while ( !glfwWindowShouldClose( window ) )
    {
        glfwPollEvents( );
    }

    glfwDestroyWindow( window );

    glfwTerminate( );

    return 0;
}