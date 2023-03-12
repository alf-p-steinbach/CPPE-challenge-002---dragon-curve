#pragma once    // Source encoding: UTF-8 with BOM (π is a lowercase Greek "pi").
#include <iterator>         // std::size

#include "cpp_util-type-builders.hpp"       // in_

namespace cpp_util {
    template< class Container >
    inline auto is_empty( in_<Container> c ) -> bool { return c.empty(); }
    
    template< class Container >
    inline auto int_size_of( in_<Container> c ) -> int { return static_cast<int>( std::size( c ) ); }
    
    template< class Item >
    struct Span_
    {
        Item*   p_first;
        Item*   p_beyond;
        
        auto size() const -> int { return static_cast<int>( p_beyond - p_first ); }
    };
}  // namespace cpp_util
