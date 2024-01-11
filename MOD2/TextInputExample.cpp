#include "TextInputExample.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include"ballmoving.h"
using namespace sf;
using namespace std;
TextInputExample::TextInputExample()
{

}
TextInputExample::TextInputExample(RenderWindow* win1)
{
    if (win1 == nullptr) {
        throw std::invalid_argument("Null pointer provided for RenderWindow");
    }
    
    if (!font.loadFromFile("D:/dssim/MOD2/MOD2/fonts/Rough Serif.ttf")) {
        std::cerr << "Error loading font file." << std::endl;
    }

    text.setFont(font);
    text.setCharacterSize(30);
    text.setFillColor(sf::Color::White);

    inputBox.setFont(font);
    inputBox.setCharacterSize(30);
    inputBox.setFillColor(sf::Color::White);
    inputBox.setPosition(20.f, 500.f);
    inputBox.setString("Input: ");
}

void TextInputExample::run(RenderWindow& window) {
     count = 0;
    std::ofstream file("output.txt", std::ios::ate);
    error.setFont(font);
    error.setFillColor(Color::Color(255, 222, 173));
    error.setString("error");
    error.setCharacterSize(40);
    error.setPosition(100,100);

    while (window.isOpen() && flag) {
        handleEvents(window);
        draw(window);
    }

}

void TextInputExample::handleEvents(RenderWindow& window) {
    sf::Event event;
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            window.close();
        }
        else if (event.type == sf::Event::TextEntered) {
            handleTextInput(event.text);
        }
        else if (event.type == sf::Event::KeyPressed) {
            if (event.key.code == sf::Keyboard::Escape || count==10) {
                
                window.close();
                ballmoving ball2;
                ball2.run();
            }
        }
    }
}

void TextInputExample::draw(RenderWindow& window) {
    window.clear();

    window.draw(inputBox);

    // Draw the entered text
    text.setPosition(200.f, 500.f);
    text.setString(inputText);
    window.draw(text);
    window.display();
}

void TextInputExample::handleTextInput(const sf::Event::TextEvent& textEvent) {
    if (textEvent.unicode < 128) {
        if (textEvent.unicode == 8 && !inputText.empty()) {
            inputText.pop_back();
        }
        else if (textEvent.unicode == 13) {
            try {
                if (count < 10) {
                    saveToFile("output.txt", inputText); // Save to a file when Enter is pressed
                    std::cout << "Entered Integer: " << std::stoi(inputText) << std::endl;
                    count++;
                inputText.clear();
                }
                else {
                    // Throw CountExceededException when count is greater than or equal to 10
                    throw CountExceededException();

                }
            }
            catch (const CountExceededException& e) {
                std::cerr << "Error: " << e.what() << std::endl;
                return;
            }
            catch (const std::exception& e) {
                std::cerr << "Error: " << e.what() << std::endl;
            }
        }
        else {
            inputText += static_cast<char>(textEvent.unicode);
        }

        text.setString(inputText);
    }
}

void TextInputExample::saveToFile(const std::string& filename, const std::string& content) {
    std::ofstream file(filename, std::ios::app); // Open in append mode
    if (file.is_open()) {
        try {
            int value = std::stoi(content);
            file << value << std::endl; // Append the new integer value and add a newline
            std::cout << "Integer appended to file: " << filename << std::endl;
        }
        catch (const std::invalid_argument& e) {
            std::cerr << "Invalid input for conversion to integer: " << content << std::endl;
        }
        file.close();
    }
    else {
        std::cerr << "Unable to open file: " << filename << std::endl;
    }
}
