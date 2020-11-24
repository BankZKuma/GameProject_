#include "stdafx.h"
#include "botFly.h"
void botFly::initVariables()
{
	this->attackCooldownMax = 1.f;
	this->attackCooldown = this->attackCooldownMax;
	this->pointCount = rand() % 8 + 3; //min = 3 max = 10
	this->type = 0;
	this->speed = static_cast<float>(1);
	this->damage = this->pointCount;
	this->points = this->pointCount;
	this->hpMax = 100;
	this->hp = this->hpMax;
}
void botFly::initTexture()
{
	this->textureSheet.loadFromFile("Texture/ufo.png");
}
void botFly::initSprite()
{
	this->sprite.setTexture(this->textureSheet);
	this->currentFrame = sf::IntRect(0, 0, 144, 57);
	this->sprite.setTextureRect(this->currentFrame);
	this->sprite.setScale(1,2);
}
void botFly::initAnimations()
{
	this->animationTimer.restart();
	this->animationSwitch = true;
}
botFly::botFly(float pos_x, float pos_y)
{
	this->sprite.setPosition(pos_x, pos_y);
	this->initVariables();
	this->initTexture();
	this->initSprite();
	this->initAnimations();
}

botFly::~botFly()
{
}

const Vector2f botFly::getPosition() const
{
	return this->sprite.getPosition();
}

//Accessors
const sf::FloatRect botFly::getBounds() const
{
	return this->sprite.getGlobalBounds();
}

const int& botFly::getPoints() const
{
	return this->points;
}

const int& botFly::getDamage() const
{
	return this->damage;
}
const bool& botFly::getAnimSwitch()
{
	bool anim_switch = this->animationSwitch;
	if (this->animationSwitch)
		this->animationSwitch = false;
	return anim_switch;
}

void botFly::resetAnimationTimer()
{
	this->animationTimer.restart();
	this->animationSwitch = true;
}

void botFly::updateAnimations()
{
	if (this->animationTimer.getElapsedTime().asSeconds() > .02f || this->getAnimSwitch())
	{
		this->currentFrame.top = 0;
		this->currentFrame.left += 144 * 2;
		if (this->currentFrame.left >144 * 5.f)
			this->currentFrame.left = 0;

		this->animationTimer.restart();
		this->sprite.setTextureRect(this->currentFrame);
	}
	else
		this->animationTimer.restart();
}
const int& botFly::getHp() const
{
	return this->hp;
}
const int& botFly::getHpMax() const
{
	return this->hpMax;
}
void botFly::setHp(const int hp)
{
	this->hp = hp;
}
void botFly::loseHp(const int value)
{
	this->hp -= value;
}
void botFly::updateMove()//move
{
	if (this->sprite.getPosition().y > 750)
		this->sprite.move(0, -100);
	if (this->sprite.getPosition().y <=750)
	{
		this->sprite.move(-1, 0);
	}
}
void botFly::update()
{
	this->updateAnimations();
	this->updateMove();
}
void botFly::render(RenderTarget* target)
{
	target->draw(this->sprite);
}
void botFly::updateAttack()
{
	if (this->attackCooldown < this->attackCooldownMax)
		this->attackCooldown += .1f;
}
const bool botFly::canAttack()
{
	if (this->attackCooldown >= this->attackCooldownMax)
	{
		this->attackCooldown = 0.f;
		return true;
	}

	return false;
}