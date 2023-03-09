#ifndef BOID_HPP
#define BOID_HPP

#include <GameObject.hpp>

class Boid : public GameObject
{
    public:
        Boid();
        virtual ~Boid();

        void Update();
    protected:
    private:
};

#endif