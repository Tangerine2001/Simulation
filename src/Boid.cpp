#include <Boid.hpp>

#include <iostream>

Boid::Boid()
{
    // Print "Boid created"
    // std::cout << "Boid created" << std::endl;
}

void Boid::Update()
{

    // Update boid
    this->position += this->velocity;
}