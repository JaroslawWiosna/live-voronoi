#include "75_world.hpp"
Coord locations[] = {{{53.12764f}, {23.15649f}, "Białystok"_sv},
                     {{54.34757f}, {18.64531f}, "Gdańsk"_sv},
                     {{50.25983f}, {19.02195f}, "Katowice"_sv},
                     {{50.06199f}, {19.93959f}, "Kraków"_sv},
                     {{52.40788f}, {16.93337}, "Poznań"_sv},
                     {{50.67034f}, {17.92026}, "Opole"_sv},
                     {{51.93970f}, {15.50500}, "Zielona Góra"_sv},
                     {{53.77610f}, {20.47750}, "Olsztyn"_sv},
                     {{54.15860f}, {19.39550}, "Elbląg"_sv},
                     {{49.29669f}, {19.94834}, "Zakopane"_sv},
                     {{49.74894f}, {18.63359}, "Cieszyn"_sv},
                     {{51.76865f}, {19.45723f}, "Łódź"_sv}};
const size_t locations_count = sizeof(locations) / sizeof(locations[0]);

SDL_Color colors[] = {
    {200, 0, 0, 255},     {100, 0, 50, 255},   {100, 100, 0, 255},
    {200, 200, 0, 255},   {0, 0, 200, 255},    {155, 200, 14, 255},
    {155, 180, 114, 255}, {55, 200, 214, 255}, {55, 100, 214, 255},
    {15, 200, 255, 255},  {15, 200, 255, 255}, {215, 110, 30, 255},
    {215, 170, 0, 255},
};
const size_t colors_count = sizeof(colors) / sizeof(colors[0]);

float manhattan(Coord a, Coord b) {
    return float(abs(a.latit.as_float - b.latit.as_float) +
                 abs(a.longit.as_float - b.longit.as_float));
}
float cubic(Coord a, Coord b) {
    return float(pow(pow(abs(a.latit.as_float - b.latit.as_float), 3) +
                         pow(abs(a.longit.as_float - b.longit.as_float), 3),
                     1.0f / 3.0f));
}
float euclidean(Coord a, Coord b) {
    return float(pow(pow(abs(a.latit.as_float - b.latit.as_float), 2) +
                         pow(abs(a.longit.as_float - b.longit.as_float), 2),
                     0.5f));
}

int closest_location(Coord c) {
    size_t manh_closest_idx{};
    size_t eucl_closest_idx{};
    const float MY_MAX_FLOAT{2000.0f};
    float manh_closest_distance{MY_MAX_FLOAT};
    float eucl_closest_distance{MY_MAX_FLOAT};
    for (int j{}; j < locations_count; j++) {
        auto manh_dist = manhattan(c, locations[j]);
        if (manh_dist < manh_closest_distance) {
            manh_closest_distance = manh_dist;
            manh_closest_idx = j;
        }
        auto eucl_dist = euclidean(c, locations[j]);
        if (eucl_dist < eucl_closest_distance) {
            eucl_closest_distance = eucl_dist;
            eucl_closest_idx = j;
        }
    }
    return (manh_closest_idx == eucl_closest_idx) ? manh_closest_idx : -1;
}

void World::update(float dt, int resolution, SDL_Renderer *renderer) {
    for (int y{}; y < resolution; ++y) {
        for (int x{}; x < resolution; ++x) {
            auto tmp = camera.at(x * (SCREEN_HEIGHT / resolution),
                                 y * (SCREEN_HEIGHT / resolution));
            auto idx = closest_location(tmp);
            if (idx == -1)
                continue;
            SDL_SetRenderDrawColor(renderer, colors[idx].r, colors[idx].g,
                                   colors[idx].b, colors[idx].a);
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

void World::render_names(SDL_Renderer *renderer) {
    // TODO(#20): unhardcode font_filepath
    // Consider using `fc-list | grep -i mono` and taking the first one
    const char *font_filepath = "/usr/share/fonts/gnu-free/FreeMonoOblique.ttf";
    TTF_Font *font = TTF_OpenFont(font_filepath, 48);
    if (nullptr == font) {
        // TODO(#21): Errors should be printed to stderr
        printf("Skipping render_names, because could not load font\n");
        printf("TTF_OpenFont: %s\n", TTF_GetError());
        exit(1);
        return;
    }

    // TODO(#22): We need a namespace with the most popular colors
    const SDL_Color white = {255, 255, 255, 255};

    const int BUFFER_CAPACITY{256};
    char buffer[BUFFER_CAPACITY] = {};
    for (int i{}; i < locations_count; ++i) {
        printf(" [DEBUG] %s:%d Name: %.*s\n", __FILE__, __LINE__,
               locations[i].name.len, locations[i].name.str);
        memset(buffer, '\0', BUFFER_CAPACITY);
        // TODO(#23): Polish letters are not rendered correctly
        sprintf(buffer, "%.*s", locations[i].name.len, locations[i].name.str);
        SDL_Surface *surfacemessage = TTF_RenderText_Solid(font, buffer, white);
        SDL_Texture *message =
            SDL_CreateTextureFromSurface(renderer, surfacemessage);
        SDL_Rect message_rect;
        // TODO: Cities names should be rendered near their locations
        message_rect.x = 0;
        message_rect.y = 0 + (i * 60);
        message_rect.w = 20 * locations[i].name.len;
        message_rect.h = 50;
        SDL_RenderCopy(renderer, message, nullptr, &message_rect);
        SDL_DestroyTexture(message);
        SDL_FreeSurface(surfacemessage);
    }
    return;
}
