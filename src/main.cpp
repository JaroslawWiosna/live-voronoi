#include <SDL.h>

const float SCREEN_WIDTH = 1920.0f;
const float SCREEN_HEIGHT = 1080.0f;

int main(int argc, char* argv[]) {
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
    }
}
