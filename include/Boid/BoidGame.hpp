#ifndef BOIDGAME_HPP
#define BOIDGAME_HPP

#include <SFML/Graphics.hpp>
#include <Boid.hpp>

class BoidGame
{
    public:
        void Init(int windowWidth, int windowHeight, sf::Texture *texture);
        BoidGame();
        BoidGame(int windowWidth, int windowHeight, sf::Texture *texture);

        void Start();
        std::vector<GameObject> Update();
    protected:
    private:
        int windowWidth;
        int windowHeight;
        sf::Texture *texture;

        std::vector<Boid> boids;
};

#endif