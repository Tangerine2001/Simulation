#ifndef GAMEMANAGER_HPP
#define GAMEMANAGER_HPP

#include <Prey.hpp>
#include <Boid/BoidGame.hpp>
// #include <Predator.hpp>

class GameManager
{
    public:
        int numPreys;
        int numPredators;
        int windowWidth;
        int windowHeight;
        
        static inline std::vector<Prey> preys;
        // static inline std::vector<Predator> predators;
        std::vector<sf::Texture> textures;

        void Init(int numPreys, int numPredators, int windowWidth, int windowHeight);

        GameManager();
        GameManager(int numPreys, int numPredators, int windowWidth, int windowHeight);

        void Start();
        std::vector<GameObject> Update();
    protected:
    private:
        float boundaryMargin = 1.0f;

        void HandleOutOfBounds(GameObject &gameObject);
        void HandlePreyCollision(Prey &prey);
};

#endif