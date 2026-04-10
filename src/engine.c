#include <SDL3/SDL.h>
#include "engine.h"

struct GameEngine {
    SDL_WindowID window;
    SDL_RendererID renderer;
};

SDL_WindowID game_get_window(GameEngine *game_engine)
{
    return game_engine->window;
}

SDL_RendererID game_get_renderer(GameEngine *game_engine)
{
    return game_engine->renderer;
}
