#ifndef COMMAND_HANDLER_HPP
#define COMMAND_HANDLER_HPP

#include <string>
#include <memory>

#include "../core/commands/base_command.hpp"
#include "../core/commands/help_command.hpp"

// Processes the commands that are invoked, handles accordinglys
class CommandHandler
{
  public:
    CommandHandler( );

    void initialize_commands( );

    void invoke_command( const std::string& command );

    std::vector< std::unique_ptr< BaseCommand > > m_commands;
};

#endif /* !COMMAND_HANDLER_HPP */
