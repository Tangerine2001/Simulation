#include <iostream>

#include <GameManager.hpp>
#include <GameObject.hpp>
#include <Prey.hpp>

void GameManager::Init(int numPreys, int numPredators)
{
    this->numPreys = numPreys;
    this->numPredators = numPredators;
    
    sf::Texture preyTexture;
    preyTexture.loadFromFile("../../assets/prey0.png");
    sf::Texture predatorTexture;
    predatorTexture.loadFromFile("../../assets/prey0.png");

    this->textures = std::vector<sf::Texture>();
    this->textures.push_back(preyTexture);
    this->textures.push_back(predatorTexture);
}

GameManager::GameManager() { Init(10, 1); }
GameManager::GameManager(int numPreys, int numPredators) { Init(numPreys, numPredators); }

void GameManager::start()
{
    // Create numPreys preys as GameObjects
    for (int i = 0; i < this->numPreys; i++)
    {
        Prey prey;
        prey.sprite.setTexture(this->textures[0]);
        GameManager::gameObjects.push_back(prey);
    }

}