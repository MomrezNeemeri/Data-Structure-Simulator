#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include "DataStructure.h"
class BubbleSortSimulation : public DataStructureSimulator {
public:
    BubbleSortSimulation(const std::vector<int>& list);

    void run();

private:
    sf::RenderWindow window;
    sf::Font font;
    sf::Text text;

    std::vector<int> array;
    int currentIteration;
    bool isSorting;

    void handleEvents();
    void update();
    void render();

    void drawBox(float x, float y, float width, float height);
    void drawRectangle(float x, float y, float width, float height);
    void drawSortName(const std::string& str, float x, float y, const sf::Color& color);
    void drawText(const std::string& str, float x, float y, const sf::Color& color);

    void performBubbleSortStep();
};

