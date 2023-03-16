#include <Boid.hpp>

#include <iostream>

#define PI 3.14159265

Boid::Boid()
{
    // Print "Boid created"
    // std::cout << "Boid created" << std::endl;
    this->velocity = Vector2(1, 0);
    this->sprite.setOrigin(16, 16);
}

void Boid::Update()
{

    // Update boid
    this->position += this->velocity;
    this->velocity += this->acceleration;
    this->velocity = this->velocity.Normalized() * 5.0f;
    this->acceleration *= 0;

    float angle = atan2(velocity.y, velocity.x);
    angle = angle * (180 / PI) - 90;
    angle = (velocity.x < 0.0f || velocity.y < 0.0f) ? angle - 180 : angle + 180;

    sprite.setRotation(angle);
    sprite.setPosition(position.x, position.y);
}