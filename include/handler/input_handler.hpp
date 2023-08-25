#ifndef INPUT_HANDLER_HPP
#define INPUT_HANDLER_HPP

#include <array>
#include <functional>
#include <string>
#include <unordered_map>
#include <vector>

#include <GLFW/glfw3.h>

#include "command_handler.hpp"

class InputHandler
{
  public:
    InputHandler( )
        : m_window( nullptr ), m_key_states { { GLFW_KEY_ENTER, GLFW_RELEASE }, { GLFW_KEY_BACKSPACE, GLFW_RELEASE } }
    {
    }

    static InputHandler& get_instance( )
    {
        static InputHandler instance;
        return instance;
    }

    void initialize_handler( GLFWwindow* const window );

    static void keystroke_callable( GLFWwindow* window, unsigned int key );
    void poll_instructions( );
    void process_input( const std::string& input_text );

  private:
    CommandHandler m_command_handler;

    GLFWwindow* m_window;

    static std::string m_user_input;
    std::unordered_map< int, int > m_key_states;

    // Helper function to extract commands starting with '$' from input
    std::vector< std::string > extract_commands( const std::string& input_text );
};

#endif /* !INPUT_HANDLER_HPP */
