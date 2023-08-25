#ifndef HELP_COMMAND_HPP
#define HELP_COMMAND_HPP

#include <iostream>

#include "base_command.hpp"

// Implements help command
class HelpCommand : public BaseCommand
{
  public:
    // Delete default ctor, to ensure base class ctor is used.
    HelpCommand( ) = delete;

    HelpCommand( const std::string& main_alias ) : BaseCommand( main_alias ) {}

    void execute( ) override { std::cout << "Executed help command...\n"; }
};

#endif /* !HELP_COMMAND_HPP */
