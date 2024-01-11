#include "Stack.h"
const int WINDOW_WIDTH = 1200;
const int WINDOW_HEIGHT = 900;
const int RECTANGLE_WIDTH = 50;
const int RECTANGLE_HEIGHT = 20;
const int STACK_X = 400;
const int STACK_Y = 100;
const float MOVEMENT_SPEED = 200.0f;
int s;

StackSimulator::StackSimulator() : window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Stack Simulator") {
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
    inputBox2.setString("Press Enter to PUSH");

    inputBox3.setFont(font);
    inputBox3.setCharacterSize(30);
    inputBox3.setFillColor(sf::Color::White);
    inputBox3.setPosition(720.f, 150.f);
    inputBox3.setString("Press Delete to POP");
    run();
}

void StackSimulator::draw() {
    window.clear();

    window.draw(inputBox);
    window.draw(inputBox2);
    window.draw(inputBox3);
    // Draw the entered text
    text.setPosition(200.f, 100.f);
    text.setString(inputText1);
    window.draw(text);
    // window.display();
}

void StackSimulator::run() {


    while (window.isOpen()) {

        handleEvents();
        update();
        render();
        draw();
    }
}

void StackSimulator::handleEvents() {
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
                    popElement();
                }
            }
        }
    }
}

void StackSimulator::handleTextInput(const sf::Event::TextEvent& textEvent) {
    if (textEvent.unicode < 128) {
        if (textEvent.unicode == 8 && !inputText1.empty()) {
            inputText1.pop_back();
        }
        else if (textEvent.unicode == 13) {
            try {
                if (count < 15) {
                    //  saveToFile("output.txt", inputText); // Save to a file when Enter is pressed
                    std::cout << "Entered Integer: " << std::stoi(inputText1) << std::endl;
                    count++;
                    s = stoi(inputText1);
                    inputText1.clear();
                    cout << s << endl;
                    pushElement();
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
            inputText1 += static_cast<char>(textEvent.unicode);
        }

        text.setString(inputText1);
    }
}









void StackSimulator::update() {
    updateStackText();
    //updatePushMovement();
    //updatePopMovement();
}

void StackSimulator::render() {
   // window.clear();
    drawStack();



    window.draw(movingRectangle);
  //  window.draw(stackText);
    updatePushMovement();
    window.display();
}

void StackSimulator::pushElement() {

   

    
    myStack.push(s);

    movingRectangle.setSize(sf::Vector2f(RECTANGLE_WIDTH, RECTANGLE_HEIGHT));
    movingRectangle.setFillColor(sf::Color::Red);
    movingRectangle.setPosition(STACK_X, WINDOW_HEIGHT);

    movementDistance = WINDOW_HEIGHT;
    pushAnimationClock.restart();
}

void StackSimulator::popElement() {
    if (!myStack.empty()) {
        int poppedElement = myStack.top();
        myStack.pop();

        //movingRectangle.setSize(sf::Vector2f(RECTANGLE_WIDTH, RECTANGLE_HEIGHT));
        //movingRectangle.setFillColor(sf::Color::Blue);
        //movingRectangle.setPosition(STACK_X, STACK_Y);
        //movementDistance = STACK_Y;
        //popAnimationClock.restart();
    }
}

//void StackSimulator::drawStack() {
//    int startY = STACK_Y;
//
//    std::stack<int> tempStack = myStack;
//
//    while (!tempStack.empty()) {
//        sf::RectangleShape rectangle(sf::Vector2f(RECTANGLE_WIDTH, RECTANGLE_HEIGHT));
//        rectangle.setFillColor(sf::Color::Blue);
//        rectangle.setPosition(STACK_X, startY);
//
//        sf::Text text;
//        text.setFont(font);
//        text.setCharacterSize(15);
//        text.setFillColor(sf::Color::White);
//        text.setPosition(STACK_X + RECTANGLE_WIDTH / 2 - 5, startY + RECTANGLE_HEIGHT / 2 - 10);
//        text.setString(std::to_string(tempStack.top()));
//
//        window.draw(rectangle);
//        window.draw(text);
//
//        tempStack.pop();
//        startY += RECTANGLE_HEIGHT + 5;
//    }
//}



void StackSimulator::drawStack() {
    int startY = STACK_Y;
    bool isFirstRectangle = true;  // Flag to check if it's the top rectangle

    std::stack<int> tempStack = myStack;
    if (!tempStack.empty()) {
        tempStack.pop();

    }


    while (!tempStack.empty()) {
        sf::RectangleShape rectangle(Vector2f(RECTANGLE_WIDTH, RECTANGLE_HEIGHT));

        //Use different colors for the top and other rectangles
       //if (isFirstRectangle) {
       //    rectangle.setFillColor(Color::Red);  // Color for the top rectangle
       //    isFirstRectangle = false;
       //}
       //else {
       //    rectangle.setFillColor(Color::Blue);  // Color for other rectangles
       //}

        rectangle.setFillColor(Color::Blue);

        rectangle.setPosition(STACK_X, startY);

        sf::Text text;
        text.setFont(font);
        text.setCharacterSize(15);
        text.setFillColor(Color::White);
        text.setPosition(STACK_X + RECTANGLE_WIDTH / 2 - 5, startY + RECTANGLE_HEIGHT / 2 - 10);
        text.setString(std::to_string(tempStack.top()));

        window.draw(rectangle);
        window.draw(text);

        tempStack.pop();
        startY += RECTANGLE_HEIGHT + 5;
    }
}


void StackSimulator::updateStackText() {
    std::string stackContent = "Stack Content: ";
    std::stack<int> tempStack = myStack;

    while (!tempStack.empty()) {
        stackContent += to_string(tempStack.top()) + " ";
        tempStack.pop();
    }

   // stackText.setString(stackContent);
}

void StackSimulator::updatePushMovement() {

    if (!myStack.empty()) {
        string s = to_string(myStack.top());

        //cout << s << endl;

        Text a;
        a.setFont(font);
        a.setCharacterSize(15);
        a.setFillColor(Color::White);
        a.setString(s);

        //a.setPosition(500,500);

        if (movementDistance > STACK_Y) {
            float deltaTime = pushAnimationClock.restart().asSeconds();
            movementDistance -= MOVEMENT_SPEED * deltaTime;
            movingRectangle.setPosition(STACK_X, movementDistance - 25);



        }
        a.setPosition(movingRectangle.getPosition().x + 15, movingRectangle.getPosition().y);
        window.draw(a);


    }
    else {
        
    }





}

//void StackSimulator::updatePopMovement() {
//    if (movementDistance < STACK_Y) {
//        float deltaTime = popAnimationClock.restart().asSeconds();
//        movementDistance += MOVEMENT_SPEED * deltaTime;
//        movingRectangle.setPosition(STACK_X, movementDistance);
//    }
//}


