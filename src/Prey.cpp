#include <Prey.hpp>
#include <SFML/Graphics.hpp>

Prey::Prey()
{
    // sf::Texture texture;
    // texture.loadFromFile("../../assets/prey0.png");
    // this->sprite.setTexture(texture);
    this->type = "prey";
    this->texture.loadFromFile("../../assets/prey0.png");
    this->sprite.setTexture(this->texture);
}