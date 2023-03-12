#pragma once    // Source encoding: UTF-8 with BOM (π is a lowercase Greek "pi").

#include "cpp_util-macro-EXPAND.hpp"    // CPPU_EXPAND
#include "cpp_util-class-kinds.hpp"     // Static_class

#define CPPU_DEFINE_WRAPPED_ENUM( name, value_list ) \
    struct name: ::cpp_util::Static_class { enum Enum{ CPPU_EXPAND value_list, _ }; }

// Example usage:
// CPPU_DEFINE_WRAPPED_ENUM( Line_direction, (down, right, up, left) );

namespace cpp_util {

    template< class Enum >              // TODO: enable if
    constexpr int count_of_ = static_cast<int>( Enum::_ );

    template< class Enum_wrapper >      // TODO: enable if
    constexpr int enum_count_of_ = Enum_wrapper::_;

}  // namespace cpp_util
