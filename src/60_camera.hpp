#pragma once
#include "40_coord.hpp"
#include "59_vec.hpp"
struct Camera {
    Coord center;
    // TODO(#18): zoom level should correspond to OpenStreetMap zoom
    // https://wiki.openstreetmap.org/wiki/Zoom_levels
    float zoom{10.0f};
    constexpr Longitude left() const;
    constexpr Longitude right() const;
    constexpr Latitude top() const;
    constexpr Latitude bottom() const;
    constexpr Coord top_left() const;
    constexpr Coord bottom_left() const;
    constexpr Coord top_right() const;
    constexpr Coord bottom_right() const;
    constexpr float dx() const;
    constexpr float dy() const;
    constexpr Coord at(int x, int y) const;
    vec2i coord_to_xy(Coord coord);
};

constexpr Longitude Camera::left() const {
    return {center.longit.as_float - (zoom * 0.6f)};
}
constexpr Longitude Camera::right() const {
    return {center.longit.as_float + (zoom * 0.6f)};
}
constexpr Latitude Camera::top() const {
    return {center.latit.as_float + (zoom * 0.4f)};
}
constexpr Latitude Camera::bottom() const {
    return {center.latit.as_float - (zoom * 0.4f)};
}
constexpr Coord Camera::top_left() const {
    return {{top()}, {left()}};
}
constexpr Coord Camera::bottom_left() const {
    return {{bottom()}, {left()}};
}
constexpr Coord Camera::top_right() const {
    return {{top()}, {left()}};
}
constexpr Coord Camera::bottom_right() const {
    return {{bottom()}, {right()}};
}
constexpr float Camera::dx() const {
    return (right().as_float - left().as_float) / SCREEN_WIDTH;
}
constexpr float Camera::dy() const {
    return (top().as_float - bottom().as_float) / SCREEN_HEIGHT;
}

constexpr Coord Camera::at(int x, int y) const {
    return {{((top().as_float - bottom().as_float) * (float)y / SCREEN_HEIGHT) +
             bottom().as_float},
            {((right().as_float - left().as_float) * (float)x / SCREEN_WIDTH) +
             left().as_float}};
}

vec2i Camera::coord_to_xy(Coord coord) {
    printf("For %.*s \n", coord.name.len, coord.name.str);
    printf("(coord.longit.as_float - left().as_float) / dx()");
    printf(" %f\n", (coord.longit.as_float - left().as_float) / dx());
    printf("(top().as_float - coord.latit.as_float) / dy()");
    printf(" %f\n", (top().as_float - coord.latit.as_float) / dy());
    printf("\n");
    return {(coord.longit.as_float - left().as_float) /
                (right().as_float - left().as_float) * SCREEN_WIDTH,
            (top().as_float - coord.latit.as_float) /
                (top().as_float - bottom().as_float) * SCREEN_HEIGHT};
}
