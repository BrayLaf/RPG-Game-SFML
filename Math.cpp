#include "Math.h"

sf::Vector2f Math::normalizeVector(sf::Vector2f vector) {
    float m = std::sqrt(vector.x * vector.x + vector.y * vector.y);

    sf::Vector2f normalizedVector;
    normalizedVector.x = vector.x / m;
    normalizedVector.y = vector.y / m;

    return normalizedVector;

}

bool Math::CheckRectCollision(sf::FloatRect rect1, sf::FloatRect rect2)
{
    if (rect1.intersects(rect2)) {
        return true;
    }
    
    return false;
}
