#include "BST.h"
#include <iostream>
int b;
BinaryTree::BinaryTree() : root(nullptr) {
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
}

void BinaryTree::insert(int value) {
    root = insertRecursive(root, value);
}

void BinaryTree::draw(sf::RenderWindow& window, float x, float y, float xOffset, float yOffset) {
    drawRecursive(window, root, x, y, xOffset, yOffset);
}

void BinaryTree::handleInput(sf::Event event,RenderWindow& window) {
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            window.close();
        }
        else if (event.type == sf::Event::TextEntered) {
            handleTextInput(event.text,window);
        }
        else if (event.type == sf::Event::KeyPressed) {
            {
                if (event.key.code == sf::Keyboard::Enter) {
                }
            }
        }
    /*if (event.type == sf::Event::KeyPressed) {
        if (event.key.code == sf::Keyboard::Space) {
            int x;
            cout << "Enter the value in BST : " << endl;
            cin >> x;
            int value = x;
            std::cout << "Inserting value: " << value << std::endl;
            insert(value);
        }*/
    }
}

    void BinaryTree::handleTextInput(const sf::Event::TextEvent & textEvent,RenderWindow&window) {
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
                        b = stoi(inputText);
                        inputText.clear();
                        cout << b << endl;
                        insert(b);
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

Node* BinaryTree::insertRecursive(Node* root, int value) {
    if (root == nullptr) {
        return new Node(value);
    }

    if (value < root->data) {
        root->left = insertRecursive(root->left, value);
    }
    else if (value > root->data) {
        root->right = insertRecursive(root->right, value);
    }

    return root;
}

void BinaryTree::drawRecursive(sf::RenderWindow& window, Node* root, float x, float y, float xOffset, float yOffset) {
    if (root != nullptr) {
        sf::CircleShape circle(20);
        circle.setFillColor(sf::Color::White);
        circle.setOutlineColor(sf::Color::Black);
        circle.setOutlineThickness(2);
        circle.setPosition(x, y);
        window.draw(circle);

        int n = root->data;
        std::string s = std::to_string(n);

        sf::Text text;
        text.setFont(font);
        text.setString(s);
        text.setCharacterSize(20);
        text.setFillColor(sf::Color::Red);
        text.setPosition(x + 5, y + 5);
        window.draw(text);

        if (root->left != nullptr) {
            drawRecursive(window, root->left, x - xOffset, y + yOffset, xOffset / 2, yOffset);
            drawLine(window, x, y, x - xOffset, y + yOffset);
        }

        if (root->right != nullptr) {
            drawRecursive(window, root->right, x + xOffset, y + yOffset, xOffset / 2, yOffset);
            drawLine(window, x, y, x + xOffset, y + yOffset);
        }
    }
}

void BinaryTree::drawLine(sf::RenderWindow& window, float x1, float y1, float x2, float y2) {
    sf::Vertex line[] = {
        sf::Vertex(sf::Vector2f(x1 + 20, y1 + 20)),
        sf::Vertex(sf::Vector2f(x2 + 20, y2 + 20))
    };

    window.draw(line, 2, sf::Lines);
}

void BinaryTree::render(BinaryTree& bst, float x, float y, float xOffset, float yOffset) {
    sf::RenderWindow window(sf::VideoMode(1200, 900), "BST Insertion Simulation");
    window.setFramerateLimit(60);

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }

            bst.handleInput(event,window);
        }

        // Perform any additional update logic here if needed

        window.clear(sf::Color::Green);
        window.draw(inputBox);
        window.draw(inputBox2);
       // window.draw(inputBox3);
        // Draw the entered text
        text.setPosition(200.f, 100.f);
        text.setString(inputText);
        window.draw(text);
        bst.draw(window, x, y, xOffset, yOffset);
        window.display();
    }
}

