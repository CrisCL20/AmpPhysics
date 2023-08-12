#include "graphics.h"
#include <SDL2/SDL.h>
#include <iostream>

void AmpPhysics::AmpPhysics::init() {
    int rFlags, wFlags;

    rFlags = SDL_RENDERER_ACCELERATED;
    wFlags = 0;

    if(SDL_Init(SDL_INIT_VIDEO) < 0){
        std::cerr << "Could not initialize SDL: " << SDL_GetError() << std::endl;
        exit(1);
    }

    window = SDL_CreateWindow("AmpPhysics",
                              SDL_WINDOWPOS_UNDEFINED,
                              SDL_WINDOWPOS_UNDEFINED,
                              SCREEN_WIDTH,
                              SCREEN_HEIGHT,
                              wFlags
                              );
    
    if(!window) {
        std::cerr << "Could not open window: " << SDL_GetError() << std::endl;
        exit(1);
    }

    SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "linear");
    renderer = SDL_CreateRenderer(window,-1,rFlags);

    if(!renderer) {
        std::cerr << "Could not create renderer: " << SDL_GetError() << std::endl;
        exit(1);
    } 

}

void AmpPhysics::AmpPhysics::doInput() {
    SDL_Event event;

    while(SDL_PollEvent(&event)) {
        switch (event.type) {
            case SDL_QUIT:
                exit(0);
                break;
            default:
                break;
        }
    }
}

void AmpPhysics::AmpPhysics::prepareScene() {
    SDL_SetRenderDrawColor(renderer,96,128,255,SDL_ALPHA_OPAQUE);
    SDL_RenderClear(renderer);
}

void AmpPhysics::AmpPhysics::presentScene() {
    SDL_RenderPresent(renderer);
}