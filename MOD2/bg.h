#pragma once
#include<SFML/Graphics.hpp>
using namespace std;
using namespace sf;




class bg {
public:
	bg(float x, float y);
	bg();

	//vector<Sprite>stone;
	void set_bg(const RenderWindow& window);
private:
	Sprite sprite;

};
