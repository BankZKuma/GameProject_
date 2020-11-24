#ifndef BULLET_H
#define BULLET_H

#include<SFML/Graphics.hpp>
#include<iostream>

class Bullet
{
private:

	Sprite shape;
	Vector2f direction;
	float movementSpeed;

public:
	Bullet(sf::Texture* texture, float pos_x, float pos_y, float dir_x, float dir_y, float movement_speed);
	virtual ~Bullet();

	//Accessor
	const sf::FloatRect getBounds() const;

	void update();
	void render(sf::RenderTarget*);
};

#endif // !BULLET_H
