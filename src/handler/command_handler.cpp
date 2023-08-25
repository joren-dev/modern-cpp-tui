#include "..\..\include\handler\command_handler.hpp"

handler::CommandHandler::CommandHandler( )
{
    initialize_handler( );
}

void handler::CommandHandler::initialize_handler( [[maybe_unused]] GLFWwindow* const window )
{

    std::unique_ptr< commands::BaseCommand >& c_help = m_commands.emplace_back( std::make_unique< commands::HelpCommand >( "Help" ) );
    c_help->add_sub_alias( "h" );

    // Add other commands

    // TODO: CHeck if there are any duplicate aliases.
}

void handler::CommandHandler::invoke_command( const std::string& command )
{
    for ( const auto& each_command : m_commands )
    {
        for ( const std::string& each : each_command->get_all_aliases( ) )
        {
            // Duplicate check is done in initialize_handler(), so no checks needed
            if ( each == command )
                each_command->execute( );
        }
    }
}
