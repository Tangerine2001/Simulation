#ifndef GAMEMANAGER_HPP
#define GAMEMANAGER_HPP

#include <Prey.hpp>
#include <BoidGame.hpp>
#include <SFML/Graphics.hpp>
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

        void Init(int numPreys, int numPredators, int windowWidth, int windowHeight, int borderWidth);

        GameManager();
        GameManager(int numPreys, int numPredators, int windowWidth, int windowHeight, int borderWidth);

        void Start(sf::RenderWindow &window);
        std::vector<GameObject> Update();
    protected:
    private:
        int borderWidth;

        BoidGame boidGame;

        void HandleOutOfBounds(GameObject &gameObject);
        void HandlePreyCollision(Prey &prey);
};

#endif