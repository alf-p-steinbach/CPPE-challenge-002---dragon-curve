#pragma once    // Source encoding: UTF-8 with BOM (π is a lowercase Greek "pi").

#include "cpp_util-Matrix_.hpp"
#include "ppm-Color.hpp"

#include <string>
#include <optional>
#include <utility>

namespace ppm {
    namespace cppu  = cpp_util;

    using   cppu::Matrix_, cppu::in_;
    using   std::string, std::to_string,        // <string>
            std::optional,                      // <optional>
            std::pair;                          // <utility>

    class Canvas
    {
        Matrix_<Color>  m_pixels;
        Color           m_drawing_color;

    public:
        Canvas( const int width, const int height, in_<Color> drawing_color = blue ):
            m_pixels( width, height, white ),
            m_drawing_color( drawing_color )
        {}
        
        auto width() const -> int           { return m_pixels.width(); }
        auto height() const -> int          { return m_pixels.height(); }

        void set_pixel( const int x, const int y, in_<optional<Color>> color = {} )
        {
            m_pixels( x, y ) = color.value_or( m_drawing_color );
        }

        void draw_horizontal_at( const int y, const int x1, const int x2, in_<optional<Color>> color = {} )
        {
            if( x1 > x2 ) {
                draw_horizontal_at( y, x2, x1, color );
            } else {
                for( int x = x1; x <= x2; ++x ) { set_pixel( x, y, color );  }
            }
        }
        
        void draw_vertical_at( const int x, const int y1, const int y2, in_<optional<Color>> color = {} )
        {
            if( y1 > y2 ) {
                draw_vertical_at( x, y2, y1, color );
            } else {
                for( int y = y1; y <= y2; ++y ) { set_pixel( x, y, color ); }
            }
        }

        template< class Func >
        void as_ppm_to( in_<Func> f ) const
        {
            f( "P3\n" );
            f( to_string( width() ) + ' ' + to_string( height() ) + " 255\n" );
            const auto [w, h] = pair( width(), height() );
            for( int y = 0; y < h; ++y ) for( int x = 0; x < w; ++x ) {
                const auto& c = m_pixels( x, y );
                f( to_string( c.red ) + ' ' + to_string( c.green ) + ' ' + to_string( c.blue ) + '\n' );
            }
        }
    };
};  // namespace ppm
