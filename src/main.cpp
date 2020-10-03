#include <SDL.h>

#include "30_string_view.cpp"
#include "40_coord.hpp"
#include "50_constants.hpp"
#include "60_camera.hpp"
#include "87_world.cpp"
#include "97_database.cpp"
#include "98_test.cpp"

int main(int argc, char *argv[]) {
#ifdef TESTS
    test();
    exit(0);
#endif // TESTS
    World world{};
    world.camera.center = {{51.798f}, {20.665f}};
    SDL_Window *window = SDL_CreateWindow(argv[0], 0, 0, SCREEN_WIDTH,
                                          SCREEN_HEIGHT, SDL_WINDOW_RESIZABLE);

    SDL_Renderer *renderer = SDL_CreateRenderer(
        window, -1, SDL_RENDERER_PRESENTVSYNC | SDL_RENDERER_ACCELERATED);
    SDL_RenderSetLogicalSize(renderer, SCREEN_WIDTH, SCREEN_HEIGHT);

    int resolution{1};
    bool need_to_render{};
    bool quit{};
    while (not quit) {
        SDL_Event event;
        while (SDL_PollEvent(&event)) {
            switch (event.type) {
                case SDL_KEYDOWN: {
                    switch (event.key.keysym.sym) {
                        case SDLK_1:
                        case SDLK_2:
                        case SDLK_3:
                        case SDLK_4:
                        case SDLK_5:
                        case SDLK_6:
                        case SDLK_7:
                        case SDLK_8:
                        case SDLK_9: {
                            resolution = event.key.keysym.sym - SDLK_0;
                            assert(resolution >= 1 && resolution < 10);
                            need_to_render = true;
                            printf(" [DEBUG] Pressed key: %d\n", resolution);
                            resolution = pow(resolution, 2);
                        } break;
                        case SDLK_q: {
                            quit = !quit;
                        } break;
                    }
                    break;
                }
            }
        }
        if (need_to_render) {
            world.update(UPDATE_TIME, resolution, renderer);
            // world.render(renderer);
            SDL_RenderPresent(renderer);
            need_to_render = false;
        }
    }
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}
