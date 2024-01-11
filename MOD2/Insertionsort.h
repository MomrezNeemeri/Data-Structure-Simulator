#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include "DataStructure.h"
#include"TextInputExample.h"

class InsertionSortSimulation {
public:
    InsertionSortSimulation(const std::vector<int>& list);

    void run();

private:
    sf::RenderWindow window;
    sf::Font font;
    sf::Text text;

    std::vector<int> array;
    int currentIndex;
    bool isSorting;

    void handleEvents();
    void update();
    void render();

    void drawSorted(const std::string& str, float x, float y, const sf::Color& color);
    void drawUnsorted(const std::string& str, float x, float y, const sf::Color& color);
    void drawBox(float x, float y, float width, float height);
    void drawRectangle(float x, float y, float width, float height);
    void drawSortName(const std::string& str, float x, float y, const sf::Color& color);
    void drawText(const std::string& str, float x, float y, const sf::Color& color);
    void drawSeparator(float x);

    void performInsertionSortStep();
};

