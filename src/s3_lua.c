#include <SDL3/SDL.h>
#include <string.h>
#include "sdl3_lua_bindings.h"

/* Window Creation */
void *S3_create_window(lua_State *L, int win_id_width, int win_id_height, int win_flags)
{
    return SDL_CreateWindow("Game", win_id_width, win_id_height, win_flags);
}

/* Renderer Creation */
int S3_create_renderer(lua_State *L, void *window, const char *name)
{
    return SDL_CreateRenderer((SDL_Window *)window, name);
}

/* SDL Quit */
void S3_quit(lua_State *L)
{
    SDL_Quit();
}

/* Logging */
void S3_log(lua_State *L, const char *msg)
{
    SDL_Log("%s", msg);
}

void S3_error(lua_State *L, const char *error)
{
    SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "%s", error);
}

/* Window Operations */
void S3_set_title(lua_State *L, void *window, const char *title)
{
    SDL_SetWindowTitle((SDL_Window *)window, title);
}

void S3_set_size(lua_State *L, void *window, int w, int h)
{
    SDL_SetWindowSize((SDL_Window *)window, w, h);
}

void S3_destroy_window(lua_State *L, void *window)
{
    SDL_DestroyWindow((SDL_Window *)window);
}

/* Renderer Operations */
void S3_draw_rectangle(lua_State *L, void *renderer, int x, int y, int w, int h)
{
    SDL_FRect rect = { (float)x, (float)y, (float)w, (float)h };
    SDL_RenderDrawRect((SDL_Renderer *)renderer, &rect);
}

void S3_clear(lua_State *L, void *renderer, int r, int g, int b, int a)
{
    SDL_Color color = { (Uint8)r, (Uint8)g, (Uint8)b, (Uint8)a };
    SDL_SetRenderDrawColor((SDL_Renderer *)renderer, r, g, b, a);
}

/* Event Handling */
void S3_pump_events(lua_State *L)
{
    SDL_PumpEvents();
}

int S3_wait_event(lua_State *L, void *window)
{
    return SDL_WaitEvent((SDL_Window *)window);
}

/* Box2D Integration */
void S3_apply_box2d_to_renderer(lua_State *L, void *renderer, void *box2d_world)
{
    SDL_SetRenderDrawColor((SDL_Renderer *)renderer, 0xFF, 0xFF, 0xFF, 0xFF);
}
