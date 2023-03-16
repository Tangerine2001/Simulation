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

void BoidGame::Start(sf::RenderWindow &window)
{
    this->window = &window;

    // Get a pointer to the texture. This will simplify the code below.
    sf::Texture *tex = this->texture;
    float scale = 0.02f;

    // Create numBoids boids
    int numBoids = 1;
    for (int i = 0; i < numBoids; i++)
    {
        Boid boid;
        boid.position = Vector2(Random::Range(0.0f, (float)windowWidth), Random::Range(0.0f, (float)windowHeight));
        boid.velocity = Vector2(0, -1);
        boid.sprite.setTexture(*tex);
        boid.sprite.setScale((*tex).getSize().x * scale, (*tex).getSize().y * scale);
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
    Vector2 raycast = boid.velocity.Normalized() * 200.0f;
    Vector2 raycastEnd = boid.position + raycast;

    // Draw the raycast for debugging purposes
    sf::VertexArray raycastLine(sf::LinesStrip, 2);
    raycastLine[0].position = sf::Vector2f(boid.position.x, boid.position.y);
    raycastLine[1].position = sf::Vector2f(raycastEnd.x, raycastEnd.y);
    this->window->draw(raycastLine);

    // Create a bounds adjustment vector that redirects the boid towards the center of the window if the raycast is out of bounds.
    Vector2 boundsAdjustment(0, 0);
    if (raycastEnd.y < 0) { boundsAdjustment += Vector2(0, 1); } // Check raycast crosses top border
    if (raycastEnd.x > windowWidth) { boundsAdjustment += Vector2(-1, 0); } // Check raycast crosses right border
    if (raycastEnd.y > windowHeight) { boundsAdjustment += Vector2(0, -1);} // Check raycast crosses bottom border
    if (raycastEnd.x < 0) { boundsAdjustment += Vector2(1, 0); } // Check raycast crosses left border

    // Add the adjustment vector to the boid's acceleration
    boid.acceleration += boundsAdjustment;
}