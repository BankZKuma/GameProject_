#include "stdafx.h"
#include "MVP.h"
void MVP::initVariables()
{
	this->attackCooldownMax = 10.f;
	this->attackCooldown = this->attackCooldownMax;
	this->hpMax = 1000;
	this->hp = this->hpMax;
	this->ammorMax = 1000;
	this->ammor = this->ammorMax;
}

void MVP::initTexture()
{
	this->textureSheet.loadFromFile("Texture/BOSS.png");
}

void MVP::initSprite()
{
	this->sprite.setTexture(this->textureSheet);
	this->currentFrame = IntRect(0, 0, 122, 110);
	this->sprite.setTextureRect(this->currentFrame);
	this->sprite.setScale(1.f, 1.f);
}

void MVP::initAnimations()
{
	this->animationTimer.restart();
	this->animationSwitch = true;
}

void MVP::initPhysics()
{
	this->velocityMax = 5.f;
	this->velocityMin = 1.f;
	this->acceleration = 3.0f;
	this->drag = 0.85f;
}

MVP::MVP()
{
	this->setPosition();
	this->initVariables();
	this->initTexture();
	this->initSprite();
	this->initAnimations();
	this->initPhysics();
}

MVP::~MVP()
{

}

const bool& MVP::getAnimSwitch()
{
	bool anim_switch = this->animationSwitch;

	if (this->animationSwitch)
		this->animationSwitch = false;

	return anim_switch;
}
const int& MVP::getHp() const
{
	return this->hp;
}

const int& MVP::getHpMax() const
{
	return this->hpMax;
}
const sf::Vector2f MVP::getPosition() const
{
	return this->sprite.getPosition();
}

const sf::FloatRect MVP::getGlobalBounds() const
{
	return this->sprite.getGlobalBounds();
}
const sf::Vector2f& MVP::getPos() const
{
	return this->sprite.getPosition();
}
void MVP::setHp(const int hp)
{
	this->hp = hp;
}

void MVP::loseHp(const int value)
{
	this->hp -= value;
	if (this->hp < 0)
		this->hp = 0;
}

const int& MVP::getAmmor() const
{
	return this->ammor;
}

const int& MVP::getAmmorMax() const
{
	return this->ammorMax;
}

void MVP::setAmmor(const int ammor)
{
	this->ammor = ammor;
}

void MVP::loseAmmor(const int value)
{
	this->ammor -= value;
}


const sf::FloatRect MVP::getBounds() const
{
	return this->sprite.getGlobalBounds();
}
void MVP::setPosition()
{
	this->sprite.setPosition(21700,400);
}

void MVP::resetVelocityY()
{
	this->velocity.y = 0.f;
}

void MVP::resetVelocityX()
{
	this->velocity.x = 0.f;
}

void MVP::resetAnimationTimer()
{
	this->animationTimer.restart();
	this->animationSwitch = true;
}

void MVP::updateMovement(float x, float y)
{
	this->sprite.move(x, y);
}
void MVP::updateAnimations()
{
		if (this->animationTimer.getElapsedTime().asSeconds() >= 0.02f || this->getAnimSwitch())
		{
			this->currentFrame.top = 110.f;
			this->currentFrame.left += 122.f;
			if (this->currentFrame.left > 122*3.f)
				this->currentFrame.left = 0;
			this->animationTimer.restart();
			this->sprite.setTextureRect(this->currentFrame);
			this->sprite.setScale(-5.f, 5.f);
			this->sprite.setOrigin(this->sprite.getGlobalBounds().width / 5.f, 0.f);
		}
	else
		this->animationTimer.restart();
}

void MVP::update()
{
	this->updateAnimations();
	this->updateAttack();
}
void MVP::updateAttack()
{
	if (this->attackCooldown < this->attackCooldownMax)
		this->attackCooldown += .1f;
}
const bool MVP::canAttack()
{
	if (this->attackCooldown >= this->attackCooldownMax)
	{
		this->attackCooldown = 0.f;
		return true;
	}

	return false;
}


void MVP::render2(RenderTarget& target)
{
	target.draw(this->sprite);
}
