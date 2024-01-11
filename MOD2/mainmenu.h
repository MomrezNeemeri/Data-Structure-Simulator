#pragma once
#include"SFML/Graphics.hpp"
#include<iostream>
#define menufunctions 10
using namespace std;
using namespace sf;
class MainMenu
{
public: 
	void draw(RenderWindow& window);
	void MoveUp();
	void MoveDown();
	void levelMoveUp();
	void levelMoveDown();
	void drawlevel(RenderWindow& levels);
	int selectmenu(MainMenu mainmenu, Sprite& backmenu);
	void mousePressed(RenderWindow& window);
	
	Text mainMenu[menufunctions];

	int MainMenuPressed() {
		return MainMenuSelected;
	}
	int mousepress()
	{
		return mouseselected;
	}
	
	MainMenu(float menuwidth, float menuheight);

	~MainMenu();

private:
	int MainMenuSelected;
	int levelmenuSelected;
	int mouseselected;
	Font font;

};
 