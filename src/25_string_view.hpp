#pragma once

struct StringView {
    size_t len;
    const char *str;
};

bool operator==(StringView lhs, StringView rhs);
