#ifndef BASE_HANDLER_HPP
#define BASE_HANDLER_HPP

#include <algorithm>
#include <string>

#include <GLFW/glfw3.h>

namespace handler
{
    class BaseHandler
    {
      public:
        BaseHandler( ) = default;

        BaseHandler( const BaseHandler& ) = default;
        BaseHandler& operator=( const BaseHandler& ) = default;

        BaseHandler( BaseHandler&& other ) noexcept = default;
        BaseHandler& operator=( BaseHandler&& other ) noexcept = default;

        virtual void initialize_handler( [[maybe_unused]] GLFWwindow* const window ) = 0;

        virtual ~BaseHandler( ) = default;
    };
} // namespace handler

#endif /* !BASE_HANDLER_HPP */
