#pragma once
#include "40_coord.hpp"
struct Camera {
    Coord center;
    // TODO(#13): unhardcore Camera::zoom
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
    return {{top().as_float - (dy() * y)}, {left().as_float + (dx() * x)}};
}
