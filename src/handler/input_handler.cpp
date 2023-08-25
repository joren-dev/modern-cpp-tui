#include "handler/input_handler.hpp"

#include <cstddef>
#include <iostream>

#include "utils/string_utility.hpp"

void handler::InputHandler::initialize_handler( GLFWwindow* const window )
{
    m_window = window;
    glfwSetCharCallback( window, keystroke_callable );
}

void handler::InputHandler::keystroke_callable( GLFWwindow* window, unsigned int key )
{
    // Convert the key to a character and add it to user_input
    char input_char = static_cast< char >( key );
    m_user_input += input_char;
}

void handler::InputHandler::poll_instructions( )
{
    for ( auto& [ key, previous_state ] : m_key_states )
    {
        const int current_state = glfwGetKey( m_window, key );

        if ( current_state == GLFW_PRESS && previous_state == GLFW_RELEASE )
        {
            if ( key == GLFW_KEY_ENTER )
            {
                // Call a function to process the user input
                std::cout << "sent: " << m_user_input << " to process_input\n";
                InputHandler::get_instance( ).process_input( m_user_input );

                // Clear the input buffer
                m_user_input.clear( );
            }

            if ( key == GLFW_KEY_BACKSPACE && !m_user_input.empty( ) )
            {
                // Remove the last character from user_input (if it's not empty)
                m_user_input.pop_back( );
            }
        }

        // Update the key state
        previous_state = current_state;
    }
}

void handler::InputHandler::process_input( const std::string& input_text )
{
    // Check if buffer is empty, while this being called. This happens when enter is pressed for a longer period of time.
    if ( input_text.empty( ) )
        return;

    if ( input_text.at( 0 ) != '$' )
    {
        std::cout << "A command starts with $, you typed: " << input_text << '\n';
        return;
    }

    // Extract commands starting with '$' from the input text
    std::vector< std::string > commands = extract_commands( input_text );

    // Call the command handler for each recognized command
    for ( const std::string& command : commands )
        m_command_handler.invoke_command( command );
}

std::vector< std::string > handler::InputHandler::extract_commands( const std::string& input_text )
{
    std::vector< std::string > commands;
    std::size_t pos { };

    while ( ( pos = input_text.find( '$', pos ) ) != std::string::npos )
    {
        std::size_t start = pos;
        std::size_t end =
            input_text.find_first_not_of( "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789_", start + 1 );

        if ( end == std::string::npos )
            end = input_text.length( );

        commands.push_back( utility::to_lowercase( input_text.substr( start, end - start ) ) );
        pos = end;
    }

    return commands;
}

// TODO: this is ugly, pls fix. Define and initialize the static member variable
std::string handler::InputHandler::m_user_input = "";
