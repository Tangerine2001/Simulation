#include <iostream>

#include <SFML/Graphics.hpp>
#include <GameManager.hpp>
// #include <Vector2.hpp>

int main()
{
    int width = 800;
    int height = 600;

    sf::RenderWindow window(sf::VideoMode(width, height), "My window");
    window.setFramerateLimit(60);

    GameManager gameManager(10, 1, width, height);
    gameManager.Start();

    while (window.isOpen())
    {
        for (auto event = sf::Event{}; window.pollEvent(event);)
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
        }
        window.clear();

        std::vector<GameObject> gameObjects = gameManager.Update();
        for (GameObject gameObject : gameObjects)
        {
            window.draw(gameObject.sprite);
        }

        window.display();
    }
}
