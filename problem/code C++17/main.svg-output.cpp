#include "draw_dragon_curve.hpp"    // draw::dragon_curve
#include <fmt/core.h>               // Define `FMT_HEADER_ONLY` for use as a header only library.

#include <string>
#include <string_view>
#include <limits.h>

namespace app {
    using   std::string, std::to_string, std::string_view;

    constexpr char svg_template_literal[] =
R"(
<?xml version="1.0" encoding="UTF-8" standalone="yes"?>
<!DOCTYPE svg PUBLIC "-//W3C//DTD SVG 1.1//EN" "http://www.w3.org/Graphics/SVG/1.1/DTD/svg11.dtd">
<svg width="{width}" height="{height}" viewBox="{min_x} {min_y} {width} {height}" 
        xmlns="http://www.w3.org/2000/svg" xmlns:xlink="http://www.w3.org/1999/xlink">
	<polyline points="{polypoints}" stroke="blue" stroke-width="1" fill="none" />
</svg>
)";
    constexpr auto svg_template = string_view( svg_template_literal + 1 );

    struct Data
    {
        string polyline_points;
        int min_x = INT_MAX, min_y = INT_MAX, max_x = INT_MIN, max_y = INT_MIN;
        
        Data( const int recursion_depth )
        {
            draw::dragon_curve( recursion_depth, [&]( int x, int y )
            {
                x *= 3; y *= 3;     // Scaling up to get some space between the lines.
                auto& s = polyline_points;
                if( not s.empty() ) { s += ' '; }
                s += fmt::format( "{},{}", x, y );

                if( x < min_x ) { min_x = x; }  if( y < min_y ) { min_y = y; }
                if( x > max_x ) { max_x = x; }  if( y > max_y ) { max_y = y; }
            } );
        }
    };

    void run()
    {
        constexpr int recursion_depth = 14;
        const auto  data    = Data( recursion_depth );
        const int   margin  = 8;
        const int   width   = 2*margin + (1 + data.max_x - data.min_x);
        const int   height  = 2*margin + (1 + data.max_y - data.min_y);
        
        using fmt::vformat, fmt::make_format_args, fmt::arg;
        fmt::vprint( svg_template, make_format_args(
            arg( "width", width ), arg( "height", height ),
            arg( "min_x", data.min_x - margin ), arg( "min_y", data.min_y - margin ),
            arg( "polypoints", data.polyline_points )
            ) );
    }
}  // namespace app

auto main() -> int { app::run(); }
