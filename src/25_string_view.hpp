#pragma once

struct StringView {
    size_t len;
    const char *str;
};

constexpr bool operator==(StringView lhs, StringView rhs);
constexpr bool operator!=(StringView lhs, StringView rhs);
