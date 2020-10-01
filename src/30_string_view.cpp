#include "25_string_view.hpp"

#include <cassert>

constexpr StringView operator""_sv(const char *cstr, size_t len) {
    return {len, cstr};
}

constexpr bool empty() const {
    return (0 == len);
}

constexpr bool operator==(StringView lhs, StringView rhs) {
    if (lhs.len != rhs.len) {
        return false;
    }
    for (size_t i{}; i < lhs.len; ++i) {
        if (lhs.str[i] != rhs.str[i]) {
            return false;
        }
    }
    return true;
}

constexpr bool operator!=(StringView lhs, StringView rhs) {
    return not(lhs == rhs);
}

static_assert("Foo"_sv == "Foo"_sv);
static_assert("Foo"_sv != "Foobar"_sv);
static_assert("Foobar"_sv != "Foo"_sv);
