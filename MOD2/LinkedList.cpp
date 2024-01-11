#include "LinkedList.h"





L_Node::L_Node(int value) : data(value), next(nullptr) {}

LinkedListSimulator::LinkedListSimulator() : window(VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Linked List Simulator") {
    window.setFramerateLimit(500);
    font.loadFromFile("D:/dssim/MOD2/MOD2/fonts/Rough Serif.ttf");

    listText.setFont(font);
    listText.setCharacterSize(20);
    listText.setFillColor(Color::Blue);
    listText.setPosition(20, 20);

    run();
}

void LinkedListSimulator::run() {
    while (window.isOpen()) {
        handleEvents();
        update();
        render();
    }
}


void LinkedListSimulator::handleEvents() {
    Event event;
    while (window.pollEvent(event)) {
        if (event.type == Event::Closed) {
            window.close();
        }

        if (event.type == Event::KeyPressed) {
            if (event.key.code == Keyboard::I) {
                insertFrontElement();
            }
            else if (event.key.code == Keyboard::E) {
                insertEndElement();
            }
            else if (event.key.code == Keyboard::D) {
                deleteFrontElement();
            }
            else if (event.key.code == Keyboard::X) {
                deleteEndElement();
            }
            else if (event.key.code == Keyboard::M) {
                insertMiddleElement();
            }
        }
    }
}

void LinkedListSimulator::update() {
    updateListText();
}

void LinkedListSimulator::render() {
    window.clear();

    // Draw the linked list
    drawList();

    // Draw the list text
    window.draw(listText);



    window.display();
}

void LinkedListSimulator::insertFrontElement() {
    int newElement = rand() % 100; // Generate a random element
    L_Node* newL_Node = new L_Node(newElement);
    newL_Node->next = head;
    head = newL_Node;



}

void LinkedListSimulator::insertEndElement() {
    int newElement = rand() % 100;
    L_Node* newL_Node = new L_Node(newElement);

    if (head == nullptr) {
        head = newL_Node;
    }
    else {
        L_Node* current = head;
        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = newL_Node;
    }



}

void LinkedListSimulator::insertMiddleElement() {
    int newElement = rand() % 100;
    L_Node* newL_Node = new L_Node(newElement);

    int position;
    cout << "Enter the position to insert (1-based index): ";
    cin >> position;

    if (position <= 0) {
        cout << "Invalid position. Position should be a positive integer." << endl;
        return;
    }

    if (position == 1) {
        newL_Node->next = head;
        head = newL_Node;
        return;
    }

    L_Node* current = head;
    int currentPosition = 1;

    while (current != nullptr && currentPosition < position - 1) {
        current = current->next;
        currentPosition++;
    }

    if (current != nullptr) {
        newL_Node->next = current->next;
        current->next = newL_Node;
    }
    else {
        cout << "Invalid position. Position exceeds the length of the linked list." << endl;
    }



}

void LinkedListSimulator::deleteFrontElement() {
    if (head != nullptr) {
        L_Node* temp = head;
        head = head->next;
        delete temp;



    }
}

void LinkedListSimulator::deleteEndElement() {
    if (head != nullptr) {
        if (head->next == nullptr) {
            delete head;
            head = nullptr;
        }
        else {
            L_Node* current = head;
            while (current->next->next != nullptr) {
                current = current->next;
            }
            delete current->next;
            current->next = nullptr;
        }



    }
}

void LinkedListSimulator::drawList() {
    int startX = LIST_X;
    int uniqueAddress = reinterpret_cast<int>(head);

    L_Node* current = head;

    while (current != nullptr) {
        // Draw the first rectangle
        RectangleShape firstRectangle(Vector2f(RECTANGLE_WIDTH, RECTANGLE_HEIGHT));
        firstRectangle.setFillColor(Color::Yellow);
        firstRectangle.setPosition(startX, LIST_Y);
        window.draw(firstRectangle);

        // Draw text on the first rectangle
        Text firstText;
        firstText.setFont(font);
        firstText.setCharacterSize(15);
        firstText.setFillColor(Color::Black);
        firstText.setPosition(startX + RECTANGLE_WIDTH / 2 - 5, LIST_Y + RECTANGLE_HEIGHT / 2 - 10);
        firstText.setString(to_string(current->data));
        window.draw(firstText);

        // Draw the second rectangle (for the next address)
        RectangleShape secondRectangle(Vector2f(RECTANGLE_WIDTH, RECTANGLE_HEIGHT));
        secondRectangle.setFillColor(Color::Green);
        secondRectangle.setPosition(startX + RECTANGLE_WIDTH + DIVIDER_WIDTH, LIST_Y);
        window.draw(secondRectangle);

        // Draw text on the second rectangle (for the next address)
        Text secondText;
        secondText.setFont(font);
        secondText.setCharacterSize(15);
        secondText.setFillColor(Color::Black);
        secondText.setPosition(startX + RECTANGLE_WIDTH + DIVIDER_WIDTH + RECTANGLE_WIDTH / 2 - 15, LIST_Y + RECTANGLE_HEIGHT / 2 - 10);
        int nextAddress = reinterpret_cast<int>(current->next); // Get the unique address for the next L_Node
        secondText.setString(formatAddress(nextAddress));
        window.draw(secondText);


        if (current->next != nullptr) {
            int nextStartX = startX + RECTANGLE_WIDTH + DIVIDER_WIDTH + RECTANGLE_WIDTH + 50;
            int nextNextAddress = reinterpret_cast<int>(current->next->next);
            drawArrow(startX + RECTANGLE_WIDTH + DIVIDER_WIDTH + RECTANGLE_WIDTH, LIST_Y + RECTANGLE_HEIGHT / 2,
                nextStartX, LIST_Y + RECTANGLE_HEIGHT / 2, Color::Cyan);

        }

        current = current->next; // Move to the next element
        startX += RECTANGLE_WIDTH + DIVIDER_WIDTH + RECTANGLE_WIDTH + 50; // Add some space between rectangles
    }
}

void LinkedListSimulator::updateListText() {
    string listContent = "Linked List Content: ";
    L_Node* current = head;

    while (current != nullptr) {
        listContent += to_string(current->data) + " ";
        current = current->next;
    }

    listText.setString(listContent);
}

void LinkedListSimulator::drawArrow(float startX, float startY, float endX, float endY, Color color = Color::Black) {
    float angle = atan2(endY - startY, endX - startX);
    float arrowLength = 20.0f;

    // Draw the line
    Vertex line[] = {
        Vertex(Vector2f(startX, startY)),
        Vertex(Vector2f(endX , endY))
    };
    line[0].color = color;
    line[1].color = color;
    window.draw(line, 2, Lines);

    // Draw the arrowhead
    Vertex arrowhead[] = {
        Vertex(Vector2f(endX, endY)),
        Vertex(Vector2f(endX - arrowLength * cos(angle - 3.1416 / 6), endY - arrowLength * sin(angle - 3.1416 / 6))),
        Vertex(Vector2f(endX - arrowLength * cos(angle + 3.1416 / 6), endY - arrowLength * sin(angle + 3.1416 / 6)))
    };
    for (int i = 0; i < 3; ++i) {
        arrowhead[i].color = color;
    }
    window.draw(arrowhead, 3, TriangleFan);
}

string LinkedListSimulator::formatAddress(int address) {
    // Format the address to be six characters long and nonnegative
    stringstream ss;
    ss << std::hex << (address & 0xFFFFFF); // Use only the last 24 bits for better visibility
    return ss.str();
}


