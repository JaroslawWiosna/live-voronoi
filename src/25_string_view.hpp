#pragma once

// This is a lite version of std::string_view
// https://code.woboq.org/gcc/libstdc++-v3/include/std/string_view.html#70
//
// even len and str names are the same as std's
struct StringView {
    size_t len;
    const char *str;

    constexpr bool empty() const;
    constexpr StringView remove_prefix(size_t n);
    constexpr StringView remove_suffix(size_t n);
    constexpr bool starts_with(StringView that) const;
    constexpr bool ends_with(StringView that) const;
};

constexpr StringView operator""_sv(const char *cstr, size_t len) {
    return {len, cstr};
}

constexpr bool operator==(StringView lhs, StringView rhs);
constexpr bool operator!=(StringView lhs, StringView rhs);
