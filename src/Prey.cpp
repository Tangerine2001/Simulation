#include <iostream>

#include <Prey.hpp>
#include <Random.hpp>
#include <SFML/Graphics.hpp>


void Prey::Init(int id, float speed)
{
    this->speed = speed;
    this->type = "prey";

    // Init random variables
    this->x = Random::Range(-1.0f, 1.0f);
    this->y = Random::Range(-1.0f, 1.0f);
}

Prey::Prey() { Init(-1, Random::Range(0.5f, 1.0f)); }
Prey::Prey(int id, float speed) { Init(id, speed); }

void Prey::Update()
{
    this->position.x += this->speed * this->x;
    this->position.y += this->speed * this->y;
}