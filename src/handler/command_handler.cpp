#include "handler/command_handler.hpp"

#include <algorithm>
#include <ranges>
#include <set>
#include <string>
#include <unordered_set>
#include <vector>

#include "utils/container_utility.hpp"

handler::CommandHandler::CommandHandler( )
{
    initialize_handler( );
}

void handler::CommandHandler::initialize_handler( [[maybe_unused]] GLFWwindow* const window )
{
    std::vector< std::set< std::string > > all_aliases;

    { // Help Command:
        auto& c_help = add_command< commands::HelpCommand >( "help" );
        c_help->add_sub_alias( "h" );

        all_aliases.emplace_back( c_help->get_all_aliases( ) );
    }

    { // Yelp Command (testing purposes):
        auto& c_help2 = add_command< commands::HelpCommand >( "yelp" );
        c_help2->add_sub_alias( "y" );

        all_aliases.emplace_back( c_help2->get_all_aliases( ) );
    }

    check_aliases( all_aliases );
}

void handler::CommandHandler::check_aliases( const std::vector< std::set< std::string > >& all_aliases )
{
    // Use a set to check for duplicate aliases across all sets
    std::unordered_set< std::string > unique_aliases;

    for ( const auto& aliases_set : all_aliases )
    {
        std::ranges::for_each( aliases_set, [ &unique_aliases ]( const std::string& alias ) {
            if ( !unique_aliases.insert( alias ).second )
            {
                std::cout << "Duplicate alias found: " << alias << '\n';
            }
        } );
    }
}

void handler::CommandHandler::invoke_command( const std::string& command )
{
    for ( const auto& each_command : m_commands )
    {
        const std::set< std::string >& aliases = each_command->get_all_aliases( );

        if ( std::any_of( aliases.begin( ), aliases.end( ),
                          [ &command ]( const std::string& alias ) { return alias == command; } ) )
        {
            each_command->execute( );
        }
    }
}
