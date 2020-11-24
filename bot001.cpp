#include "stdafx.h"
#include "bot001.h"
void bot001::initVariables()
{
	this->pointCount = rand() % 8 + 3; //min = 3 max = 10
	this->type = 0;
	this->speed = static_cast<float>(1);
	this->damage = this->pointCount;
	this->points = this->pointCount;
	this->hpMax = 100;
	this->hp = this->hpMax;
}
void bot001::initTexture()
{
	this->textureSheet.loadFromFile("Texture/enemy.jpg");
}
void bot001::initSprite()
{
	this->sprite.setTexture(this->textureSheet);
	this->currentFrame = sf::IntRect(0, 0, 64,64); //SHOULD BE 40 50
	this->sprite.setTextureRect(this->currentFrame);
	this->sprite.setScale(1.7, 1.7);
}
void bot001::initAnimations()
{
	this->animationTimer.restart();
	this->animationSwitch = true;
}
bot001::bot001(float pos_x, float pos_y)
{
	this->sprite.setPosition(pos_x, pos_y);
	this->initVariables();
	this->initTexture();
	this->initSprite();
	this->initAnimations();
}

bot001::~bot001()
{
}

const Vector2f bot001::getPosition() const
{
	return this->sprite.getPosition();
}

//Accessors
const sf::FloatRect bot001::getBounds() const
{
	return this->sprite.getGlobalBounds();
}

const int& bot001::getPoints() const
{
	return this->points;
}

const int& bot001::getDamage() const
{
	return this->damage;
}
const bool& bot001::getAnimSwitch()
{
	bool anim_switch = this->animationSwitch;
	if (this->animationSwitch)
		this->animationSwitch = false;
	return anim_switch;
}

void bot001::resetAnimationTimer()
{
	this->animationTimer.restart();
	this->animationSwitch = true;
}

void bot001::updateAnimations()
{
	if (this->animationTimer.getElapsedTime().asSeconds() > .02f || this->getAnimSwitch())
	{
		this->currentFrame.top = 64.f;
		this->currentFrame.left += 64;
		if (this->currentFrame.left > 64 * 8.f)
			this->currentFrame.left = 0;

		this->animationTimer.restart();
		this->sprite.setTextureRect(this->currentFrame);
	}
	if ((this->animationTimer.getElapsedTime().asSeconds() > .02f || this->getAnimSwitch())&&this->getDamage())
	{
		this->currentFrame.top = 64*6.f;
		this->currentFrame.left += 64;
		if (this->currentFrame.left > 64 * 8.f)
			this->currentFrame.left = 0;

		this->animationTimer.restart();
		this->sprite.setTextureRect(this->currentFrame);
	}
	else
		this->animationTimer.restart();
}
const int& bot001::getHp() const
{
	return this->hp;
}
const int& bot001::getHpMax() const
{
		return this->hpMax;
}
void bot001::setHp(const int hp)
{
	this->hp = hp;
}
void bot001::loseHp(const int value)
{
	this->hp -= value;
}
void bot001::updateMove()//move
{
	if (this->sprite.getPosition().y > 800)
		this->sprite.move(0, -110);
	if (this->sprite.getPosition().y <= 800)
	{
			this->sprite.move(-rand()%5, 0);
	}
}
void bot001::update()
{
	this->updateAnimations();
	this->updateMove();
}
void bot001::render(RenderTarget* target)
{
	target->draw(this->sprite);
}
