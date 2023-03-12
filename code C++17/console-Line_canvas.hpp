#pragma once    // Source encoding: UTF-8 with BOM (π is a lowercase Greek "pi").

#include "line_drawing_characters.hpp"

#include <string>

namespace console {
    namespace ldc   = line_drawing_characters;
    namespace cppu  = cpp_util;

    using   cppu::Matrix_, cppu::ref_, cppu::in_, cppu::is_empty;
    using   std::string;

    class Line_canvas
    {
        Matrix_<ldc::Lines_in_char_box>  m_box_lines;

    public:
        Line_canvas( const int width, const int height ):
            m_box_lines( width + 1, height + 1 )
        {}
        
        auto width() const -> int           { return m_box_lines.width() - 1; }
        auto height() const -> int          { return m_box_lines.height() - 1; }
        auto n_text_lines() const -> int    { return height() + 1; }

        void draw_horizontal_at(
            const int y, const int x1, const int x2,
            const int line_width = ldc::Line_width::thin
            )
        {
            if( x1 > x2 ) {
                draw_horizontal_at( y, x2, x1, line_width );
            } else {
                for( int x = x1; x < x2; ++x ) {
                    using D = ldc::Line_direction;
                    m_box_lines( x, y ).line_width[D::right] = line_width;
                    m_box_lines( x + 1, y ).line_width[D::left] = line_width;
                }
            }
        }
        
        void draw_vertical_at(
            const int x, const int y1, const int y2,
            const int line_width = ldc::Line_width::thin
            )
        {
            if( y1 > y2 ) {
                draw_vertical_at( x, y2, y1, line_width );
            } else {
                for( int y = y1; y < y2; ++y ) {
                    using D = ldc::Line_direction;
                    m_box_lines( x, y ).line_width[D::down] = line_width;
                    m_box_lines( x, y + 1 ).line_width[D::up] = line_width;
                }
            }
        }

        auto text_line_at( const int y ) const
            -> string
        {
            string result;
            for( int x = 0; x <= width(); ++x ) {
                result += m_box_lines( x, y ).sv();
            }
            return result;
        }
    };
}  // namespace console
