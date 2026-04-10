#ifndef RENDERER_H
#define RENDERER_H

#include <SDL3/SDL.h>

typedef struct {
    SDL_Window *window;
    SDL_Renderer *renderer;
    double width;
    double height;
} Renderer;

int renderer_create(int width, int height);
void renderer_destroy(Renderer *renderer);
void renderer_clear(Renderer *renderer, Uint32 color);
void renderer_render(Renderer *renderer);
int renderer_get_mouse_x(Renderer *renderer);
int renderer_get_mouse_y(Renderer *renderer);

#endif