#pragma once


#include <SFML/Graphics.hpp>
#include <iostream>
#include <ctime>
#include <sstream>
#include "DataStructure.h"

const int WINDOW_WIDTH = 1200;
const int WINDOW_HEIGHT = 900;
const int RECTANGLE_WIDTH = 80;
const int RECTANGLE_HEIGHT = 50;
const int DIVIDER_WIDTH = 5;
const int ARROW_SIZE = 10;
const int LIST_X = 200;
const int LIST_Y = 500;
const float MOVEMENT_SPEED = 5.0f;

using namespace std;
using namespace sf;

class L_Node {
public:
    int data;
    L_Node* next;

    L_Node(int value);
};

class LinkedListSimulator : public DataStructureSimulator {
public:
    LinkedListSimulator();

private:
    RenderWindow window;
    Font font;
    L_Node* head;
    Text listText;
    float movementDistance;
    RectangleShape movingRectangle;
    Clock insertFrontAnimationClock;
    Clock insertEndAnimationClock;
    Clock deleteFrontAnimationClock;
    Clock deleteEndAnimationClock;

    void run();
    void handleEvents();
    void update();
    void render();
    void insertFrontElement();
    void insertEndElement();
    void insertMiddleElement();
    void deleteFrontElement();
    void deleteEndElement();
    void drawList();
    void updateListText();
    void drawArrow(float startX, float startY, float endX, float endY, Color color);
    string formatAddress(int address);
    void addinstructions();

};
