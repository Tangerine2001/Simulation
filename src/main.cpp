#include <iostream>

#include <SFML/Graphics.hpp>
#include <TGUI/TGUI.hpp>    // This include SFML/Graphics.hpp for us
#include <GameManager.hpp>
#include <FPSCounter.hpp>
#include <ParameterSlider.hpp>
// #include <Vector2.hpp>

int main()
{
    int width = 1600;
    int height = 900;
    bool startGame = false;

    // TODO: Use this variable
    int border = 100;

    sf::RenderWindow window(sf::VideoMode(width, height), "My window");
    window.setFramerateLimit(60);

    tgui::Gui gui(window);
    tgui::Button::Ptr button = tgui::Button::create("Start");
    button->setWidth(100);
    button->setHeight(50);
    button->setPosition(700, 800);
    button->onClick.connect([&](){ startGame = !startGame; });
    gui.add(button, "button");

    ParameterSlider alignmentParam(gui, "Alignment", 0.0f, 10.0f, 0.1f, 10.0f, Vector2(100, 850), Vector2(100, 10));
    ParameterSlider cohesionParam(gui, "Cohesion", 0.0f, 10.0f, 0.1f, 10.0f, Vector2(300, 850), Vector2(100, 10));
    ParameterSlider separationParam(gui, "Separation", 0.0f, 10.0f, 0.1f, 10.0f, Vector2(500, 850), Vector2(100, 10));

    FPSCounter fpscounter(width);

    GameManager gameManager(10, 1, width, height);
    gameManager.Start(window);

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

        if (startGame)
        {
            std::vector<GameObject> gameObjects = gameManager.Update();
            for (GameObject gameObject : gameObjects)
            {
                window.draw(gameObject.sprite);
            }
        }

        window.draw(fpscounter.GetFPS());

        // alignmentStrengthValue->setText(std::to_string(alignmentStrength->getValue()));
        gui.draw();
        window.display();
    }
}
