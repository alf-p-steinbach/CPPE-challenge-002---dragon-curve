#include "line_drawing_characters.hpp"

#include <iostream>
#include <string_view>
using   std::cout, std::endl,
        std::string_view;

auto main() -> int
{
    namespace ldc = line_drawing_characters;
    for( int i = 0; i < ldc::n_line_characters; ++i ) {
        const auto ch = ldc::line_characters[i];
        cout << (ch.empty()? "0" : ch) << " ";
    }
    cout << endl;
    
    cout << endl;
    int n_missing = 0;
    for( const string_view& ch: ldc::line_characters ) {
        if( ch.empty() ) {
            ++n_missing;
            const auto i = static_cast<int>( &ch -  &ldc::line_characters[0] );
            const auto lines = ldc::Lines_in_char_box::from_index( i );
            cout << "missing (r, u, l, d) = (";
            for( int direction = 0; direction < ldc::Line_direction::count; ++direction ) {
                cout << (direction > 0? ", " : "") << lines.line_width[direction];
            }
            cout << ") - at index " << i << "." << endl;
        }
    }
    
    if( not n_missing ) {
        cout << "All line characters defined." << endl;
    }
}
