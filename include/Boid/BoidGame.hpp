#ifndef BOIDGAME_HPP
#define BOIDGAME_HPP

#include <BoidGame.hpp>
#include <SFML/Graphics.hpp>

class BoidGame
{
    public:
        BoidGame();
        BoidGame(int windowWidth, int windowHeight, sf::Texture *texture);

        void Start();
    protected:
    private:
};

#endif