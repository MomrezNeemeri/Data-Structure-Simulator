#include "Deque.h"


using namespace std;

using namespace sf;

const int WINDOW_WIDTH = 1200;
const int WINDOW_HEIGHT = 900;
const int RECTANGLE_WIDTH = 50;
const int RECTANGLE_HEIGHT = 50;
const int DEQUE_X = 200;
const int DEQUE_Y = 500;
const float MOVEMENT_SPEED = 5.0f;

int newelement;
DequeSimulator::DequeSimulator() : window(VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Deque Simulator") {
    window.setFramerateLimit(500);
    font.loadFromFile("D:/dssim/MOD2/MOD2/fonts/Rough Serif.ttf");


    text.setFont(font);
    text.setCharacterSize(30);
    text.setFillColor(sf::Color::White);

    inputBox.setFont(font);
    inputBox.setCharacterSize(30);
    inputBox.setFillColor(sf::Color::White);
    inputBox.setPosition(20.f, 100.f);
    inputBox.setString("Input: ");

    inputBox2.setFont(font);
    inputBox2.setCharacterSize(30);
    inputBox2.setFillColor(sf::Color::White);
    inputBox2.setPosition(720.f, 100.f);
    inputBox2.setString("Press Enter to PUSHBACK");

    inputBox3.setFont(font);
    inputBox3.setCharacterSize(30);
    inputBox3.setFillColor(sf::Color::White);
    inputBox3.setPosition(720.f, 150.f);
    inputBox3.setString("Press TAB to PUSHFRONT");

    inputBox4.setFont(font);
    inputBox4.setCharacterSize(30);
    inputBox4.setFillColor(sf::Color::White);
    inputBox4.setPosition(720.f, 200.f);
    inputBox4.setString("Press BACKSPACE to POPFRONT");

    inputBox5.setFont(font);
    inputBox5.setCharacterSize(30);
    inputBox5.setFillColor(sf::Color::White);
    inputBox5.setPosition(720.f, 250.f);
    inputBox5.setString("Press DELETE to POPBACK");

    run();
}

void DequeSimulator::draw() {
    window.clear();

    window.draw(inputBox);
    window.draw(inputBox2);
    window.draw(inputBox3);
    window.draw(inputBox4);
    window.draw(inputBox5);
    // Draw the entered text
    text.setPosition(200.f, 100.f);
    text.setString(inputText);
    window.draw(text);
    // window.display();
}

void DequeSimulator::run() {


    while (window.isOpen()) {

        handleEvents();
        update();
        render();
        draw();
    }
}

void DequeSimulator::handleEvents() {
    Event event;
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            window.close();
        }
        else if (event.type == sf::Event::TextEntered) {
            handleTextInput(event.text);
        }
        else if (event.type == sf::Event::KeyPressed) {
            
            if (event.key.code == Keyboard::Enter) {
               // pushBackElement();
            }
            else if (event.key.code == Keyboard::Insert) {
              //  pushFrontElement();
            }
            else if (event.key.code == Keyboard::Delete) {
                popBackElement();
            }
            else if (event.key.code == Keyboard::Backspace) {
                popFrontElement();
            }
        }
    }
}

