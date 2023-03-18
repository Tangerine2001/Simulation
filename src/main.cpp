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

    // tgui::Slider::Ptr alignmentStrength = tgui::Slider::create();
    // alignmentStrength->setSize(50, 10);
    // alignmentStrength->setPosition(100, 100);
    // alignmentStrength->setMinimum(0.0f);
    // alignmentStrength->setMaximum(10.0f);
    // alignmentStrength->setValue(10);
    // alignmentStrength->setStep(0.1f);
    // gui.add(alignmentStrength, "alignmentStrength");

    // tgui::Label::Ptr alignmentStrengthLabel = tgui::Label::create();
    // alignmentStrengthLabel->setText("Alignment strength");
    // alignmentStrengthLabel->setPosition(100, 80);
    // gui.add(alignmentStrengthLabel, "alignmentStrengthLabel");

    // tgui::Label::Ptr alignmentStrengthValue = tgui::Label::create();
    // alignmentStrengthValue->setText(std::to_string(alignmentStrength->getValue()));
    // alignmentStrengthValue->setPosition(100, 120);
    // gui.add(alignmentStrengthValue, "alignmentStrengthValue");

    // ParameterSlider alignmentParam;
    ParameterSlider alignmentParam(gui, "Alignment strength", 0.0f, 10.0f, 0.1f, 10.0f, Vector2(100, 100), Vector2(100, 10));


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
