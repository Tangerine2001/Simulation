#include <BoidGame.hpp>
#include <iostream>

#include <Vector2.hpp>
#include <Boid.hpp>
#include <Random.hpp>

void BoidGame::Init(int windowWidth, int windowHeight, sf::Texture *texture)
{
    this->windowWidth = windowWidth;
    this->windowHeight = windowHeight;
    this->texture = texture;
}

BoidGame::BoidGame() { Init(800, 600, nullptr); }

BoidGame::BoidGame(int windowWidth, int windowHeight, sf::Texture *texture) { Init(windowWidth, windowHeight, texture); }

void BoidGame::Start()
{
    int numBoids = 1;

    // Create numBoids boids
    for (int i = 0; i < numBoids; i++)
    {
        Boid boid;
        boid.position = Vector2(Random::Range(0.0f, (float)windowWidth), Random::Range(0.0f, (float)windowHeight));
        boid.velocity = Vector2(0, -1);
        boid.sprite.setTexture(*texture);
        boids.push_back(boid);
    }
}

std::vector<GameObject> BoidGame::Update()
{
    std::vector<GameObject> gameObjects;

    // Update boids
    for (Boid &boid : boids)
    {
        boid.Update();
        HandleOutOfBounds(boid);
        boid.sprite.setPosition(boid.position.x, boid.position.y);
        boid.sprite.setRotation(boid.angle);
        gameObjects.push_back(boid);
    }

    return gameObjects;
}

void BoidGame::HandleOutOfBounds(Boid &boid)
{
    // Make a forward facing raycast to check if the boid will be out of bounds. Length of raycast should be 20 pixels.
    Vector2 raycast = boid.velocity.Normalized() * 20.0f;
    Vector2 raycastEnd = boid.position + raycast;

    // Check raycast crosses top border
    if (raycastEnd.y < 0)
    {
        // If the raycast will be out of bounds, rotate the boid depending on the angle relative to the boundary.
        float angle = Vector2::AngleBetween(boid.velocity, Vector2(0, 1));

        angle *= 0.1f;
        boid.Rotate(angle);
    }
    
}