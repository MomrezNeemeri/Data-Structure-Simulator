#include "bg.h"



bg::bg(float x, float y) {
	sprite.setPosition(x, y);
}

void bg::set_bg(const RenderWindow& window) {

	Texture bg;
	bg.loadFromFile("bg.png");
	sprite.setTexture(bg);
	//window.draw(sprite);


};