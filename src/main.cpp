#include <iostream>

#include <SFML/Graphics.hpp>
#include <TGUI/TGUI.hpp>    // This include SFML/Graphics.hpp for us
#include <GameManager.hpp>
#include <FPSCounter.hpp>
// #include <Vector2.hpp>

int main()
{
    int width = 1600;
    int height = 900;

    sf::RenderWindow window(sf::VideoMode(width, height), "My window");
    window.setFramerateLimit(60);

    tgui::Gui gui(window);
    tgui::Button::Ptr button = tgui::Button::create("Start");
    gui.add(button, "button");

    FPSCounter fpscounter(width);

    // GameManager gameManager(10, 1, width, height);
    // gameManager.Start(window);

    while (window.isOpen())
    {
        for (auto event = sf::Event{}; window.pollEvent(event);)
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }

            gui.handleEvent(event);
        }
        window.clear();

        // std::vector<GameObject> gameObjects = gameManager.Update();
        // for (GameObject gameObject : gameObjects)
        // {
        //     window.draw(gameObject.sprite);
        // }

        window.draw(fpscounter.GetFPS());

        gui.draw();
        window.display();
    }
}
