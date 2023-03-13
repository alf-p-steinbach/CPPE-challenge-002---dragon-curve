#pragma once    // Source encoding: UTF-8 with BOM (π is a lowercase Greek "pi").

#include "cpp_util-basic-types.hpp"

namespace ppm {
    using   cpp_util::Byte;

    struct Color{ Byte red; Byte green; Byte blue; };

    static constexpr auto black = Color{ 0x00, 0x00, 0x00 };
    static constexpr auto blue  = Color{ 0x00, 0x00, 0xC0 };
    static constexpr auto white = Color{ 0xFF, 0xFF, 0xFF };
}  // namespace ppm
