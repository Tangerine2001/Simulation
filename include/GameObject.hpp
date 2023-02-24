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
        sf::Sprite sprite;
        
        void Init(Vector2 position);

        GameObject();
        GameObject(Vector2 position);
    protected:
    private:
};

#endif // GAMEOBJECT_HPP