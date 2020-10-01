#pragma once

// This is a lite version of std::string_view
// https://code.woboq.org/gcc/libstdc++-v3/include/std/string_view.html#70
//
// even len and str names are the same as std's
struct StringView {
    size_t len;
    const char *str;

    constexpr bool empty() const;
};

constexpr bool operator==(StringView lhs, StringView rhs);
constexpr bool operator!=(StringView lhs, StringView rhs);
