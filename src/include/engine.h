#ifndef ENGINE_H
#define ENGINE_H

#include <SDL3/SDL.h>
#include <stdbool.h>

typedef struct {
    SDL_Window *window;
    SDL_Renderer *renderer;
    int width;
    int height;
} Renderer;

typedef struct {
    float gravity_x;
    float gravity_y;
    float dt;
    void *world;
} PhysicsWorld;

typedef struct GameEngine {
    int window_width;
    int window_height;
    SDL_Window *window;
    Uint32 last_tick;
    Uint32 last_update;
    bool initialized;
} GameEngine;

extern GameEngine *game_engine_create(int width, int height);
extern void game_engine_destroy(GameEngine *engine);
extern bool engine_init(GameEngine *engine);
extern void engine_run(GameEngine *engine);
extern void update_renderer(GameEngine *engine);
extern void update_physics(GameEngine *engine);
extern void update_events(GameEngine *engine);

#endif // ENGINE_H
