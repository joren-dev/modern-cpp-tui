#ifndef INPUT_HANDLER_HPP
#define INPUT_HANDLER_HPP

#include <array>
#include <functional>
#include <string>
#include <unordered_map>
#include <vector>

#include <GLFW/glfw3.h>

#include "base_handler.hpp"
#include "command_handler.hpp"

namespace handler
{

    class InputHandler : public BaseHandler
    {
      private:
        InputHandler( );

      public:
        [[nodiscard]] static InputHandler& get( ) noexcept 
        {
            static handler::InputHandler instance;
            return instance;
        }

        static void keystroke_callable( GLFWwindow* window, unsigned int key );

        void poll_instructions( );
        void process_input( const std::string& input_text );
        void initialize_handler( [[maybe_unused]] GLFWwindow* const window ) override;

      private:
        CommandHandler m_command_handler;

        GLFWwindow* m_window;

        static std::string m_user_input;
        std::unordered_map< int, int > m_key_states;

        // Helper function to extract commands starting with '$' from input
        std::vector< std::string > extract_commands( const std::string& input_text );
    };

} // namespace handler

#endif /* !INPUT_HANDLER_HPP */
