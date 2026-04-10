#ifndef PHYSICS_H
#define PHYSICS_H

#include <stdbool.h>
#include "engine.h"

typedef struct {
    float gravity_x;
    float gravity_y;
    float dt;
    void *world;
} PhysicsWorld;

PhysicsWorld *physics_create(GameEngine *engine);
void physics_destroy(PhysicsWorld *world);

#endif
