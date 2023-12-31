#ifndef COMMAND_HANDLER_HPP
#define COMMAND_HANDLER_HPP

#include <memory>
#include <string>
#include <type_traits>
#include <utility>
#include <vector>

#include "base_handler.hpp"

#include "core/commands/base_command.hpp"
#include "core/commands/help_command.hpp"

namespace handler
{

    // Processes the commands that are invoked, handles accordinglys
    class CommandHandler : public BaseHandler
    {
      public:
        CommandHandler( );

        template< typename T, typename... Args >
        inline auto& add_command( Args&&... args ) requires( std::is_base_of_v< commands::BaseCommand, T > )
        {
            return m_commands.emplace_back( std::make_unique< T >( std::forward< Args >( args )... ) );
        }

        void initialize_handler( [[maybe_unused]] GLFWwindow* const window = nullptr ) override;
        void check_aliases( const std::vector< std::set< std::string > >& all_aliases );
        void invoke_command( const std::string& command );

        std::vector< std::unique_ptr< commands::BaseCommand > > m_commands;
    };

} // namespace handler

#endif /* !COMMAND_HANDLER_HPP */
