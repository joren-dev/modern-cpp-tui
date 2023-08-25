#ifndef CONTAINER_UTILITY_HPP
#define CONTAINER_UTILITY_HPP

#include <algorithm>
#include <string>
#include <vector>

namespace utility
{
    inline std::vector< std::string > flatten( const std::vector< std::vector< std::string > >& input )
    {
        std::vector< std::string > flattened;
        for ( const auto& sub_vector : input )
            flattened.insert( flattened.end( ), sub_vector.begin( ), sub_vector.end( ) );

        return flattened;
    }
} // namespace utility

#endif /* !CONTAINER_UTILITY_HPP */
