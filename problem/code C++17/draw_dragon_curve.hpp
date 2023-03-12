#pragma once    // Source encoding: UTF-8 with BOM (π is a lowercase Greek "pi").
#include <functional>
#include <string>
#include <tuple>
#include <utility>

namespace draw {
    using   std::function,              // <functional>
            std::string,                // <string>
            std::tie,                   // <tuple>
            std::move, std::pair;       // <utility>

    template< class T > using in_ = const T&;
    
    // <url: https://en.wikipedia.org/wiki/Dragon_curve>
    void dragon_curve( const int level, in_<function<void( int x, int y )>> put_point )
    {
        string spec = "F";
        for( int i = 1; i <= level; ++i ) {
            string new_spec;  new_spec.reserve( 3*spec.size() );
            for( const char ch: spec ) {
                switch( ch ) {
                    case 'F':   new_spec += "F+G";  break;
                    case 'G':   new_spec += "F-G";  break;
                    default:    new_spec += ch;  break;
                }
            }
            spec = move( new_spec );
        }
        
        struct{ int x; int y; }     position    = {0, 0};
        struct{ int dx; int dy; }   step        = {0, -1};  // "Up" in usual screen coordinate system.

        const auto forward = [&]() -> void
        {
            position.x += step.dx;  position.y += step.dy;
            put_point( position.x, position.y );
        };

        put_point( position.x, position.y );
        for( const char ch: spec ) {
            switch( ch ) {
                case 'F':
                case 'G':   forward();  break;
                case '+':   tie( step.dx, step.dy ) = pair( step.dy, -step.dx );  break;
                case '-':   tie( step.dx, step.dy ) = pair( -step.dy, step.dx );  break;
            }
        }
    }
}  // namespace draw
