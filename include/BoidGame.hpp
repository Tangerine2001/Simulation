#ifndef BOIDGAME_HPP
#define BOIDGAME_HPP

#include <SFML/Graphics.hpp>
#include <Boid.hpp>
#include <GameObject.hpp>

class BoidGame
{
    public:
        void Init(int windowWidth, int windowHeight, sf::Texture *texture);
        BoidGame();
        BoidGame(int windowWidth, int windowHeight, sf::Texture *texture);

        void Start(sf::RenderWindow &window);
        std::vector<GameObject> Update();
    protected:
    private:
        int windowWidth;
        int windowHeight;
        sf::Texture *texture;
        sf::RenderWindow *window;

        std::vector<Boid> boids;

        void HandleOutOfBounds(Boid &boid);
        void DrawLine(Vector2 start, Vector2 end, sf::Color color = sf::Color::White);
};

#endif