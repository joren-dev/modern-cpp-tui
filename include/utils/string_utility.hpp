#ifndef STRING_UTILITY_HPP
#define STRING_UTILITY_HPP

#include <algorithm>
#include <string>

namespace utility
{
    // Convert a string to lowercase
    inline std::string to_lowercase( const std::string& str )
    {
        std::string result = str;
        std::transform( result.begin( ), result.end( ), result.begin( ), ::tolower );
        return result;
    }
} // namespace utility

#endif /* !STRING_UTILITY_HPP */
