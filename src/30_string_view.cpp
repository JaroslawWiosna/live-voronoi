#include "25_string_view.hpp"

#include <cassert>

constexpr bool StringView::empty() const {
    return (0 == len);
}

constexpr StringView StringView::remove_prefix(size_t n) {
    auto result = StringView{(n < len ? n : len), str};
    str += n;
    len = (n < len) ? len - n : 0;
    return result;
}

constexpr StringView StringView::remove_suffix(size_t n) {
    auto result =
        StringView{(n < len ? n : len), str + (n < len ? (len - n) : 0)};
    len = (n < len) ? len - n : 0;
    return result;
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
static_assert("Foo"_sv == "Foobar"_sv.remove_prefix(3));
static_assert("bar"_sv == "Foobar"_sv.remove_suffix(3));
