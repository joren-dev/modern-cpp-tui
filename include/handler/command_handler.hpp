#ifndef COMMAND_HANDLER_HPP
#define COMMAND_HANDLER_HPP

#include <memory>
#include <string>

#include "base_handler.hpp"

#include "../core/commands/base_command.hpp"
#include "../core/commands/help_command.hpp"

namespace handler
{

    // Processes the commands that are invoked, handles accordinglys
    class CommandHandler : public BaseHandler
    {
      public:
        CommandHandler( );

        void initialize_handler( [[maybe_unused]] GLFWwindow* const window = nullptr ) override;

        void invoke_command( const std::string& command );

        std::vector< std::unique_ptr< commands::BaseCommand > > m_commands;
    };

} // namespace handler

#endif /* !COMMAND_HANDLER_HPP */
