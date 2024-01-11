#pragma once

#include <SFML/Graphics.hpp>
#include<iostream>
#include<stdexcept>
using namespace std;
using namespace sf;

class TextInputExample {
public:
    TextInputExample();
    TextInputExample(RenderWindow* win1);


    void run(RenderWindow& window);
    class CountExceededException : public std::exception {
    public:
        const char* what() const noexcept override {
            return "Count exceeded 10.";
        }
    };

private:
    sf::RenderWindow window1;
    sf::Font font;
    sf::Text text;
    sf::Text error;
    Text inputBox;
    std::string inputText;
    bool flag = true;
    int count;

    void saveToFile(const std::string& filename, const std::string& content);
    void handleTextInput(const sf::Event::TextEvent& textEvent);

    void handleEvents(RenderWindow& window);
    void draw(RenderWindow& win);
};
