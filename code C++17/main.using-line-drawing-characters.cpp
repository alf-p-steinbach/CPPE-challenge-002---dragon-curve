#include "console-Line_canvas.hpp"
#include "console-geometry.hpp"

#include "cpp_util.hpp"
#include "draw_dragon_curve.hpp"

#include <iostream>

#include <assert.h>     // assert
#include <stdlib.h>     // atoi

namespace app {
    namespace cppu = cpp_util;
    namespace geometry = console::geometry;

    using   cppu::in_, cppu::const_, cppu::Span_;
    using   console::Line_canvas;
    using   std::function,              // <functional>
            std::cout, std::endl,       // <iostream>
            std::pair;                  // <utility>

    template< class Drawing_func >
    auto bounding_box_of( in_<Drawing_func> draw )
        -> pair<geometry::Point, geometry::Point>
    {
        namespace m = geometry;
        m::Point    box_ul = {};
        m::Point    box_dr = {};
        draw( [&]( in_<m::Point> pt )
        {
            if( pt.x < box_ul.x ) { box_ul.x = pt.x; }
            if( pt.y < box_ul.y ) { box_ul.y = pt.y; }
            if( pt.x > box_dr.x ) { box_dr.x = pt.x; }
            if( pt.y > box_dr.y ) { box_dr.y = pt.y; }
        } );
        return {box_ul, box_dr};
    }

    template< class Drawing_func >
    auto line_drawing_from( in_<Drawing_func> drawfunc )
        -> Line_canvas
    {
        namespace m = geometry;
        const auto scaled_drawing = [&drawfunc]( auto callback )
        {
            drawfunc( [&callback]( in_<m::Point> pt ) { callback( m::Point{3*pt.x, pt.y} ); } );
        };

        const auto [bbox_ul, bbox_dr]   = bounding_box_of( scaled_drawing );
        const m::Distance offset        = m::Point() - bbox_ul;
        const m::Distance bbox_size     = bbox_dr - bbox_ul;

        auto        canvas             = Line_canvas( bbox_size.dx, bbox_size.dy );
        m::Point    previous_canvas_pt;
        bool        has_previous_point      = false;
        scaled_drawing( [&]( in_<m::Point> pt )
        {
            const m::Point canvas_pt = pt + offset;
            if( has_previous_point ) {
                if( canvas_pt.y == previous_canvas_pt.y ) {
                    canvas.draw_horizontal_at( canvas_pt.y, previous_canvas_pt.x, canvas_pt.x );
                } else if( canvas_pt.x == previous_canvas_pt.x ) {
                    canvas.draw_vertical_at( canvas_pt.x, previous_canvas_pt.y, canvas_pt.y );
                } else {
                    assert( !"Each line segment in a drawing must be horizontal or vertical." );
                }
            }
            previous_canvas_pt = canvas_pt;
            has_previous_point = true;
        } );
        
        return canvas;
    }

    void draw_dragon_curve( const int level, in_<function<void( geometry::Point )>> put_point )
    {
        ::draw::dragon_curve( level, [&put_point]( int x, int y )
        {
            put_point( geometry::Point{ x, y } );
        } );
    }

    void run( in_<Span_<const_<const char*>>> args )
    {
        auto& out = cout;

        const int args0_value = (args.size() == 0? 0 : atoi( *args.p_first ));
        const int level = (args0_value > 0? args0_value : 9);

        Line_canvas canvas = line_drawing_from( [level]( auto f ){ draw_dragon_curve( level, f ); } );
        out << "Dragon curve level " << level << ","
            << " drawing size " << canvas.width() << "×" << canvas.height() << "." << endl;
        for( int i = 0; i < canvas.n_text_lines(); ++i ) {
            cout << canvas.text_line_at( i ) << endl;
        }
    }
}  // namespace app

auto main( int n, char** a ) -> int
{
    using cpp_util::const_;
    const_<const_<const char*>*> ac = a;
    app::run( { ac + 1, ac + n } );
}
