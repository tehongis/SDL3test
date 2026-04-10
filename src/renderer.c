#include <SDL3/SDL.h>
#include "renderer.h"
#include "engine.h"

static int g_mouse_x = 0;
static int g_mouse_y = 0;

static struct SDL_WindowID g_initialized_window_id = 0;

struct Renderer *renderer_create(int width, int height)
{
    struct Renderer *renderer = SDL_calloc(1, sizeof(struct Renderer));
    if (!renderer)
        return NULL;

    renderer->width = width;
    renderer->height = height;

    struct SDL_WindowID window_id = SDL_CreateWindow("My Game", width, height, 0);
    if (!window_id) {
        SDL_free(renderer);
        return NULL;
    }

    renderer->window = window_id;

    struct SDL_Window *window = (struct SDL_Window *)window_id;
    struct SDL_Renderer *renderer_id = SDL_CreateRenderer(window, -1, 0);
    if (!renderer_id) {
        SDL_DestroyWindow(g_initialized_window_id);
        SDL_free(renderer);
        return NULL;
    }

    renderer->renderer = renderer_id;

    return renderer;
}

void renderer_destroy(struct Renderer *renderer)
{
    if (renderer) {
        if (renderer->renderer) {
            SDL_DestroyRenderer(renderer->renderer);
            renderer->renderer = NULL;
        }
        if (renderer->window) {
            SDL_DestroyWindow(renderer->window);
            renderer->window = NULL;
        }
        SDL_free(renderer);
    }
}

void renderer_clear(struct Renderer *renderer, Uint32 color)
{
    if (renderer->renderer) {
        SDL_RenderClear(renderer->renderer);
    }
}

void renderer_render(struct Renderer *renderer)
{
    if (renderer->renderer) {
        SDL_Present(renderer->renderer);
    }
}

int renderer_get_mouse_x(struct Renderer *renderer)
{
    return g_mouse_x;
}

int renderer_get_mouse_y(struct Renderer *renderer)
{
    return g_mouse_y;
}
