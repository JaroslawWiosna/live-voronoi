#include <SDL.h>
#include <SDL_ttf.h>

#include "30_string_view.cpp"
#include "40_coord.hpp"
#include "50_constants.hpp"
#include "60_camera.hpp"
#include "65_args.hpp"
#include "87_world.cpp"
#include "97_database.cpp"
#include "98_test.cpp"

int main(int argc, char *argv[]) {
#ifdef TESTS
    test();
    exit(0);
#endif // TESTS

    args.parse(argc, argv);

    World world{};
    world.camera.center = {{51.798f}, {20.665f}};
    SDL_Window *window = SDL_CreateWindow(argv[0], 0, 0, SCREEN_WIDTH,
                                          SCREEN_HEIGHT, SDL_WINDOW_RESIZABLE);

    SDL_Renderer *renderer = SDL_CreateRenderer(
        window, -1, SDL_RENDERER_PRESENTVSYNC | SDL_RENDERER_ACCELERATED);
    SDL_RenderSetLogicalSize(renderer, SCREEN_WIDTH, SCREEN_HEIGHT);

    TTF_Init();

    int resolution{2 * 2 * 2 * 3 * 5};
    bool need_to_render{true};
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
                        case SDLK_5: {
                            resolution = event.key.keysym.sym - SDLK_0;
                            assert(resolution >= 1 && resolution < 10);
                            need_to_render = true;
                            printf(" [DEBUG] Pressed key: %d\n", resolution);
                            int resolution_array[] = {2, 2 * 2, 2 * 2 * 2,
                                                      2 * 2 * 2 * 3,
                                                      2 * 2 * 2 * 3 * 5};
                            resolution = resolution_array[resolution - 1];
                        } break;
                        case SDLK_q: {
                            quit = !quit;
                        } break;
                        case SDLK_LEFT: {
                            printf(" [DEBUG] Pressed arrow key: %s\n",
                                   SDL_GetKeyName(event.key.keysym.sym));
                            world.camera.center.longit.as_float -= 0.2f;
                            need_to_render = true;
                        } break;
                        case SDLK_UP: {
                            printf(" [DEBUG] Pressed arrow key: %s\n",
                                   SDL_GetKeyName(event.key.keysym.sym));
                            world.camera.center.latit.as_float += 0.2f;
                            need_to_render = true;
                        } break;
                        case SDLK_DOWN: {
                            printf(" [DEBUG] Pressed arrow key: %s\n",
                                   SDL_GetKeyName(event.key.keysym.sym));
                            world.camera.center.latit.as_float -= 0.2f;
                            need_to_render = true;
                        } break;
                        case SDLK_RIGHT: {
                            printf(" [DEBUG] Pressed arrow key: %s\n",
                                   SDL_GetKeyName(event.key.keysym.sym));
                            world.camera.center.longit.as_float += 0.2f;
                            need_to_render = true;
                        } break;
                        case SDLK_EQUALS: {
                            printf(" [DEBUG] Pressed key: SDLK_EQUALS\n");
                            world.camera.zoom -= 0.5f;
                            need_to_render = true;
                        } break;
                        case SDLK_MINUS: {
                            printf(" [DEBUG] Pressed key: SDLK_MINUS\n");
                            world.camera.zoom += 0.5f;
                            need_to_render = true;
                        } break;
                        default: {
                            printf(
                                " [DEBUG] Physical %s key acting as %s key\n",
                                SDL_GetScancodeName(event.key.keysym.scancode),
                                SDL_GetKeyName(event.key.keysym.sym));
                        }
                    }
                    break;
                }
            }
        }
        if (need_to_render) {
            world.update(UPDATE_TIME, resolution, renderer);
            // world.render(renderer);
            world.render_names(renderer);
            SDL_RenderPresent(renderer);
            need_to_render = false;
        }
    }
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}
