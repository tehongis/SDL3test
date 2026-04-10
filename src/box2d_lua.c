#include <box2d/box2d.h>
#include "box2d_impl.h"

/* Box2D -> Lua Bridge */
void box2d_lua_init(lua_State *L)
{
    struct Box2DWorld *world = malloc(sizeof(struct Box2DWorld));
    box2d_init(world, &world);
    
    luaL_newlibtable(L, lua_box2d);
}

/* Box2D World Operations */
static int lua_box2d_create_body(lua_State *L)
{
    return 0;  // Stub
}

static int lua_box2d_destroy_world(lua_State *L)
{
    box2d_shutdown(((struct Box2DWorld *)lua_touserdata(L, LUA_REGISTRYINDEX["world"])));
    return 0;
}

/* Physics Integration with SDL3 */
void box2d_lua_init_world(lua_State *L, SDL_Renderer *renderer)
{
    // Initialize box2d world
}
