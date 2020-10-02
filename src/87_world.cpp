#include "75_world.hpp"

void World::update(float dt, int resolution, SDL_Renderer *renderer) {
    for (int y{}; y < resolution; ++y) {
        for (int x{}; x < resolution; ++x) {
            auto tmp = camera.at(x * (SCREEN_HEIGHT / resolution),
                                 y * (SCREEN_HEIGHT / resolution));
            SDL_SetRenderDrawColor(renderer, 100 + x * 10 - y * 10, 20 + y * 15,
                                   250 - x * 24, 255);
            SDL_Rect rect{(int)((SCREEN_WIDTH / resolution) * x),
                          (int)((SCREEN_HEIGHT / resolution) * y),
                          (int)(SCREEN_WIDTH / resolution),
                          (int)(SCREEN_HEIGHT / resolution)};
            SDL_RenderFillRect(renderer, &rect);
        }
    }

    return;
}

void World::render(SDL_Renderer *renderer) {
    assert(!"For now rendering is inside World::Update");
    return;
}
