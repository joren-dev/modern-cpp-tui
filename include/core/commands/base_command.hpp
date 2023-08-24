#ifndef BASE_COMMAND_HPP
#define BASE_COMMAND_HPP


// Defines a base for our commands. A command object will only represent what a command does, we dont care if
// its being copied or moved.
class BaseCommand
{
  public:
    BaseCommand( ) = default;

    BaseCommand( const BaseCommand& ) = default;
    BaseCommand& operator=( const BaseCommand& ) = default;

    BaseCommand( BaseCommand&& other ) noexcept = default;
    BaseCommand& operator=( BaseCommand&& other ) noexcept = default;

    virtual void execute( ) = 0;

    virtual ~BaseCommand( ) = default;
};

#endif /* !BASE_COMMAND_HPP */
