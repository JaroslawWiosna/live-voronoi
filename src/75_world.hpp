#pragma once

// it keeps the current state of the world, calculates things and provide render
// method
struct World {
    void update(float dt);
    void render(SDL_Renderer *renderer);
};
