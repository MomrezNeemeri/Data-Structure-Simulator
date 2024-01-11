#pragma once

#include <SFML/Graphics.hpp>
#include<iostream>
#include<stdexcept>
#include<vector>
using namespace std;

class TextInputExample {
public:
    TextInputExample();

    void run();
    vector<int> readFromFile();
    class CountExceededException : public std::exception {
    public:
        const char* what() const noexcept override {
            return "Count exceeded 10.";
        }
    };


private:
    sf::RenderWindow window;
    sf::Font font;
    sf::Text text;
    sf::Text error;
    std::string inputText;
    bool flag = true;
    int count;
   

    void saveToFile(const std::string& filename, const std::string& content);
    void handleTextInput(const sf::Event::TextEvent& textEvent);
    void handleEvents();
    void draw();
};
