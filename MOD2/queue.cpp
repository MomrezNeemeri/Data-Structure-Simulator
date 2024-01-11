#include "Queue.h"
#include <iostream>

    int newElement;
const int WINDOW_WIDTH = 1200;
const int WINDOW_HEIGHT = 900;
const int RECTANGLE_WIDTH = 50;
const int RECTANGLE_HEIGHT = 50;
const int QUEUE_X = 200;
const int QUEUE_Y = 500;
const float MOVEMENT_SPEED = 200.0f;
int counter = 0;

QueueSimulator::QueueSimulator() : window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Queue Simulator") {
    window.setFramerateLimit(500);
    font.loadFromFile("D:/dssim/MOD2/MOD2/fonts/Rough Serif.ttf");

    queueText.setFont(font);
    queueText.setCharacterSize(30);
    queueText.setFillColor(sf::Color::Blue);
    queueText.setPosition(20, 20);




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
    inputBox2.setString("Press Enter to PUSH");

    inputBox3.setFont(font);
    inputBox3.setCharacterSize(30);
    inputBox3.setFillColor(sf::Color::White);
    inputBox3.setPosition(720.f, 150.f);
    inputBox3.setString("Press Delete to POP");


    run();
}
void QueueSimulator::draw() {
    window.clear();

    window.draw(inputBox);
    window.draw(inputBox2);
    window.draw(inputBox3);
    // Draw the entered text
    text.setPosition(200.f, 100.f);
    text.setString(inputText);
    window.draw(text);
   // window.display();
}

void QueueSimulator::run() {

    
    while (window.isOpen()) {

        handleEvents();
        update();
        render();
        draw();
    }
}

void QueueSimulator::handleEvents() {
    sf::Event event;
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            window.close();
        }
        else if (event.type == sf::Event::TextEntered) {
            handleTextInput(event.text);
        }
        else if (event.type == sf::Event::KeyPressed) {
            {
                if (event.key.code == sf::Keyboard::Enter) {
                    //enqueueElement();
                }
                else if (event.key.code == sf::Keyboard::Delete) {
                    if (count > 0)
                        count--;
                   dequeueElement();
                }
            }
        }
    }
}

void QueueSimulator::handleTextInput(const sf::Event::TextEvent& textEvent) {
    if (textEvent.unicode < 128) {
        if (textEvent.unicode == 8 && !inputText.empty()) {
            inputText.pop_back();
        }
        else if (textEvent.unicode == 13) {
            try {
                if (count < 15) {
                  //  saveToFile("output.txt", inputText); // Save to a file when Enter is pressed
                    std::cout << "Entered Integer: " << std::stoi(inputText) << std::endl;
                    count++;
                    newElement = stoi(inputText);
                    inputText.clear();
                    cout << newElement << endl;
                    enqueueElement();
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

void QueueSimulator::update() {
    updateQueueText();
    //updateEnqueueMovement();
    // updateDequeueMovement();
}

void QueueSimulator::render() {
   // window.clear();


    drawQueue();

    //window.draw(movingRectangle);
  //  window.draw(queueText);
    //updateEnqueueMovement();




    window.display();
}

void QueueSimulator::enqueueElement() {

    
    myQueue.push(newElement);
    counter++;

    //Set up the moving rectangle
    movingRectangle.setSize(sf::Vector2f(RECTANGLE_WIDTH, RECTANGLE_HEIGHT));
    movingRectangle.setFillColor(sf::Color::Green);
    movingRectangle.setPosition(0, 0);

    //movementDistance = QUEUE_Y;
    //pushAnimationClock.restart();
}

void QueueSimulator::dequeueElement() {
    if (!myQueue.empty()) {
        int dequeuedElement = myQueue.front();
        myQueue.pop();

        // Set up the moving rectangle for dequeue animation
        // movingRectangle.setSize(sf::Vector2f(RECTANGLE_WIDTH, RECTANGLE_HEIGHT));
        // movingRectangle.setFillColor(sf::Color::Green);
        // movingRectangle.setPosition(QUEUE_X, QUEUE_Y);
        // movementDistance = WINDOW_WIDTH;
        // popAnimationClock.restart();
    }
}

void QueueSimulator::drawQueue() {
    int startX = QUEUE_X;

    std::queue<int> tempQueue = myQueue;


    //if (!tempQueue.empty()) {
    //    tempQueue.pop();
    //}

    while (!tempQueue.empty()) {
        sf::RectangleShape rectangle(sf::Vector2f(RECTANGLE_WIDTH, RECTANGLE_HEIGHT));
        rectangle.setFillColor(sf::Color::Blue);
        rectangle.setPosition(startX, QUEUE_Y);
        window.draw(rectangle);

        // Draw text on the rectangles
        sf::Text text;
        text.setFont(font);
        text.setCharacterSize(15);
        text.setFillColor(sf::Color::Black);
        text.setPosition(startX + RECTANGLE_WIDTH / 2 - 5, QUEUE_Y + RECTANGLE_HEIGHT / 2 - 10);
        text.setString(std::to_string(tempQueue.front()));
        window.draw(text);

        tempQueue.pop();
        startX += RECTANGLE_WIDTH + 5;
    }
}

void QueueSimulator::updateQueueText() {
    std::string queueContent = "Queue Content: ";
    std::queue<int> tempQueue = myQueue;

    while (!tempQueue.empty()) {
        queueContent += std::to_string(tempQueue.front()) + " ";
        tempQueue.pop();
    }

    queueText.setString(queueContent);
}

//void QueueSimulator::updateEnqueueMovement() {
//    if (!myQueue.empty()) {

//        string s = to_string(myQueue.back());

//        cout << s << endl;


//        Text a;
//        a.setFont(font);
//        a.setCharacterSize(15);
//        a.setFillColor(Color::Red);
//        a.setString(s);

//        cout << movementDistance << endl;
//        if (movementDistance > QUEUE_X) {
//            float deltaTime = pushAnimationClock.restart().asSeconds();
//            movementDistance -= MOVEMENT_SPEED * deltaTime;
//            //cout << deltaTime << endl;
//            movingRectangle.setPosition(movementDistance-60, QUEUE_Y);
//        }

//        a.setPosition(movingRectangle.getPosition().x + 15, movingRectangle.getPosition().y);
//        //a.setPosition(300,300);
//        window.draw(a);

//    }


//}


void QueueSimulator::updateEnqueueMovement() {

    int startX = QUEUE_X;
    if (!myQueue.empty()) {
        string s = to_string(myQueue.back());

        cout << s << endl;

        Text a;
        a.setFont(font);
        a.setCharacterSize(15);
        a.setFillColor(Color::Red);
        a.setString(s);

        startX += (RECTANGLE_WIDTH + 5) * counter;


        //cout << startX << endl;





        if (movementDistance >= 0) {
            float deltaTime = pushAnimationClock.restart().asSeconds();
            movementDistance -= MOVEMENT_SPEED * deltaTime;
            movingRectangle.setPosition(startX - 55, QUEUE_Y);
        }





        a.setPosition(movingRectangle.getPosition().x + 15, movingRectangle.getPosition().y);
        //a.setPosition(startX - 50, QUEUE_Y);
        cout << a.getPosition().x << endl;
        window.clear();
        window.draw(a);
        window.display();
    }
}



// void QueueSimulator::updateDequeueMovement() {
//     if (movementDistance < QUEUE_X) {
//         float deltaTime = popAnimationClock.restart().asSeconds();
//         movementDistance += MOVEMENT_SPEED * deltaTime;
//         movingRectangle.setPosition(movementDistance, QUEUE_Y);
//     }
// }

