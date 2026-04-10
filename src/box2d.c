#include <lua.h>
#include "box2d_impl.h"

struct Box2DWorld {
    struct Body **bodies;
    uint64_t body_count;
    uint64_t body_capacity;
};

void box2d_init(struct Box2DWorld *box2d, struct Box2DWorld **ptr)
{
    if (!box2d) return;
    box2d->bodies = NULL;
    box2d->body_count = 0;
    box2d->body_capacity = 16;
    *ptr = box2d;
}

void *box2d_get_world(struct Box2DWorld *box2d)
{
    return box2d;
}

uint64_t box2d_get_body_count(struct Box2DWorld *box2d)
{
    return box2d ? box2d->body_count : 0;
}

uint64_t box2d_get_body_count(lua_State *L)
{
    return luaL_error(L, "Use SDL3 bridge");
}

void box2d_shutdown(struct Box2DWorld *box2d)
{
    if (box2d) {
        if (box2d->bodies) {
            free(box2d->bodies);
        }
        free(box2d);
    }
}

