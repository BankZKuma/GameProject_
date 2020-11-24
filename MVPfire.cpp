#include "stdafx.h"
#include "MVPfire.h"
void MVPfire::initTexture()
{
	this->shape.setTexture(this->texture);
	this->shape.setScale(.25, .5);
}
void MVPfire::initSprite()
{
	this->texture.loadFromFile("Texture/beam_.png");
}
MVPfire::MVPfire( float pos_x, float pos_y, float dir_x, float dir_y, float movement_speed)
{
	this->shape.setPosition(pos_x, pos_y);
	this->direction.x = dir_x;
	this->direction.y = dir_y;
	this->movementSpeed = movement_speed;
	this->initSprite();
	this->initTexture();
}

MVPfire::~MVPfire()
{

}

const Vector2f MVPfire::getPosition() const
{
	return this->shape.getPosition();
}

const FloatRect MVPfire::getBounds() const
{
	return this->shape.getGlobalBounds();
}


void MVPfire::update()
{
	//Movement
	this->shape.move(this->movementSpeed * this->direction);
}

void MVPfire::render(sf::RenderTarget& target)
{
	target.draw(this->shape);
}