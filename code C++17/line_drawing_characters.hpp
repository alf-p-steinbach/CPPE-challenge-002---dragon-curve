#pragma once    // Source encoding: UTF-8 with BOM (π is a lowercase Greek "pi").
#include "cpp_util.hpp"

#include <array>
#include <string_view>

namespace line_drawing_characters {
    namespace cppu = cpp_util;
    using cppu::intpow, cppu::enum_count_of_;
    using std::array, std::string_view;

    CPPU_DEFINE_WRAPPED_ENUM( Line_width,       (none, thin, thick) );      // 0, 1, 2
    CPPU_DEFINE_WRAPPED_ENUM( Line_direction,   (down, right, up, left) );

    struct Lines_in_char_box
    {
        int line_width[enum_count_of_<Line_direction>]; // As if an array of `Line_width_enum`.
        
        constexpr auto index() const
            -> int
        {
            int result = 0;
            for( int i = enum_count_of_<Line_direction> - 1; i >= 0; --i ) {
                result = enum_count_of_<Line_width>*result + line_width[i];
            }
            return result;
        }
        
        static constexpr auto from_index( const int index )
            -> Lines_in_char_box
        {
            Lines_in_char_box    result{};
            int remaining = index;
            for( int i = 0; i < enum_count_of_<Line_direction>; ++i ) {
                result.line_width[i] = remaining % enum_count_of_<Line_width>;
                remaining /= enum_count_of_<Line_width>;
            }
            return result;
        }
        
        constexpr auto sv() const -> string_view;   // Defined at the end of this header.
    };

    constexpr int n_line_characters  =
        intpow( enum_count_of_<Line_width>, enum_count_of_<Line_direction> );       // 81
    using Line_characters_array     = array<string_view, n_line_characters>;

    constexpr auto produce_line_characters()
        -> Line_characters_array
    {
        Line_characters_array result;
        #define DEFINE( down_width, right_width, up_width, left_width, code ) \
            result[Lines_in_char_box{ down_width, right_width, up_width, left_width }.index()] = code

        #   include "line_drawing_characters.inc"

        #undef DEFINE
        return result;
    }
    
    constexpr Line_characters_array line_characters = produce_line_characters();

    constexpr auto Lines_in_char_box::sv() const
        -> string_view
    { return line_characters[index()]; }

    constexpr auto ch_for_widths(
        const int r_width, const int u_width, const int l_width, const int d_width
        ) -> string_view
    { return Lines_in_char_box{ r_width, u_width, l_width, d_width }.sv(); }
}  // namespace line_drawing_characters
