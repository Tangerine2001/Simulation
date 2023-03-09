#include <Vector2.hpp>
#include <math.h>

Vector2::Vector2()
{
    Vector2(0, 0);
}

Vector2::Vector2(float x, float y)
{
    this->x = x;
    this->y = y;
}

float Vector2::Length()
{
    return sqrt(this->x * this->x + this->y * this->y);
}

void Vector2::Rotate(float angle)
{
    float newX = this->x * cos(angle) - this->y * sin(angle);
    float newY = this->x * sin(angle) + this->y * cos(angle);
    this->x = newX;
    this->y = newY;
}

Vector2 Vector2::Normalized()
{
    float length = Length();
    return Vector2(this->x / length, this->y / length);
}

Vector2 Vector2::operator+(Vector2 other)
{
    return Vector2(this->x + other.x, this->y + other.y);
}

Vector2 Vector2::operator+=(Vector2 other)
{
    this->x += other.x;
    this->y += other.y;
    return *this;
}

Vector2 Vector2::operator*(float other)
{
    return Vector2(this->x * other, this->y * other);
}

//////////////////////
// Static functions //
//////////////////////

float Vector2::AngleBetween(Vector2 vec1, Vector2 vec2)
{
    float dot = vec1.x * vec2.x + vec1.y * vec2.y;
    float det = vec1.x * vec2.y - vec1.y * vec2.x;
    return atan2(det, dot);
}
