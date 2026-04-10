#ifndef ENGINE_H
#define ENGINE_H

#include <SDL3/SDL.h>

#ifdef sdl_lua_bindings_EXPORTS
#define S3_API __attribute__((visibility("default")))
#else
#define S3_API
#endif

void S3_init(SDL_Window *window, SDL_Renderer *renderer);
void S3_init_box2d(Box2DWorld* world);
void S3_init_lua_bindings();

#endif
