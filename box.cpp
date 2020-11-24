#include "stdafx.h"
#include "box.h"
void box::initVariables()
{
	this->hpMax = 100;
	this->hp = this->hpMax;
}

void box::initTexture()
{
	this->textureSheet.loadFromFile("Texture/treaser_.png");
}

void box::initSprite()
{
	this->sprite.setTexture(this->textureSheet);
	this->currentFrame = IntRect(0, 0, 90, 91);
	this->sprite.setTextureRect(this->currentFrame);
	this->sprite.setScale(2.f, 2.f);
}

void box::initAnimations()
{
	this->animationTimer.restart();
	this->animationSwitch = true;
}

box::box()
{
	this->setPosition();
	this->initVariables();
	this->initTexture();
	this->initSprite();
	this->initAnimations();
}

box::~box()
{

}

const bool& box::getAnimSwitch()
{
	bool anim_switch = this->animationSwitch;

	if (this->animationSwitch)
		this->animationSwitch = false;

	return anim_switch;
}
const int& box::getHp() const
{
	return this->hp;
}

const int& box::getHpMax() const
{
	return this->hpMax;
}

const sf::FloatRect box::getGlobalBounds() const
{
	return this->sprite.getGlobalBounds();
}
const sf::Vector2f& box::getPos() const
{
	return this->sprite.getPosition();
}
void box::setHp(const int hp)
{
	this->hp = hp;
}

void box::loseHp(const int value)
{
	this->hp -= value;
	if (this->hp < 0)
		this->hp = 0;
}

const sf::FloatRect box::getBounds() const
{
	return this->sprite.getGlobalBounds();
}

void box::setPosition()
{
	this->sprite.setPosition(18000, 730);
}

void box::resetAnimationTimer()
{
	this->animationTimer.restart();
	this->animationSwitch = true;
}

void box::updateAnimations()
{
	if (this->animationTimer.getElapsedTime().asSeconds() >= 0.02f || this->getAnimSwitch())
	{
		this->currentFrame.top = 0.f;
		this->currentFrame.left += 90.f;
		if (this->currentFrame.left > 90 * 2.f)
			this->currentFrame.left = 0;
		this->animationTimer.restart();
		this->sprite.setTextureRect(this->currentFrame);
	}
	else
		this->animationTimer.restart();
}

void box::update()
{
	this->updateAnimations();
}

void box::render2(RenderTarget& target)
{
	target.draw(this->sprite);
}
