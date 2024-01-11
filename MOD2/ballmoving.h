#ifndef BALL_EXAMPLE_H
#define BALL_EXAMPLE_H

#include <SFML/Graphics.hpp>

class ballmoving {
public:
    ballmoving();
    void run();
    
private:
    sf::RenderWindow window;
    sf::CircleShape ball;
    sf::Vector2f position;
    sf::Vector2f velocity;

    void handleEvents();
    void update();
    void draw();
};

#endif // BALL_EXAMPLE_H

