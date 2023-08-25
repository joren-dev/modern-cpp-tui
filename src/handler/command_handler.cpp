#include "..\..\include\handler\command_handler.hpp"

CommandHandler::CommandHandler( ) { initialize_commands( ); }

void CommandHandler::initialize_commands( )
{

    std::unique_ptr<BaseCommand>& c_help = m_commands.emplace_back( std::make_unique< HelpCommand >( "Help" ) );
    c_help->add_sub_alias( "h" );

    // Add other commands

    // TODO: CHeck if there are any duplicate aliases.
}

void CommandHandler::invoke_command( const std::string& command )
{

    // Iterate over all commands
    for ( const auto& c_command : m_commands )
    {
        // Gather all aliases
        for ( const std::string& each : c_command->get_all_aliases( ) )
        {
            // If any of them match, execute the command. There should be a duplicate check prior to finishing initialize_commands() so we dont have to break out.
            if ( each == command )
                c_command->execute( );
        }
    }
}
