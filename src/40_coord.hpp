#pragma once

// Example or rather special Latitudes are:
//   Equator
//   Tropic of Cancer
//   Tropic of Capricorn
//   Arctic Circle
//   Antarctic Circle
struct Latitude {
    float as_float{};
};

constexpr auto arctic_circle = Latitude{66.57f};
constexpr auto tropic_of_cancer = Latitude{23.43659f};
constexpr auto equator = Latitude{0.0f};
constexpr auto tropic_of_capricorn = Latitude{-23.43659f};
constexpr auto antarctic_circle = Latitude{-66.57f};

// The most famous one is Greenwich
struct Longitude {
    float as_float{};
};

constexpr auto prime_meridian = Longitude{0.0f};

// as km
struct Distance {
    float as_float{};
};
struct Coord {
    Latitude latit{};
    Longitude longit{};
    StringView name{};
    constexpr Coord() {
    }
    constexpr Coord(Latitude lat, Longitude lon, StringView sv = {})
        : latit{lat}, longit{lon}, name{sv} {
    }
};
