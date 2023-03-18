#include <FPSCounter.hpp>
#include <iostream>

FPSCounter::FPSCounter(int width)
{
    this->lastTime = 0.0f;
    float currentTime = 0.0f;
    float fpsUpdateInterval = 0.6f;
    int frames = 0;

    this->font = sf::Font();
    this->font.loadFromFile("assets/arial.ttf");

    this->fpsCounter = sf::Text();
    this->fpsCounter.setFont(font);
    this->fpsCounter.setCharacterSize(16);
    this->fpsCounter.setFillColor(sf::Color::White);
    this->fpsCounter.setPosition(((float) width / 2.0f) - 70, 10);

    this->clock = sf::Clock();
    this->clock.restart();
}

sf::Text FPSCounter::GetFPS()
{
    // this->currentTime = this->clock.getElapsedTime().asSeconds();
    // if (this->currentTime - this->lastTime >= this->fpsUpdateInterval)
    // {
    //     this->fpsCounter.setString("FPS: " + std::to_string(this->frames));
    //     this->frames = 0;
    //     this->lastTime = this->currentTime;
    // }
    // this->frames++;
    // 
    frames++;
    this->currentTime = clock.getElapsedTime().asSeconds();
    if ((this->currentTime - this->lastTime) >= this->fpsUpdateInterval)
    {
        this->fpsCounter.setString("FPS: " + std::to_string((int) (this->frames/(this->currentTime - this->lastTime))));
        this->lastTime = this->currentTime;
        this->frames = 0;
    }
    return this->fpsCounter;
}

