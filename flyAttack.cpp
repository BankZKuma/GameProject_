#include "stdafx.h"
#include "flyAttack.h"
flyAttack::flyAttack(float pos_x, float pos_y,Vector2f dir_xy, float movement_speed)
{
	this->shape.setPosition(pos_x, pos_y);
	this->direction = dir_xy;
	this->movementSpeed = movement_speed;
	this->initSprite();
	this->initTexture();
}

flyAttack::~flyAttack()
{

}
void flyAttack::initTexture()
{
	this->shape.setTexture(this->texture);
	this->shape.setScale(1, 1);
}
void flyAttack::initSprite()
{
	this->texture.loadFromFile("Texture/redspot.png");
}
const Vector2f flyAttack::getPosition() const
{
	return this->shape.getPosition();
}

const FloatRect flyAttack::getBounds() const
{
	return this->shape.getGlobalBounds();
}

void flyAttack::update()
{
	//Movement
	this->shape.move(this->movementSpeed * this->direction);
}

void flyAttack::render(sf::RenderTarget& target)
{
	target.draw(this->shape);
}