#include <GameObject.hpp>
#include <random>

GameObject::GameObject()
{
    // Randomize the vector x, y between the values 100 and 200 for both
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(100, 200);
    Init(Vector2(dis(gen), dis(gen)));
}

GameObject::GameObject(Vector2 position)
{
    Init(position);
}

void GameObject::Init(Vector2 position)
{
    this->position = position;
    this->sprite.setPosition(position.x, position.y);
}