void DequeSimulator::handleTextInput(const sf::Event::TextEvent& textEvent) {
    if (textEvent.unicode < 128) {
        if (textEvent.unicode == 8 && !inputText.empty()) {
            inputText.pop_back();
        }
        else if (textEvent.unicode == 13|| textEvent.unicode == 9) {
            try {
                if (count < 15) {
                    //  saveToFile("output.txt", inputText); // Save to a file when Enter is pressed
                    std::cout << "Entered Integer: " << std::stoi(inputText) << std::endl;
                    count++;
                    newelement = stoi(inputText);
                    inputText.clear();
                    cout << newelement << endl;
                    if (textEvent.unicode == 13)
                        pushBackElement();
                    else
                        pushFrontElement();
                }
                else {
                    // Throw CountExceededException when count is greater than or equal to 10
                    inputBox.setString("limit_exceed");
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
void DequeSimulator::update() {
    updateDequeText();
    // updatePushBackMovement();
    // updatePushFrontMovement();
    // updatePopBackMovement();
    // updatePopFrontMovement();
}

void DequeSimulator::render() {
   // window.clear();

    // Draw the deque
    drawDeque();

    // Draw the deque text
   // window.draw(dequeText);

    // Draw the moving rectangle
    // window.draw(movingRectangle);

    window.display();
}

void DequeSimulator::pushBackElement() {
    int newElement = rand() % 100; // Generate a random element
    myDeque.push_back(newelement);

    // Set up the moving rectangle
    // movingRectangle.setSize(Vector2f(RECTANGLE_WIDTH, RECTANGLE_HEIGHT));
    // movingRectangle.setFillColor(Color::Red);
    // movingRectangle.setPosition(WINDOW_WIDTH, DEQUE_Y);

    // movementDistance = DEQUE_Y;
    // pushBackAnimationClock.restart();
}

void DequeSimulator::pushFrontElement() {
    int newElement = rand() % 100; // Generate a random element
    myDeque.push_front(newelement);

    // Set up the moving rectangle for push_front animation
    // movingRectangle.setSize(Vector2f(RECTANGLE_WIDTH, RECTANGLE_HEIGHT));
    // movingRectangle.setFillColor(Color::Red);
    // movingRectangle.setPosition(DEQUE_X, DEQUE_Y);
    // movementDistance = WINDOW_WIDTH;
    // pushFrontAnimationClock.restart();
}

void DequeSimulator::popBackElement() {
    if (!myDeque.empty()) {
        myDeque.pop_back();

        // Set up the moving rectangle for pop_back animation
        // movingRectangle.setSize(Vector2f(RECTANGLE_WIDTH, RECTANGLE_HEIGHT));
        // movingRectangle.setFillColor(Color::Red);
        // movingRectangle.setPosition(WINDOW_WIDTH, DEQUE_Y);
        // movementDistance = DEQUE_Y;
        // popBackAnimationClock.restart();
    }
}

void DequeSimulator::popFrontElement() {
    if (!myDeque.empty()) {
        myDeque.pop_front();

        // Set up the moving rectangle for pop_front animation
        // movingRectangle.setSize(Vector2f(RECTANGLE_WIDTH, RECTANGLE_HEIGHT));
        // movingRectangle.setFillColor(Color::Red);
        // movingRectangle.setPosition(DEQUE_X, DEQUE_Y);
        // movementDistance = WINDOW_WIDTH;
        // popFrontAnimationClock.restart();
    }
}

void DequeSimulator::drawDeque() {
    int startX = DEQUE_X;

    // Create a temporary deque for iteration without modifying the original deque
    std::deque<int> tempDeque = myDeque;

    while (!tempDeque.empty()) {
        RectangleShape rectangle(Vector2f(RECTANGLE_WIDTH, RECTANGLE_HEIGHT));
        rectangle.setFillColor(Color::Green);
        rectangle.setPosition(startX, DEQUE_Y);
        window.draw(rectangle);

        // Draw text on the rectangles
        Text text;
        text.setFont(font);
        text.setCharacterSize(15);
        text.setFillColor(Color::Black);
        text.setPosition(startX + RECTANGLE_WIDTH / 2 - 5, DEQUE_Y + RECTANGLE_HEIGHT / 2 - 10);
        text.setString(std::to_string(tempDeque.front()));
        window.draw(text);

        tempDeque.pop_front(); // Move to the next element
        startX += RECTANGLE_WIDTH + 5; // Add some space between rectangles
    }
}

void DequeSimulator::updateDequeText() {
    std::string dequeContent = "Deque Content: ";
    std::deque<int> tempDeque = myDeque;

    while (!tempDeque.empty()) {
        dequeContent += std::to_string(tempDeque.front()) + " ";
        tempDeque.pop_front();
    }

    //dequeText.setString(dequeContent);
}

// void DequeSimulator::updatePushBackMovement() {
//     if (movementDistance > DEQUE_X) {
//         float deltaTime = pushBackAnimationClock.restart().asSeconds();
//         movementDistance -= MOVEMENT_SPEED * deltaTime;
//         movingRectangle.setPosition(movementDistance, DEQUE_Y);
//     }
// }

// void DequeSimulator::updatePushFrontMovement() {
//     if (movementDistance < DEQUE_X) {
//         float deltaTime = pushFrontAnimationClock.restart().asSeconds();
//         movementDistance += MOVEMENT_SPEED * deltaTime;
//         movingRectangle.setPosition(movementDistance, DEQUE_Y);
//     }
// }

// void DequeSimulator::updatePopBackMovement() {
//     if (movementDistance > DEQUE_X) {
//         float deltaTime = popBackAnimationClock.restart().asSeconds();
//         movementDistance -= MOV
