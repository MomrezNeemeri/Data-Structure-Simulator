#include "Heapsort.h"

HeapSortSimulation::HeapSortSimulation(const std::vector<int>& list)
    : window(sf::VideoMode(800, 600), "Heap Sort Simulation"), array(list) {
    font.loadFromFile("D:/dssim/MOD2/MOD2/fonts/Rough Serif.ttf");
    text.setFont(font);
    text.setCharacterSize(24);
    text.setFillColor(sf::Color::White);

    currentIteration = array.size() - 1;
    isSorting = true;

    separatorLine.setSize(sf::Vector2f(1, 400));
    separatorLine.setPosition(array.size() * 60 + 45, 100);
    separatorLine.setFillColor(sf::Color::Yellow);
}

void HeapSortSimulation::run() {
    while (window.isOpen()) {
        handleEvents();
        update();
        render();
    }
}

void HeapSortSimulation::handleEvents() {
    sf::Event event;
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            window.close();
        }
        else if (event.type == sf::Event::KeyPressed) {
            if (event.key.code == sf::Keyboard::Space) {
                if (isSorting) {
                    performHeapSortStep();
                }
            }
        }
    }
}

void HeapSortSimulation::update() {
    // Update logic if needed
}

void HeapSortSimulation::render() {
    window.clear();

    int xPos = 50;
    for (int value : array) {
        drawRectangle(xPos, 400 - value * 3, 50, value * 3);
        drawBox(xPos, 410, 50, 45);
        drawSortName("Heap Sort :", 50, 50, sf::Color::White);
        drawText(std::to_string(value), xPos + 10, 416, sf::Color::Red);
        drawSortUp("Maximum value is separated", 470, 100, sf::Color::Yellow);
        drawSortDown("out from the Max Heap", 495, 125, sf::Color::Yellow);
        drawSortDown("Sorted Part", 495, 500, sf::Color::Yellow);
        xPos += 60;
    }

    window.draw(separatorLine);

    window.display();
}

void HeapSortSimulation::drawSortUp(const std::string& str, float x, float y, const sf::Color& color) {
    text.setString(str);
    text.setPosition(x, y);
    text.setFillColor(color);
    window.draw(text);
}

void HeapSortSimulation::drawSortDown(const std::string& str, float x, float y, const sf::Color& color) {
    text.setString(str);
    text.setPosition(x, y);
    text.setFillColor(color);
    window.draw(text);
}

void HeapSortSimulation::drawBox(float x, float y, float width, float height) {
    sf::RectangleShape rectangle(sf::Vector2f(width, height));
    rectangle.setPosition(x, y);
    rectangle.setFillColor(sf::Color::Green);
    window.draw(rectangle);
}

void HeapSortSimulation::drawRectangle(float x, float y, float width, float height) {
    sf::RectangleShape rectangle(sf::Vector2f(width, height));
    rectangle.setPosition(x, y);
    rectangle.setFillColor(sf::Color::Blue);
    window.draw(rectangle);
}

void HeapSortSimulation::drawSortName(const std::string& str, float x, float y, const sf::Color& color) {
    text.setString(str);
    text.setPosition(x, y);
    text.setFillColor(color);
    window.draw(text);
}

void HeapSortSimulation::drawText(const std::string& str, float x, float y, const sf::Color& color) {
    text.setString(str);
    text.setPosition(x, y);
    text.setFillColor(color);
    window.draw(text);
}

void HeapSortSimulation::performHeapSortStep() {
    if (currentIteration <= 0) {
        isSorting = false;
        return;
    }

    for (int i = 0; i < currentIteration; ++i) {
        if (array[i] > array[i + 1]) {
            std::swap(array[i], array[i + 1]);
        }
    }

    currentIteration--;

    separatorLine.setPosition(45 + (currentIteration + 1) * 60, 100);

    sf::sleep(sf::milliseconds(500));
}

