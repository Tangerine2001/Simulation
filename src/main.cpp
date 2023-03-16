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

    sf::Font font;
    font.loadFromFile("../assets/arial.ttf");

    sf::Text fpsCounter;
    fpsCounter.setFont(font);
    fpsCounter.setCharacterSize(16);
    fpsCounter.setFillColor(sf::Color::White);
    fpsCounter.setPosition(((float) width / 2.0f) - 70, 10);

    sf::Clock clock;
    float lastTime = 0.0f;
    float currentTime = 0.0f;
    float fpsUpdateInterval = 0.6f;
    int frames = 0;

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

        frames++;
        currentTime = clock.getElapsedTime().asSeconds();
        if ((currentTime - lastTime) > fpsUpdateInterval)
        {
            fpsCounter.setString("FPS: " + std::to_string((int) (frames/(currentTime - lastTime))));
            lastTime = currentTime;
            frames = 0;
        }
        window.draw(fpsCounter);

        window.display();
    }
}
