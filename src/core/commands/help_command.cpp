#include "..\..\..\include\core\commands\help_command.hpp"

commands::HelpCommand::HelpCommand( const std::string& main_alias ) : BaseCommand( main_alias ) {}

void commands::HelpCommand::execute( )
{
    std::cout << "Executed help command...\n";
}
