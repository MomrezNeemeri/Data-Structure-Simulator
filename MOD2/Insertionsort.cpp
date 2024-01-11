#include "Insertionsort.h"

InsertionSortSimulation::InsertionSortSimulation(const std::vector<int>& list)
    : window(sf::VideoMode(800, 600), "Insertion Sort Simulation"), array(list) {
    font.loadFromFile("D:/dssim/MOD2/MOD2/fonts/Rough Serif.ttf");
    text.setFont(font);
    text.setCharacterSize(24);
    text.setFillColor(sf::Color::White);

    currentIndex = 1; // Start with the second element for insertion sort
    isSorting = true;
}

void InsertionSortSimulation::run() {
    while (window.isOpen()) {
        handleEvents();
        update();
        render();
    }
}

void InsertionSortSimulation::handleEvents() {
    sf::Event event;
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            window.close();
        }
        else if (event.type == sf::Event::KeyPressed) {
            if (event.key.code == sf::Keyboard::Space) {
                if (isSorting) {
                    performInsertionSortStep();
                }
            }
        }
    }
}

void InsertionSortSimulation::update() {
    // Update logic if needed
}

void InsertionSortSimulation::render() {
    window.clear();

    int xPos = 50;
    for (int value : array) {
        drawRectangle(xPos, 400 - value * 3, 50, value * 3);
        drawBox(xPos, 410, 50, 45);
        drawSortName("Insertion Sort :", 50, 50, sf::Color::White);
        drawText(std::to_string(value), xPos + 10, 416, sf::Color::Red);
        drawSorted("Sorted", 10, 100, sf::Color::Yellow);
        drawUnsorted("Unsorted", 600, 100, sf::Color::Yellow);
        xPos += 60;
    }

    drawSeparator(currentIndex * 60 + 45);

    window.display();
}

void InsertionSortSimulation::drawSorted(const std::string& str, float x, float y, const sf::Color& color) {
    text.setString(str);
    text.setPosition(x, y);
    text.setFillColor(color);
    window.draw(text);
}

void InsertionSortSimulation::drawUnsorted(const std::string& str, float x, float y, const sf::Color& color) {
    text.setString(str);
    text.setPosition(x, y);
    text.setFillColor(color);
    window.draw(text);
}

void InsertionSortSimulation::drawBox(float x, float y, float width, float height) {
    sf::RectangleShape rectangle(sf::Vector2f(width, height));
    rectangle.setPosition(x, y);
    rectangle.setFillColor(sf::Color::Green);
    window.draw(rectangle);
}

void InsertionSortSimulation::drawRectangle(float x, float y, float width, float height) {
    sf::RectangleShape rectangle(sf::Vector2f(width, height));
    rectangle.setPosition(x, y);
    rectangle.setFillColor(sf::Color::Blue);
    window.draw(rectangle);
}

void InsertionSortSimulation::drawSortName(const std::string& str, float x, float y, const sf::Color& color) {
    text.setString(str);
    text.setPosition(x, y);
    text.setFillColor(color);
    window.draw(text);
}

void InsertionSortSimulation::drawText(const std::string& str, float x, float y, const sf::Color& color) {
    text.setString(str);
    text.setPosition(x, y);
    text.setFillColor(color);
    window.draw(text);
}

void InsertionSortSimulation::drawSeparator(float x) {
    sf::Vertex separator[] = {
        sf::Vertex(sf::Vector2f(x, 100), sf::Color::Yellow),
        sf::Vertex(sf::Vector2f(x, 500), sf::Color::Yellow)
    };

    window.draw(separator, 2, sf::Lines);
}

void InsertionSortSimulation::performInsertionSortStep() {
    if (currentIndex >= array.size()) {
        isSorting = false;
        return;
    }

    int key = array[currentIndex];
    int j = currentIndex - 1;

    while (j >= 0 && array[j] > key) {
        array[j + 1] = array[j];
        --j;
    }

    array[j + 1] = key;



    ++currentIndex;

    sf::sleep(sf::milliseconds(500));
}


