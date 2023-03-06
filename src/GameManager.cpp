#include <iostream>

#include <GameManager.hpp>
#include <GameObject.hpp>
#include <Prey.hpp>
#include <Random.hpp>

void GameManager::Init(int numPreys, int numPredators, int windowWidth, int windowHeight)
{
    this->numPreys = numPreys;
    this->numPredators = numPredators;
    this->windowWidth = windowWidth;
    this->windowHeight = windowHeight;
    
    sf::Texture preyTexture;
    preyTexture.loadFromFile("../assets/prey0.png");
    sf::Texture predatorTexture;
    predatorTexture.loadFromFile("../assets/prey0.png");

    this->textures = std::vector<sf::Texture>();
    this->textures.push_back(preyTexture);
    this->textures.push_back(predatorTexture);
}

GameManager::GameManager() { Init(10, 1, 800, 600); }
GameManager::GameManager(int numPreys, int numPredators, int windowWidth, int windowHeight) { Init(numPreys, numPredators, windowWidth, windowHeight); }

void GameManager::Start()
{
    // Don't spawn entities with borderMargin pixels of the boundary
    float borderMargin = 50.0f;

    // Create numPreys preys as GameObjects
    for (int i = 0; i < this->numPreys; i++)
    {
        Prey prey(i, Random::Range(0.5f, 1.0f));
        prey.position = Vector2(Random::Range(borderMargin, (float)(this->windowWidth) - borderMargin), Random::Range(borderMargin, (float)(this->windowHeight - borderMargin)));
        prey.sprite.setTexture(this->textures[0]);
        GameManager::preys.push_back(prey);
    }

}

std::vector<GameObject> GameManager::Update()
{
    std::vector<GameObject> gameObjects;
    // Update preys and predators
    for (Prey &prey : GameManager::preys)
    {
        prey.Update();
        HandleOutOfBounds(prey);
        prey.sprite.setPosition(prey.position.x, prey.position.y);
        gameObjects.push_back(prey);
    }

    return gameObjects;
}

void GameManager::HandleOutOfBounds(GameObject &gameObject)
{
    if (gameObject.position.x <= 0.0f - this->boundaryMargin)
    {
        gameObject.position.x = this->windowWidth;
    }
    else if (gameObject.position.x >= (float)(this->windowWidth + this->boundaryMargin))
    {
        gameObject.position.x = 0.0f;
    }

    if (gameObject.position.y <= 0.0f - this->boundaryMargin)
    {
        gameObject.position.y = this->windowHeight;
    }
    else if (gameObject.position.y >= (float)(this->windowHeight + this->boundaryMargin))
    {
        gameObject.position.y = 0.0f;
    }
}