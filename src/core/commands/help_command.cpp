#include "..\..\..\include\core\commands\help_command.hpp"

inline commands::HelpCommand::HelpCommand( const std::string& main_alias ) : BaseCommand( main_alias ) {}

inline void commands::HelpCommand::execute( )
{
    std::cout << "Executed help command...\n";
}
