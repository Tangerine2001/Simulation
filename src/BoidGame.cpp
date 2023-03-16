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
        HandleOutOfBounds(boid);
        boid.Update();
        gameObjects.push_back(boid);
    }

    return gameObjects;
}

void BoidGame::HandleOutOfBounds(Boid &boid)
{
    // Make a forward facing raycast to check if the boid will be out of bounds. Length of raycast should be 100 pixels.
    Vector2 raycast = boid.velocity.Normalized() * 100.0f;
    Vector2 raycastEnd = boid.position + raycast;

    Vector2 boundsAdjustment(0, 0);
    if (raycastEnd.y < 0) // Check raycast crosses top border
    {
        // If the raycast will be out of bounds, rotate the boid depending on the angle relative to the boundary.
        // angle -= Vector2::AngleBetween(boid.velocity, Vector2(1, 0));
        boundsAdjustment += Vector2(0, -1);
    }
    if (raycastEnd.x > windowWidth) // Check raycast crosses right border
    {
        // If the raycast will be out of bounds, rotate the boid depending on the angle relative to the boundary.
        // angle += 180 - (Vector2::AngleBetween(boid.velocity, Vector2(0, -1)));
         boundsAdjustment += Vector2(1, 0);
    }
    if (raycastEnd.y > windowHeight) // Check raycast crosses bottom border
    {
        // If the raycast will be out of bounds,Tang rotate the boid depending on the angle relative to the boundary.
        // angle += Vector2::AngleBetween(boid.velocity, Vector2(-1, 0));
        boundsAdjustment += Vector2(0, 1);
    }
    if (raycastEnd.x < 0)  // Check raycast crosses left border
    {
        // If the raycast will be out of bounds, rotate the boid depending on the angle relative to the boundary.
        // angle += Vector2::AngleBetween(boid.velocity, Vector2(0, 1));
        boundsAdjustment += Vector2(-1, 0);
    }

    // angle *= 0.01f;
    // boid.Rotate(angle);
    boid.acceleration -= boundsAdjustment;
}