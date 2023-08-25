#ifndef BASE_COMMAND_HPP
#define BASE_COMMAND_HPP

#include <algorithm>
#include <string>
#include <set>

namespace commands
{
    class BaseCommand
    {
      public:
        BaseCommand( const std::string& main_alias );

        BaseCommand( const BaseCommand& ) = default;
        BaseCommand& operator=( const BaseCommand& ) = default;

        BaseCommand( BaseCommand&& other ) noexcept = default;
        BaseCommand& operator=( BaseCommand&& other ) noexcept = default;

        virtual void execute( ) = 0;

        virtual ~BaseCommand( ) = default;

        void add_sub_alias( const std::string& alias );

        const std::string& get_main_alias( ) const noexcept;
        const std::set< std::string > get_all_aliases( ) const noexcept;

      private:
        const char kCommandPrefix { '$' };

        const std::string m_main_alias;
        std::set< std::string > m_sub_aliases;
    };
} // namespace commands

#endif /* !BASE_COMMAND_HPP */
