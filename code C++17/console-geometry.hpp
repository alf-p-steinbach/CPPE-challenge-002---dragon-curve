#pragma once    // Source encoding: UTF-8 with BOM (π is a lowercase Greek "pi").

#include "cpp_util-type-builders.hpp"       // in_, ref_

namespace console::geometry {
    namespace cppu = cpp_util;
    using   cppu::in_, cppu::ref_;

    struct Point                { int x; int y; };
    struct Distance             { int dx; int dy; };
    struct Relative_direction   { enum Enum: int { left, right }; };

    constexpr auto operator+( in_<Point> point, in_<Distance> distance )
        -> Point
    { return {point.x + distance.dx, point.y + distance.dy}; }
    
    constexpr void operator+=( ref_<Point> point, in_<Distance> distance )
    {
        point = point + distance;
    }
    
    constexpr auto operator-( in_<Point> a, in_<Point> b )
        -> Distance
    { return {a.x - b.x, a.y - b.y}; }

    constexpr auto rect_size( in_<Point> ul, in_<Point> dr )
        -> Distance
    { return dr + Distance{ 1, 1 } - ul; }

    constexpr void turn_right( ref_<Distance> d ) { d = Distance{ -d.dy, d.dx }; }
    constexpr void turn_left( ref_<Distance> d )  { d = Distance{ d.dy, -d.dx }; }
    
    constexpr void turn( const Relative_direction::Enum dir, ref_<Distance> dist )
    {
        switch( dir ) {
            case Relative_direction::right:     turn_right( dist );  break;
            case Relative_direction::left:      turn_left( dist );  break;
        }
    }
}  // namespace console::geometry
