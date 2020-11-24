#include "stdafx.h"
#include "Enemy.h"

void Enemy::initVariables()
{
	this->pointCount = rand() % 8 + 3; //min = 3 max = 10
	this->type = 0;
	this->speed = static_cast<float>(5);
	this->damage = this->pointCount;
	this->points = this->pointCount;
}
void Enemy::initTexture()
{
	this->textureSheet.loadFromFile("Texture/dream2.gif");
}
void Enemy::initSprite()
{
	this->sprite.setTexture(this->textureSheet);
	this->currentFrame = sf::IntRect(0, 0,120 ,115); //SHOULD BE 40 50
	this->sprite.setTextureRect(this->currentFrame);
	this->sprite.setScale(1,1);
}
void Enemy::initAnimations()
{
	this->animationTimer.restart();
	this->animationSwitch = true;
}
Enemy::Enemy(float pos_x, float pos_y)
{
	this->sprite.setPosition(pos_x, pos_y);
	this->initVariables();
	this->initTexture();
	this->initSprite();
	this->initAnimations();
}

Enemy::~Enemy()
{
}

//Accessors
const sf::FloatRect Enemy::getBounds() const
{
	return this->sprite.getGlobalBounds();
}

const int& Enemy::getPoints() const
{
	return this->points;
}

const int& Enemy::getDamage() const
{
	return this->damage;
}
const bool& Enemy::getAnimSwitch()
{
	bool anim_switch = this->animationSwitch;

	if (this->animationSwitch)
		this->animationSwitch = false;

	return anim_switch;
}

void Enemy::resetAnimationTimer()
{
	this->animationTimer.restart();
	this->animationSwitch = true;
}

void Enemy::updateAnimations()
{
	if ((this->animationTimer.getElapsedTime().asSeconds()>.01||this->getAnimSwitch())&&this->sprite.getPosition().y<804)
		{
			this->currentFrame.top =0.f;
			this->currentFrame.left += 120;
			if (this->currentFrame.left >120 * 3.f)
				this->currentFrame.left = 0;

			this->animationTimer.restart();
			this->sprite.setTextureRect(this->currentFrame);
		}
		else
			this->animationTimer.restart();
	}
//Functions
void Enemy::updateMove()//move
{
	this->sprite.move(-5, this->speed);
}

void Enemy::update()
{
	this->updateAnimations();
	this->updateMove();
}

void Enemy::render(sf::RenderTarget* target)
{
	if(this->sprite.getPosition().y<830)
		target->draw(this->sprite);
}
