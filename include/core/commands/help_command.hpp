#ifndef HELP_COMMAND_HPP
#define HELP_COMMAND_HPP

#include <iostream>

#include "base_command.hpp"

namespace commands
{
    // Implements help command
    class HelpCommand : public BaseCommand
    {
      public:
        // Delete default ctor, to ensure base class ctor is used.
        HelpCommand( ) = delete;

        HelpCommand( const std::string& main_alias );

        void execute( ) override;
    };
} // namespace commands

#endif /* !HELP_COMMAND_HPP */
