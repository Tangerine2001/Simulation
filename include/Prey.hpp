#ifndef PREY_HPP
#define PREY_HPP

#include <GameObject.hpp>

class Prey : public GameObject
{
    public:
        sf::Texture texture;
        int id;
        float speed;
        float x;
        float y;

        // Constructors
        void Init(int id, float speed);
        Prey();
        Prey(int id, float speed);

        void Update();
    protected:
    private:
};

#endif