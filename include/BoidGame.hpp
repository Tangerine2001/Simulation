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
        float maxBoidSpeed = 5.0f;
        float maxBoidForce = 0.1f;
        float alignmentRadius = 100.0f;
        float alignmentStrength = 1.0f;
        float cohesionRadius = 100.0f;
        float cohesionStrength = 1.0f;
        float separationRadius = 50.0f;
        float separationStrength = 3.0f;
        sf::Texture *texture;
        sf::RenderWindow *window;

        std::vector<Boid> boids;

        void HandleOutOfBounds(Boid &boid);
        void TurnFromBorder(Boid &boid);

        Vector2 AdjustSteering(Vector2 steering, Vector2 velocity);
        Vector2 Align(Boid &boid);
        Vector2 Cohere(Boid &boid);
        Vector2 Separate(Boid &boid);

        // Utility functions
        void DrawLine(Vector2 start, Vector2 end, sf::Color color = sf::Color::White);
};

#endif