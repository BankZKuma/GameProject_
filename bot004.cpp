#include "stdafx.h"
#include "bot004.h"
void bot004::initVariables()
{
	this->pointCount = rand() % 8 + 3; //min = 3 max = 10
	this->type = 0;
	this->speed = static_cast<float>(1);
	this->damage = this->pointCount;
	this->points = this->pointCount;
	this->hpMax = 100;
	this->hp = this->hpMax;
}
void bot004::initTexture()
{
	this->textureSheet.loadFromFile("Texture/bot004.png");
}
void bot004::initSprite()
{
	this->sprite.setTexture(this->textureSheet);
	this->currentFrame = sf::IntRect(0, 0, 55.9,70);
	this->sprite.setTextureRect(this->currentFrame);
	this->sprite.setScale(2.1, 2.1);
}
void bot004::initAnimations()
{
	this->animationTimer.restart();
	this->animationSwitch = true;
}
bot004::bot004(float pos_x, float pos_y)
{
	this->sprite.setPosition(pos_x, pos_y);
	this->initVariables();
	this->initTexture();
	this->initSprite();
	this->initAnimations();
}

bot004::~bot004()
{
}

const Vector2f bot004::getPosition() const
{
	return this->sprite.getPosition();
}

//Accessors
const sf::FloatRect bot004::getBounds() const
{
	return this->sprite.getGlobalBounds();
}

const int& bot004::getPoints() const
{
	return this->points;
}

const int& bot004::getDamage() const
{
	return this->damage;
}
const bool& bot004::getAnimSwitch()
{
	bool anim_switch = this->animationSwitch;
	if (this->animationSwitch)
		this->animationSwitch = false;
	return anim_switch;
}

void bot004::resetAnimationTimer()
{
	this->animationTimer.restart();
	this->animationSwitch = true;
}

void bot004::updateAnimations()
{
	if (this->animationTimer.getElapsedTime().asSeconds() > .02f || this->getAnimSwitch())
	{
		this->currentFrame.top = 70*3.f;
		this->currentFrame.left += 55.9*2;
		if (this->currentFrame.left >55.9* 4.f)
			this->currentFrame.left = 0;

		this->animationTimer.restart();
		this->sprite.setTextureRect(this->currentFrame);
	}
	else
		this->animationTimer.restart();
}
const int& bot004::getHp() const
{
	return this->hp;
}
const int& bot004::getHpMax() const
{
	return this->hpMax;
}
void bot004::setHp(const int hp)
{
	this->hp = hp;
}
void bot004::loseHp(const int value)
{
	this->hp -= value;
}
void bot004::updateMove()//move
{
	if (this->sprite.getPosition().y > 780)
		this->sprite.move(0, -110);
	if (this->sprite.getPosition().y <= 780)
	{
		this->sprite.move(-1, 0);
	}
}
void bot004::update()
{
	this->updateAnimations();
	this->updateMove();
}
void bot004::render(RenderTarget* target)
{
	target->draw(this->sprite);
}
