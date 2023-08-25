#include "core/commands/base_command.hpp"

#include <iostream>

#include "utils/string_utility.hpp"


commands::BaseCommand::BaseCommand( const std::string& main_alias )
    : m_main_alias( kCommandPrefix + utility::to_lowercase( main_alias ) )
{
}

void commands::BaseCommand::add_sub_alias( const std::string& alias )
{
    if ( utility::to_lowercase( alias ) == m_main_alias )
        std::cout << alias << " has collision with main alias: " << alias << '\n';

    auto insertion_result = m_sub_aliases.insert( kCommandPrefix + utility::to_lowercase( alias ) );

    if ( !insertion_result.second )
        std::cout << alias << " is a duplicate sub alias\n";
}

const std::string& commands::BaseCommand::get_main_alias( ) const noexcept
{
    return m_main_alias;
}

const std::set< std::string > commands::BaseCommand::get_all_aliases( ) const noexcept
{
    std::set< std::string > all_aliases;

    // Insert the main alias
    all_aliases.insert( m_main_alias );

    // Insert all the sub aliases from m_sub_aliases, no need to check for duplicates as add_sub_alias already does.
    all_aliases.insert( m_sub_aliases.begin( ), m_sub_aliases.end( ) );

    return all_aliases;
}
