#pragma once

#include <SFML/Graphics.hpp>
#include<iostream>
#include "DataStructure.h"

using namespace std;
using namespace sf;



struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int value) : data(value), left(nullptr), right(nullptr) {}
};

class BinaryTree : public DataStructureSimulator {
public:
    class CountExceededException : public std::exception {
    public:
        const char* what() const noexcept override {
            return "Count exceeded 15.";
        }
    };
    BinaryTree();
    void insert(int value);
    void draw(sf::RenderWindow& window, float x, float y, float xOffset, float yOffset);
    void handleInput(sf::Event event,RenderWindow&window);
    void render(BinaryTree& bst, float x, float y, float xOffset, float yOffset);
    void handleTextInput(const sf::Event::TextEvent& textEvent,RenderWindow&window);
private:
    Node* root;
    sf::Font font;

    Node* insertRecursive(Node* root, int value);
    void drawRecursive(sf::RenderWindow& window, Node* root, float x, float y, float xOffset, float yOffset);
    void drawLine(sf::RenderWindow& window, float x1, float y1, float x2, float y2);
    void draw();


    Text text;
    Text inputBox;
    Text inputBox2;
    Text inputBox3;
    string inputText;
    int count;
};

