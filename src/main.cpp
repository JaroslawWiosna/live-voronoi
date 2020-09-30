#include <SDL.h>

#include "50_constants.hpp"
#include "87_world.cpp"

int main(int argc, char* argv[]) {
    World world{};
    SDL_Window* window = SDL_CreateWindow(argv[0], 0, 0, SCREEN_WIDTH,
                                          SCREEN_HEIGHT, SDL_WINDOW_RESIZABLE);

    SDL_Renderer* renderer = SDL_CreateRenderer(
        window, -1, SDL_RENDERER_PRESENTVSYNC | SDL_RENDERER_ACCELERATED);
    SDL_RenderSetLogicalSize(renderer, SCREEN_WIDTH, SCREEN_HEIGHT);

    bool quit{};
    while (not quit) {
        SDL_Event event;
        while (SDL_PollEvent(&event)) {
            switch (event.type) {
                case SDL_KEYDOWN: {
                    switch (event.key.keysym.sym) {
                        case SDLK_1:
                        case SDLK_2: {
                            // TBD
                        } break;
                        case SDLK_q: {
                            quit = !quit;
                        } break;
                    }
                    break;
                }
            }
        }
        world.update(0.5f);
        world.render(renderer);
        SDL_RenderPresent(renderer);
    }
    SDL_Quit();
}
