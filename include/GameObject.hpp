#ifndef GAMEOBJECT_HPP
#define GAMEOBJECT_HPP

#include <Vector2.hpp>
#include <SFML/Graphics.hpp>
#include <vector>

class GameObject
{
    public:
        std::string type;
        Vector2 position;
        Vector2 velocity;    
        sf::Sprite sprite;
        float angle;
        
        // Constructors and init
        void Init(Vector2 position);
        GameObject();
        GameObject(Vector2 position);

        // Methods
        void Update();
        void Rotate(float angle);
    protected:
    private:
};

#endif // GAMEOBJECT_HPP