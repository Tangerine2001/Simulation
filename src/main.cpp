#include <iostream>

#include <SFML/Graphics.hpp>
#include <GameManager.hpp>
// #include <Vector2.hpp>

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "My window");
    window.setFramerateLimit(144);

    sf::CircleShape shape(10.f);
    shape.setFillColor(sf::Color::Green);
    // Print shape's position
    // std::cout << shape.getPosition().x << ", " << shape.getPosition().y << std::endl;

    // Create a GameManger object and start the game
    // Vector2 position(0, 0);
    sf::Texture preyTexture;
    preyTexture.loadFromFile("../../assets/prey0.png");
    sf::Texture predatorTexture;
    predatorTexture.loadFromFile("../../assets/prey0.png");

    GameManager gameManager(10, 1);
    gameManager.start();

    // Set the textures for each of the sprites
    // for (GameObject gameObject : GameManager::gameObjects)
    // {
    //     gameObject.sprite.setTexture(preyTexture);
    // }

    // Print hello world
    // std::cout << "Hello world!" << std::endl;

    // Create a sprite based on assets/prey0.png
    // sf::Sprite sprite;
    // sprite.setTexture(texture);
    // sprite.setPosition(300, 300);

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

        // window.draw(shape);
        // window.draw(sprite);
        
        // Iterate through gameObjects and draw their sprites
        for (GameObject gameObject : GameManager::gameObjects)
        {
            // Vector2 position = gameObject.position;
            // sf::Sprite sprite;
            // sprite.setPosition(position.x, position.y);
            // gameObject.sprite.setTexture(preyTexture);
            // if (gameObject.type == "prey")
            // {
            //     gameObject.sprite.setTexture(preyTexture);
            // }
            // else if (gameObject.type == "predator")
            // {
            //     gameObject.sprite.setTexture(predatorTexture);
            // }
            window.draw(gameObject.sprite);
        }

        window.display();
    }
}
