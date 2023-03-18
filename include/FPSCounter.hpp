#ifndef FPSCOUNTER_HPP
#define FPSCOUNTER_HPP

#include <SFML/Graphics.hpp>

class FPSCounter
{
    public:
        FPSCounter(int width);

        sf::Text GetFPS();
    private:
        sf::Font font;
        sf::Text fpsCounter;
        sf::Clock clock;
        float lastTime = 0.0f;
        float currentTime = 0.0f;
        float fpsUpdateInterval = 0.6f;
        int frames = 0;

};

#endif