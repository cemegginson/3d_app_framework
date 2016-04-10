#include <ctime>
#include <iostream>

#include "SDL.h"

#include "util/definitions.h"
#include "core/app_3d.h"

int main(int argc, char* argv[]) {
    UNUSED(argc); UNUSED(argv);

    App3D* app = new App3D();
    if (!app->Initialize()) {
        printf("Game could not Initialize!");
        exit(1);
    }

    app->Run();

    if (app != nullptr) {
        delete app;
        app = nullptr;
    }

    return 0;
}
