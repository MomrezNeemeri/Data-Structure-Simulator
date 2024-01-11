#include <SFML/Graphics.hpp>
#include"ballmoving.h"
#include"bg.h"
#include"mainmenu.h"
#include"TextInputExample.h"
#include"queue.h"

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
                        ballmoving ball1;
                        ball1.run();
                    }

                    if (x == 1)
                    {
                        QueueSimulator q1;
                       

                    }

                    if (x == 2)
                    {
                        TextInputExample txt1;
                        txt1.run(menu);
                    }

                    if (x == 3)
                    {
                        TextInputExample txt1;
                        txt1.run(menu);
                    }
                    if (x == 4)
                    {
                        TextInputExample txt1;
                        txt1.run(menu);
                    }

                    if (x == 5)
                    {
                        TextInputExample txt1;
                        txt1.run(menu);

                    }

                    if (x == 6)
                    {

                        menu.clear();
                        menu.close();
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
