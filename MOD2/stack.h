#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
#include <stack>
#include "DataStructure.h"


using namespace std;
using namespace sf;


class StackSimulator : public DataStructureSimulator {
public:
    class CountExceededException : public std::exception {
    public:
        const char* what() const noexcept override {
            return "Count exceeded 15.";
        }
    };
    StackSimulator();

private:
    RenderWindow window;
    Font font;
    stack<int> myStack;
    
    Text inputText;  // Added for graphical input
    float movementDistance;
    RectangleShape movingRectangle;
    Clock pushAnimationClock;
    //Clock popAnimationClock;
    int elementsToAddIndex;

    void run();
    void handleEvents();
    void update();
    void render();
    void pushElement();
    void popElement();
    void drawStack();
    void updateStackText();
    void updatePushMovement();
    //void updatePopMovement();

    void draw();
    void handleTextInput(const sf::Event::TextEvent& textEvent);


    Text text;
    Text inputBox;
    Text inputBox2;
    Text inputBox3;
    string inputText1;
    int count;
};

