#include "stdafx.h"
#include "bot_002.h"
void bot_002::initVariables()
{
	this->pointCount = rand() % 8 + 3; //min = 3 max = 10
	this->type = 0;
	this->speed = static_cast<float>(1);
	this->damage = this->pointCount;
	this->points = this->pointCount;
	this->hpMax = 100;
	this->hp = this->hpMax;
}
void bot_002::initTexture()
{
	this->textureSheet.loadFromFile("Texture/bot002_02.png");
}
void bot_002::initSprite()
{
	this->sprite.setTexture(this->textureSheet);
	this->currentFrame = sf::IntRect(0, 0,49,51); 
	this->sprite.setTextureRect(this->currentFrame);
	this->sprite.setScale(2.5 ,2.5);
}
void bot_002::initAnimations()
{
	this->animationTimer.restart();
	this->animationSwitch = true;
}
bot_002::bot_002(float pos_x, float pos_y)
{
	this->sprite.setPosition(pos_x, pos_y);
	this->initVariables();
	this->initTexture();
	this->initSprite();
	this->initAnimations();
}

bot_002::~bot_002()
{
}

const Vector2f bot_002::getPosition() const
{
	return this->sprite.getPosition();
}

//Accessors
const sf::FloatRect bot_002::getBounds() const
{
	return this->sprite.getGlobalBounds();
}

const int& bot_002::getPoints() const
{
	return this->points;
}

const int& bot_002::getDamage() const
{
	return this->damage;
}
const bool& bot_002::getAnimSwitch()
{
	bool anim_switch = this->animationSwitch;
	if (this->animationSwitch)
		this->animationSwitch = false;
	return anim_switch;
}

void bot_002::resetAnimationTimer()
{
	this->animationTimer.restart();
	this->animationSwitch = true;
}

void bot_002::updateAnimations()
{
	if (this->animationTimer.getElapsedTime().asSeconds() > .02f || this->getAnimSwitch())
	{
		this->currentFrame.top = 51*5.f;
		this->currentFrame.left += 49;
		if (this->currentFrame.left > 49 * 8.f)
			this->currentFrame.left = 0;

		this->animationTimer.restart();
		this->sprite.setTextureRect(this->currentFrame);
	}
	if ((this->animationTimer.getElapsedTime().asSeconds() > .02f || this->getAnimSwitch())&&this->getDamage())
	{
		this->currentFrame.top = 51 * 6.f;
		this->currentFrame.left += 49*7;
		if (this->currentFrame.left > 49 * 9.f)
			this->currentFrame.left = 0;

		this->animationTimer.restart();
		this->sprite.setTextureRect(this->currentFrame);
	}
	else
		this->animationTimer.restart();
}
const int& bot_002::getHp() const
{
	return this->hp;
}
const int& bot_002::getHpMax() const
{
	return this->hpMax;
}
void bot_002::setHp(const int hp)
{
	this->hp = hp;
}
void bot_002::loseHp(const int value)
{
	this->hp -= value;
}
void bot_002::updateMove()//move
{
	if (this->sprite.getPosition().y > 850)
		this->sprite.move(0, -110);
	if (this->sprite.getPosition().y <= 850)
	{
		this->sprite.move(-1, 0);
	}
}
void bot_002::update()
{
	this->updateAnimations();
	this->updateMove();
}
void bot_002::render(RenderTarget* target)
{
	target->draw(this->sprite);
}
