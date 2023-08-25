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

        BaseHandler( const BaseHandler& ) = delete;
        BaseHandler& operator=( const BaseHandler& ) = delete;

        BaseHandler( BaseHandler&& other ) noexcept = delete;
        BaseHandler& operator=( BaseHandler&& other ) noexcept = delete;

        virtual void initialize_handler( [[maybe_unused]] GLFWwindow* const window ) = 0;

        virtual ~BaseHandler( ) = default;
    };
} // namespace handler

#endif /* !BASE_HANDLER_HPP */
