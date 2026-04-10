#ifndef SDL3_LUA_BINDINGS_H
#define SDL3_LUA_BINDINGS_H

/* SDL3 Common Functions -> Lua */
extern void *S3_create_window(lua_State *L, int win_id_width, int win_id_height, int win_flags);
extern int S3_create_renderer(lua_State *L, void *window, const char *name);
extern void S3_quit(lua_State *L);
extern void S3_log(lua_State *L, const char *msg);
extern void S3_error(lua_State *L, const char *error);

/* Window Functions */
extern void S3_set_title(lua_State *L, void *window, const char *title);
extern void S3_set_size(lua_State *L, void *window, int w, int h);
extern void S3_destroy_window(lua_State *L, void *window);

/* Renderer Functions */
extern void S3_draw_rectangle(lua_State *L, void *renderer, int x, int y, int w, int h);
extern void S3_clear(lua_State *L, void *renderer, int r, int g, int b, int a);

/* Event Handling */
extern void S3_pump_events(lua_State *L);
extern int S3_wait_event(lua_State *L, void *window);

/* Physics Integration */
extern void S3_apply_box2d_to_renderer(lua_State *L, void *renderer, void *box2d_world);

#endif /* SDL3_LUA_BINDINGS_H */
