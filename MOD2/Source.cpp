#include <SFML/Graphics.hpp>
#include"ballmoving.h"
#include"bg.h"
#include"mainmenu.h"
#include"TextInputExample.h"
#include"queue.h"
#include"stack.h"
#include"Deque.h"
#include"LinkedList.h"
#include"BST.h"
#include"Insertionsort.h"
#include"Heapsort.h"
#include"bubblesort.h"

using namespace std;
using namespace sf;

int main() {
    Sprite backmenu;
    Event menuevent;
    RenderWindow menu(VideoMode(1800, 900), "menu");
    MainMenu mainmenu(1800, 1000);

    Texture texmenu;
    if (!texmenu.loadFromFile("texture/back1.jpg")) {
        cout << "Failed to load the background image" << endl;
    }
    backmenu.setTexture(texmenu);
    backmenu.setColor(Color(255, 255, 255, 128));
    while (menu.isOpen())
    {

        while (menu.pollEvent(menuevent))
        {
            if (menuevent.type == Event::Closed)
            {
                menu.close();
            }
            if (menuevent.type == Event::KeyReleased)
            {

                if (menuevent.key.code == Keyboard::Up)
                {


                    mainmenu.MoveUp();

                    break;
                }

                if (menuevent.key.code == Keyboard::Down)
                {
                    mainmenu.MoveDown();

                    break;
                }

                if (menuevent.key.code == Keyboard::Return)
                {
                    int x = mainmenu.MainMenuPressed();
                    if (x == 0)
                    {
                        StackSimulator s1;
                    }

                    if (x == 1)
                    {
                        QueueSimulator q1;
                       

                    }

                    if (x == 2)
                    {
                        LinkedListSimulator l;
                    }

                    if (x == 3)
                    {
                        BinaryTree bt;
                        bt.render(bt, 400, 50, 90, 90);
                    }
                    if (x == 4)
                    {
                        DequeSimulator d;
                    }

                    if (x == 5)
                    {
                        TextInputExample t1;
                        t1.run();
                        vector<int> v1;
                        v1 = t1.readFromFile();
                        BubbleSortSimulation it(v1);
                        it.run();
                    }

                    if (x == 6)
                    {
                        TextInputExample t1;
                        t1.run();
                        vector<int> v1;
                        v1 = t1.readFromFile();
                        InsertionSortSimulation it(v1);
                        it.run();

                    }
                    if (x == 7)
                    {
                        TextInputExample t1;
                        t1.run();
                        vector<int> v1;
                        v1 = t1.readFromFile();
                         HeapSortSimulation it(v1);
                        it.run();
                    }
                }
            }
        }
        menu.draw(backmenu);
        mainmenu.draw(menu);
        menu.display();
    }

    return 0;
}
