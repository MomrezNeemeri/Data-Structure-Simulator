#include "BubbleSort.h"

BubbleSortSimulation::BubbleSortSimulation(const std::vector<int>& list)
    : window(sf::VideoMode(800, 600), "Bubble Sort Simulation"), array(list) {
    font.loadFromFile("D:/dssim/MOD2/MOD2/fonts/Rough Serif.ttf");
    // Make sure to provide a valid font file path
    text.setFont(font);
    text.setCharacterSize(24);
    text.setFillColor(sf::Color::White);

    currentIteration = array.size() - 1;
    isSorting = true;

    run();
}

void BubbleSortSimulation::run() {
    while (window.isOpen()) {
        handleEvents();
        update();
        render();
    }
}

void BubbleSortSimulation::handleEvents() {
    sf::Event event;
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            window.close();
        }
        else if (event.type == sf::Event::KeyPressed) {
            if (event.key.code == sf::Keyboard::Space) {
                if (isSorting) {
                    performBubbleSortStep();
                }
            }
        }
    }
}

void BubbleSortSimulation::update() {
    // Update logic if needed
}

void BubbleSortSimulation::render() {
    window.clear();

    int xPos = 50;
    for (int value : array) {
        drawRectangle(xPos, 400 - value * 3, 50, value * 3);
        drawBox(xPos, 410, 50, 45);
        drawSortName("Bubble Sort :", 50, 50, sf::Color::White);
        drawText(std::to_string(value), xPos + 10, 416, sf::Color::Red);

        xPos += 60;
    }

    window.display();
}

void BubbleSortSimulation::drawBox(float x, float y, float width, float height) {
    sf::RectangleShape rectangle(sf::Vector2f(width, height));
    rectangle.setPosition(x, y);
    rectangle.setFillColor(sf::Color::Green);
    window.draw(rectangle);
}

void BubbleSortSimulation::drawRectangle(float x, float y, float width, float height) {
    sf::RectangleShape rectangle(sf::Vector2f(width, height));
    rectangle.setPosition(x, y);
    rectangle.setFillColor(sf::Color::Blue);
    window.draw(rectangle);
}

void BubbleSortSimulation::drawSortName(const std::string& str, float x, float y, const sf::Color& color) {
    text.setString(str);
    text.setPosition(x, y);
    text.setFillColor(color);
    window.draw(text);
}

void BubbleSortSimulation::drawText(const std::string& str, float x, float y, const sf::Color& color) {
    text.setString(str);
    text.setPosition(x, y);
    text.setFillColor(color);
    window.draw(text);
}

void BubbleSortSimulation::performBubbleSortStep() {
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

    // Delay to make the sorting process visible
    sf::sleep(sf::milliseconds(100));
}

//int main() {
//    std::vector<int> inputArray;
//    int totalnumber;
//    std::cin >> totalnumber;
//    while (totalnumber--) {
//        int i;
//        std::cin >> i;
//        inputArray.push_back(i);
//    }
//    BubbleSortSimulation bubbleSortSim(inputArray);
//    return 0;
//}
