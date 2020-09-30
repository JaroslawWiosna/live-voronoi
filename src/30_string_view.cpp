#include "25_string_view.hpp"

#include <cassert>

constexpr StringView operator""_sv(const char *cstr, size_t len) {
    return {len, cstr};
}

// TODO(#1): Make operator== constexpr is possible
bool operator==(StringView lhs, StringView rhs) {
    assert(!"TODO: Implement operator== for StringView");
    return {};
}
