#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
#include <deque>
#include "DataStructure.h"
using namespace std;
using namespace sf;


class DequeSimulator : public DataStructureSimulator {
public:



    
    class CountExceededException : public std::exception {
    public:
        const char* what() const noexcept override {
            return "Count exceeded 15.";
        }
    };
        
    DequeSimulator();

private:
    sf::RenderWindow window;
    sf::Font font;
    std::deque<int> myDeque;
  
    float movementDistance;
    sf::RectangleShape movingRectangle;
    sf::Clock pushBackAnimationClock;
    sf::Clock pushFrontAnimationClock;
    sf::Clock popBackAnimationClock;
    sf::Clock popFrontAnimationClock;

    void run();
    void handleEvents();
    void update();
    void render();
    void pushBackElement();
    void pushFrontElement();
    void popBackElement();
    void popFrontElement();
    void drawDeque();
    void updateDequeText();
    void updatePushBackMovement();
    void updatePushFrontMovement();
    void updatePopBackMovement();
    void updatePopFrontMovement();
    void draw();
    void handleTextInput(const sf::Event::TextEvent& textEvent);


    Text text;
    Text inputBox;
    Text inputBox2;
    Text inputBox3;
    Text inputBox4;
    Text inputBox5;
    string inputText;
    int count;
};

