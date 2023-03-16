#include <GameObject.hpp>
#include <stdlib.h>
#include <iostream>

GameObject::GameObject()
{
    // Randomize the vector x, y between the values 100 and 200 for both
    int randX = rand() % 100 + 100;
    int randY = rand() % 100 + 100;
    Init(Vector2(randX, randY));
}

GameObject::GameObject(Vector2 position)
{
    Init(position);
}

void GameObject::Init(Vector2 position)
{
    this->position = position;
    this->sprite.setPosition(position.x, position.y);
    this->angle = 0;
}

void GameObject::Update()
{
    // Do nothing
}