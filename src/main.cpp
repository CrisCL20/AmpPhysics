/**
 * @brief For testing purposes
 */

#include "vectors.h"
#include "basics.h"
#include "moves.h"
#include "matrix.h"
#include "graphics.h"
#include <iostream>
#include <SDL2/SDL.h>

using namespace std;

int main() {

    AmpPhysics::AmpPhysics simulator;

    simulator.init();

    system("clear");


    while(1) {
        simulator.prepareScene();
        simulator.doInput();
        simulator.presentScene();
        
        SDL_Delay(16);
    }

    return 0;

}