#include "core/commands/base_command.hpp"

#include "utils/string_utility.hpp"


commands::BaseCommand::BaseCommand( const std::string& main_alias )
    : m_main_alias( kCommandPrefix + utility::to_lowercase( main_alias ) )
{
}

void commands::BaseCommand::add_sub_alias( const std::string& alias )
{
    m_sub_aliases.emplace_back( kCommandPrefix + utility::to_lowercase( alias ) );
}

const std::string& commands::BaseCommand::get_main_alias( ) const noexcept
{
    return m_main_alias;
}

const std::vector< std::string > commands::BaseCommand::get_all_aliases( ) const noexcept
{
    // TODO: This creates a new vector each time, should just be a member. Fix this.
    std::vector< std::string > all_aliases;
    all_aliases.push_back( m_main_alias );
    all_aliases.insert( all_aliases.end( ), m_sub_aliases.begin( ), m_sub_aliases.end( ) );

    return all_aliases;
}
