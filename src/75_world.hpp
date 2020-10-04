#pragma once

// it keeps the current state of the world, calculates things and provide render
// method
struct World {
    Camera camera{};
    void update(float dt, int resolution);
    void update(float dt, int resolution, SDL_Renderer *renderer);
    void render(SDL_Renderer *renderer);
    void render_names(SDL_Renderer *renderer);
};
