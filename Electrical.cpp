#include "stdafx.h"
#include "Electrical.h"

void Electrical::initVariables()
{
	this->type = 0;
	this->speed = static_cast<float>(70);
}
void Electrical::initTexture()
{
	this->textureSheet.loadFromFile("Texture/boss_skill.png");
}
void Electrical::initSprite()
{
	this->sprite.setTexture(this->textureSheet);
	this->currentFrame = sf::IntRect(0, 0, 86,253); //SHOULD BE 40 50
	this->sprite.setTextureRect(this->currentFrame);
	this->sprite.setScale(3, 5);
}
void Electrical::initAnimations()
{
	this->animationTimer.restart();
	this->animationSwitch = true;
}
Electrical::Electrical(float pos_x, float pos_y)
{
	this->sprite.setPosition(pos_x, pos_y);
	this->initVariables();
	this->initTexture();
	this->initSprite();
	this->initAnimations();
}

Electrical::~Electrical()
{
}

//Accessors
const sf::FloatRect Electrical::getBounds() const
{
	return this->sprite.getGlobalBounds();
}


const int& Electrical::getDamage() const
{
	return this->damage;
}
const bool& Electrical::getAnimSwitch()
{
	bool anim_switch = this->animationSwitch;

	if (this->animationSwitch)
		this->animationSwitch = false;

	return anim_switch;
}

void Electrical::resetAnimationTimer()
{
	this->animationTimer.restart();
	this->animationSwitch = true;
}

void Electrical::updateAnimations()
{
	if ((this->animationTimer.getElapsedTime().asSeconds() > .01 || this->getAnimSwitch()) && this->sprite.getPosition().y < 804)
	{
		this->currentFrame.top = 0.f;
		this->currentFrame.left += 86;
		if (this->currentFrame.left > 86 * 6.f)
			this->currentFrame.left = 0;

		this->animationTimer.restart();
		this->sprite.setTextureRect(this->currentFrame);
	}
	else
		this->animationTimer.restart();
}
//Functions
void Electrical::updateMove()//move
{
	this->sprite.move(0, this->speed);
}

void Electrical::update()
{
	this->updateAnimations();
	this->updateMove();
}

void Electrical::render(sf::RenderTarget* target)
{
	if (this->sprite.getPosition().y < 830)
		target->draw(this->sprite);
}
