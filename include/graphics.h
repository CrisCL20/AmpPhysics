#include <SDL2/SDL.h>

#define SCREEN_WIDTH 1600
#define SCREEN_HEIGHT 900

namespace AmpPhysics {

    class AmpPhysics {
    public:
        void init();
        void doInput();
        void prepareScene();
        void presentScene();
    private:
        SDL_Renderer* renderer;
        SDL_Window* window;
    };

    typedef struct {
        AmpPhysics physElement;
    } amp;

}