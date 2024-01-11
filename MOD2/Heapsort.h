#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include "DataStructure.h"


using namespace std;
using namespace sf;

class HeapSortSimulation : public DataStructureSimulator {
public:
    HeapSortSimulation(const std::vector<int>& list);

    void run();

private:
    sf::RenderWindow window;
    sf::Font font;
    sf::Text text;
    sf::RectangleShape separatorLine;

    std::vector<int> array;
    int currentIteration;
    bool isSorting;

    void handleEvents();
    void update();
    void render();

    void drawSortUp(const std::string& str, float x, float y, const sf::Color& color);
    void drawSortDown(const std::string& str, float x, float y, const sf::Color& color);
    void drawBox(float x, float y, float width, float height);
    void drawRectangle(float x, float y, float width, float height);
    void drawSortName(const std::string& str, float x, float y, const sf::Color& color);
    void drawText(const std::string& str, float x, float y, const sf::Color& color);

    void performHeapSortStep();
    //vector<int> getInputArray();
};

