#include "ballmoving.h"

ballmoving::ballmoving() : window(sf::VideoMode(1920, 1080), "SFML Ball Example") {
    ball.setRadius(30.0f);
    ball.setFillColor(sf::Color::Green);

    position = sf::Vector2f(400.0f, 300.0f);
    velocity = sf::Vector2f(1.0f, 1.0f);
}

void ballmoving::run() {
    while (window.isOpen()) {
        handleEvents();
        update();
        draw();
    }
}

void ballmoving::handleEvents() {
    sf::Event event;
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed)
            window.close();
    }
}

void ballmoving::update() {
    position += velocity;

    if (position.x - ball.getRadius() < 0 || position.x + ball.getRadius() > window.getSize().x) {
        velocity.x = -velocity.x;
    }
    if (position.y - ball.getRadius() < 0 || position.y + ball.getRadius() > window.getSize().y) {
        velocity.y = -velocity.y;
    }
}

void ballmoving::draw() {
    window.clear();
    ball.setPosition(position - sf::Vector2f(ball.getRadius(), ball.getRadius()));
    window.draw(ball);
    window.display();
}
