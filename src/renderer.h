#ifndef RENDERER_H
#define RENDERER_H

#include <SDL3/SDL.h>

struct Renderer {
    SDL_Window *window;
    SDL_Renderer *renderer;
    int width;
    int height;
};

#define MOUSE_X 0
#define MOUSE_Y 1

void renderer_create(struct Renderer *renderer, int width, int height);
void renderer_destroy(struct Renderer *renderer);
void renderer_clear(struct Renderer *renderer, Uint32 color);
void renderer_render(struct Renderer *renderer);
int renderer_get_mouse_x(struct Renderer *renderer);
int renderer_get_mouse_y(struct Renderer *renderer);

#endif
