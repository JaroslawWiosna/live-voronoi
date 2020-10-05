#pragma once

struct Args {
    char *font_filepath{};
    void parse(int argc, char *argv[]) {
        for (int i{}; i < argc; ++i) {
            //            printf("%d. %s\n", i, argv[i]);
        }
        if (argc > 0) {
            font_filepath = argv[1];
        }
    }
};

Args args{};
