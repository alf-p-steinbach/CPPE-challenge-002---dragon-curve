#pragma once    // Source encoding: UTF-8 with BOM (π is a lowercase Greek "pi").

#include <tuple>
#include <utility>

namespace console::geometry {
    using   std::tie,           // <tuple>
            std::pair;          // <utility>

    struct Point                { int x; int y; };
    struct Distance             { int dx; int dy; };
    struct Relative_direction   { enum Enum: int { left, right }; };

    inline auto operator+( in_<Point> point, in_<Distance> distance )
        -> Point
    { return {point.x + distance.dx, point.y + distance.dy}; }
    
    inline void operator+=( ref_<Point> point, in_<Distance> distance )
    {
        point = point + distance;
    }
    
    inline auto operator-( in_<Point> a, in_<Point> b )
        -> Distance
    { return {a.x - b.x, a.y - b.y}; }

    inline void turn_right( ref_<Distance> d ) { tie( d.dx, d.dy ) = pair( -d.dy, d.dx ); }
    inline void turn_left( ref_<Distance> d )  { tie( d.dx, d.dy ) = pair( d.dy, -d.dx ); }
    
    inline void turn( const Relative_direction::Enum dir, ref_<Distance> dist )
    {
        switch( dir ) {
            case Relative_direction::right:     turn_right( dist );  break;
            case Relative_direction::left:      turn_left( dist );  break;
        }
    }
}  // namespace console::geometry
