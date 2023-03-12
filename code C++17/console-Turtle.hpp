#pragma once    // Source encoding: UTF-8 with BOM (π is a lowercase Greek "pi").
// Was used in the original draw_dragon_curve function.
// Removed for the challenge presentation, to make that presentation simple.

#include "console-geometry.hpp"

namespace console {
    class Turtle
    {
        geometry::Point     m_pos;
        geometry::Distance  m_step;
        
    public:
        Turtle( in_<geometry::Point> pos = {} ): m_pos( pos ), m_step{ 0, -1 } {}

        auto position() const -> geometry::Point { return m_pos; }

        void forward() { m_pos += m_step; }
        void forward( const int n_steps ) { for( int i = 1; i <= n_steps; ++i ) { forward(); } }

        void turn_right()   { geometry::turn_right( m_step ); }
        void turn_left()    { geometry::turn_left( m_step ); }
        void turn( const geometry::Relative_direction::Enum dir ) { geometry::turn( dir, m_step ); }
    };
}  // namespace console
