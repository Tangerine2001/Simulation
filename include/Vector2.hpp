#ifndef VECTOR2_HPP
#define VECTOR2_HPP

class Vector2 
{
    public:
        Vector2();
        Vector2(float x, float y);
        
        float Length();
        Vector2 Normalized();
        void Rotate(float angle);

        Vector2 operator+(Vector2 other);
        Vector2 operator+=(Vector2 other);
        Vector2 operator-(Vector2 other);
        Vector2 operator-=(Vector2 other);
        Vector2 operator*(float other);
        Vector2 operator*=(float other);
        Vector2 operator/(float other);
        Vector2 operator/=(float other);

        float x;
        float y;

        static float AngleBetween(Vector2 vec1, Vector2 vec2);
        static float Distance(Vector2 vec1, Vector2 vec2);
};

#endif