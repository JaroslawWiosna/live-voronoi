Coord locations[] = {{{53.12764f}, {23.15649f}, "Białystok"_sv},
                     {{54.34757f}, {18.64531f}, "Gdańsk"_sv},
                     {{50.25983f}, {19.02195f}, "Katowice"_sv},
                     {{50.06199f}, {19.93959f}, "Kraków"_sv},
                     {{51.76865f}, {19.45723f}, "Łódź"_sv}};
const size_t locations_count = sizeof(locations) / sizeof(locations[0]);
SDL_Color colors[] = {
    {200, 0, 0, 255},   {100, 0, 50, 255}, {100, 100, 0, 255},
    {200, 200, 0, 255}, {0, 0, 200, 255},
};
const size_t colors_count = sizeof(colors) / sizeof(colors[0]);
static_assert(locations_count <= colors_count);
