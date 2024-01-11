#include"mainmenu.h"

using namespace std;
MainMenu::MainMenu(float menuwidth, float menuheight)
{
	if (!font.loadFromFile("D:/dssim/MOD2/MOD2/fonts/Rough Serif.ttf"))
		cout << "font didn't load";
	mainMenu[0].setFont(font);
	mainMenu[0].setFillColor(Color::Color(255, 222, 173));
	mainMenu[0].setString("Stack");
	mainMenu[0].setCharacterSize(40);
	mainMenu[0].setPosition(825, 150);


	mainMenu[1].setFont(font);
	mainMenu[1].setFillColor(Color::Color(255, 222, 173));
	mainMenu[1].setString("Queue");
	mainMenu[1].setCharacterSize(40);
	mainMenu[1].setPosition(825, 250);


	mainMenu[2].setFont(font);
	mainMenu[2].setFillColor(Color::Color(255, 222, 173));
	mainMenu[2].setString("LinkedList");
	mainMenu[2].setCharacterSize(40);
	mainMenu[2].setPosition(825, 350);


	mainMenu[3].setFont(font);
	mainMenu[3].setFillColor(Color::Color(255, 222, 173));
	mainMenu[3].setString("BST");
	mainMenu[3].setCharacterSize(40);
	mainMenu[3].setPosition(825, 450);



	mainMenu[4].setFont(font);
	mainMenu[4].setFillColor(Color::Color(255, 222, 173));
	mainMenu[4].setString("Deque");
	mainMenu[4].setCharacterSize(40);
	mainMenu[4].setPosition(825, 550);


	mainMenu[5].setFont(font);
	mainMenu[5].setFillColor(Color::Color(255, 222, 173));
	mainMenu[5].setString("Bubble Sort");
	mainMenu[5].setCharacterSize(40);
	mainMenu[5].setPosition(825, 650);



	mainMenu[6].setFont(font);
	mainMenu[6].setFillColor(Color::Color(255, 222, 173));
	mainMenu[6].setString("Insertion Sort");
	mainMenu[6].setCharacterSize(40);
	mainMenu[6].setPosition(825, 750);

	mainMenu[7].setFont(font);
	mainMenu[7].setFillColor(Color::Color(255, 222, 173));
	mainMenu[7].setString("Heap Sort");
	mainMenu[7].setCharacterSize(40);
	mainMenu[7].setPosition(825, 850);

	MainMenuSelected = 0;

}
MainMenu:: ~MainMenu()
{}



void MainMenu::draw(RenderWindow& window)
{
	for (int i = 0;i < 8;i++)
	{
		window.draw(mainMenu[i]);
	}
}

void MainMenu::MoveUp()
{
	if (MainMenuSelected - 1 >= -1)
	{
		mainMenu[MainMenuSelected].setFillColor(Color::Color(255, 222, 173));
		MainMenuSelected--;
		if (MainMenuSelected == -1)
		{
			MainMenuSelected = 6;
		}
		mainMenu[MainMenuSelected].setFillColor(Color::Color(178, 34, 34));
	}
}

void MainMenu::MoveDown()
{
	if (MainMenuSelected + 1 <= menufunctions)
	{
		mainMenu[MainMenuSelected].setFillColor(Color::Color(255, 222, 173));
		MainMenuSelected++;
		if (MainMenuSelected == 7)
		{
			MainMenuSelected = 0;
		}
		//mainMenu[MainMenuSelected].setCharacterSize(60);
		mainMenu[MainMenuSelected].setFillColor(Color::Color(178, 34, 34));
	}
	//mainMenu[MainMenuSelected].setCharacterSize(40);

}



void MainMenu::drawlevel(RenderWindow& levels)
{


	for (int i = 0;i < 8;i++)
	{
		levels.draw(mainMenu[i]);
	}
}






void MainMenu::mousePressed(RenderWindow& window)
{
	Vector2f mousePos = window.mapPixelToCoords(Mouse::getPosition(window));
	FloatRect menu1 = mainMenu[0].getGlobalBounds();
	FloatRect menu2 = mainMenu[1].getGlobalBounds();
	FloatRect menu3 = mainMenu[2].getGlobalBounds();
	FloatRect menu4 = mainMenu[3].getGlobalBounds();
	//mouseselected = -1;
	if (menu1.contains(mousePos))
	{
		Color current = mainMenu[0].getFillColor();
		mainMenu[0].setFillColor(Color::Color(178, 34, 34));
		if (Mouse::isButtonPressed(Mouse::Left))
		{

			mouseselected = 0;
		//	cout << "         " << mouseselected;
		}
		//if (current != Color::Red)
		//	menusound.play();
	}
	else
	{
		mainMenu[0].setFillColor(Color::Color(255, 222, 173));
	}
	if (menu2.contains(mousePos))
	{
		Color current = mainMenu[0].getFillColor();
		mainMenu[1].setFillColor(Color::Color(178, 34, 34));
		if (Mouse::isButtonPressed(Mouse::Left))
		{
			mouseselected = 1;
		//	cout << "         " << mouseselected;
		}
		//if (current != Color::Red)
		//	menusound.play();
	}
	else
	{
		mainMenu[1].setFillColor(Color::Color(255, 222, 173));
	}
	if (menu3.contains(mousePos))
	{
		Color current = mainMenu[1].getFillColor();
		mainMenu[2].setFillColor(Color::Color(178, 34, 34));
		if (Mouse::isButtonPressed(Mouse::Left))
			mouseselected = 2;
		//if (current != Color::Red)
		//	menusound.play();

	}
	else
	{
		mainMenu[2].setFillColor(Color::Color(255, 222, 173));
	}
	if (menu4.contains(mousePos))
	{
		Color current = mainMenu[2].getFillColor();
		mainMenu[3].setFillColor(Color::Color(178, 34, 34));
		if (Mouse::isButtonPressed(Mouse::Left))
			mouseselected = 3;


		//if (current != Color::Red)
		//	menusound.play();
	}
	else
	{
		mainMenu[3].setFillColor(Color::Color(255, 222, 173));
	}


}



