#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>


using namespace std;
using namespace sf;
class DataStructureSimulator {
public:
    virtual void run();
    virtual void handleEvents();
    virtual void update();
    virtual void render();
    vector<int> getInputArray();
};