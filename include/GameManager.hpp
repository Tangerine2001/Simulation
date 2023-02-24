#ifndef GAMEMANAGER_HPP
#define GAMEMANAGER_HPP

#include <GameObject.hpp>

class GameManager
{
    public:
        int numPreys;
        int numPredators;
        
        static inline std::vector<GameObject> gameObjects;
        std::vector<sf::Texture> textures;

        void Init(int numPreys, int numPredators);

        GameManager();
        GameManager(int numPreys, int numPredators);

        void start();
    protected:
    private:
};

#endif