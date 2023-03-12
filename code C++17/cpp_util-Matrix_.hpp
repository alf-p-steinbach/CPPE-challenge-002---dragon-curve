#pragma once    // Source encoding: UTF-8 with BOM (π is a lowercase Greek "pi").

#include "cpp_util-type-builders.hpp"       // ref_

#include <vector>

namespace cpp_util {
    using   std::vector;            // <vector>
    
    template< class Item >
    class Matrix_
    {
        vector<Item>        m_items;
        int                 m_width;
        int                 m_height;
        
        auto index_of( const int x, const int y ) const
            -> int
        { return y*m_width + x; }

    public:
        Matrix_( const int width, const int height, in_<Item> default_value = {} ):
            m_items( width*height, default_value ),
            m_width( width ),
            m_height( height )
        {}
        
        auto width() const -> int   { return m_width; }
        auto height() const -> int  { return m_height; }

        auto operator()( const int x, const int y )
            -> ref_<Item>
        { return m_items[index_of( x, y )]; }
        
        auto operator()( const int x, const int y ) const
            -> ref_<const Item>
        { return m_items[index_of( x, y )]; }
    };
}  // namespace cpp_util
