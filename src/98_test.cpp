#include "25_string_view.hpp"
// TODO(#25): Use EXPECT_EQ, EXPECT_TRUE, EXPECT_FALSE, ASSERT_EQ or more from
// https://github.com/google/googletest/blob/10ade8473b698a8fe14ddb518c2abd228669657a/googletest/docs/primer.md

// TODO(#26): Executing a test binary should print a report "X OK, Y FAILED"
void test() {
    {
        auto sv1 = "Foo"_sv;
        auto sv2 = sv1.remove_prefix(1);
        assert(sv2 == "F"_sv);
        assert(sv1 == "oo"_sv);
    }
    {
        auto sv1 = "Bar"_sv;
        auto sv2 = sv1.remove_suffix(1);
        assert(sv2 == "r"_sv);
        assert(sv1 == "Ba"_sv);
    }
    {
        auto sv1 = "Foo"_sv;
        auto sv2 = sv1.remove_prefix(0);
        assert(sv2 == ""_sv);
        assert(sv1 == "Foo"_sv);
    }
    {
        auto sv1 = "Bar"_sv;
        auto sv2 = sv1.remove_suffix(0);
        assert(sv2 == ""_sv);
        assert(sv1 == "Bar"_sv);
    }
    {
        auto sv1 = "Foo"_sv;
        auto sv2 = sv1.remove_prefix(42);
        assert(sv2 == "Foo"_sv);
        assert(sv1 == ""_sv);
    }
    {
        auto sv1 = "Bar"_sv;
        auto sv2 = sv1.remove_suffix(42);
        assert(sv2 == "Bar"_sv);
        assert(sv1 == ""_sv);
    }
}
