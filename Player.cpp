 #include "stdafx.h"
#include "Player.h"
void Player::initVariables()
{
	this->animState = PLAYER_ANIMATION_STATES::IDLE;
	this->attackCooldownMax = 1.f;
	this->attackCooldown = this->attackCooldownMax;
	this->hpMax = 100;
	this->hp = this->hpMax;
	this->ammorMax = 100;
	this->ammor = this->ammorMax;
}

void Player::initTexture()
{
	this->textureSheet.loadFromFile("Texture/player_001.png");
}

void Player::initSprite()
{
	this->sprite.setTexture(this->textureSheet);
	this->currentFrame = sf::IntRect(0,0, 32, 32);
	this->sprite.setTextureRect(this->currentFrame);
	this->sprite.setScale(3.f, 3.f);
}

void Player::initAnimations()
{
	this->animationTimer.restart();
	this->animationSwitch = true;
}

void Player::initPhysics()
{
	this->velocityMax = 5.f;
	this->velocityMin = 1.f;
	this->acceleration = 3.0f;
	this->drag = 0.85f;
	this->gravity = 3.;
	this->velocityMaxY = 15.f;
}

Player::Player()
{
	this->initVariables();
	this->initTexture();
	this->initSprite();
	this->initAnimations();
	this->initPhysics();
}

Player::~Player()
{

}

const bool& Player::getAnimSwitch()
{
	bool anim_switch = this->animationSwitch;

	if (this->animationSwitch)
		this->animationSwitch = false;

	return anim_switch;
}
const int& Player::getHp() const
{
	return this->hp;
}

const int& Player::getHpMax() const
{
	return this->hpMax;
}
const sf::Vector2f Player::getPosition() const
{
	return this->sprite.getPosition();
}

const sf::FloatRect Player::getGlobalBounds() const
{
	return this->sprite.getGlobalBounds();
}
const sf::Vector2f& Player::getPos() const
{
	return this->sprite.getPosition();
}
void Player::setHp(const int hp)
{
	this->hp = hp;
}

void Player::loseHp(const int value)
{
	this->hp -= value;
	if (this->hp < 0)
		this->hp = 0;
}

void Player::attainhp(const int value)
{
	this->hp += value;
}

const int& Player::getAmmor() const
{
	return this->ammor;
}

const int& Player::getAmmorMax() const
{
	return this->ammorMax;
}

void Player::setAmmor(const int ammor)
{
	this->ammor = ammor;
}

void Player::loseAmmor(const int value)
{
	if (this->ammor < 0)
		this->ammor = 0;
	this->ammor -= value;
}

void Player::attainAmmor(const int value)
{
	this->ammor += value;
}

const sf::FloatRect Player::getBounds() const
{
	return this->sprite.getGlobalBounds();
}
void Player::setPosition(const float x, const float y)
{
	this->sprite.setPosition(x, y);
}

void Player::resetVelocityY()
{
	this->velocity.y = 0.f;
}

void Player::resetVelocityX()
{
	this->velocity.x = 0.f;
}

void Player::resetAnimationTimer()
{
	this->animationTimer.restart();
	this->animationSwitch = true;
}

void Player::move(const float dir_x, const float dir_y)
{
	//Acceleration
	this->velocity.x += dir_x * this->acceleration;

	//Limit velocity
	if (std::abs(this->velocity.x) > this->velocityMax)
	{
		this->velocity.x = this->velocityMax * ((this->velocity.x < 0.f) ? -1.f : 1.f);
	}
}

void Player::updatePhysics()
{
	//Gravity
	this->velocity.y += 1.0 * this->gravity;
	if (std::abs(this->velocity.x) > this->velocityMaxY)
	{
		this->velocity.y = this->velocityMaxY * ((this->velocity.y < 0.f) ? -1.f : 1.f);
	}

	//Deceleration
	this->velocity *= this->drag;

	//Limit deceleration
	if (std::abs(this->velocity.x) < this->velocityMin)
		this->velocity.x = 0.f;
	if (std::abs(this->velocity.y) < this->velocityMin)
		this->velocity.y = 0.f;

	this->sprite.move(this->velocity);
}

void Player::updateMovement()
{
	this->animState = PLAYER_ANIMATION_STATES::IDLE;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A)&&this->sprite.getPosition().x>=20) //Left
	{
		this->move(-1.f, 0.f);
		this->animState = PLAYER_ANIMATION_STATES::MOVING_LEFT;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)) //Right
	{
		this->move(1.f, 0.f);
		this->animState = PLAYER_ANIMATION_STATES::MOVING_RIGHT;
	}

	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W)) //Top
	{
		this->sprite.move(0.f, -30.f);
		this->animState = PLAYER_ANIMATION_STATES::JUMPING;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S)) //Top
	{
		this->animState = PLAYER_ANIMATION_STATES::SITDOWN;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right)) //Down
	{
		this->animState = PLAYER_ANIMATION_STATES::SHOOTING_RIGHT;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left)) //Down
	{
		this->animState = PLAYER_ANIMATION_STATES::SHOOTING_LEFT;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up)) //Down
	{
		this->animState = PLAYER_ANIMATION_STATES::SHOOTING_45;
	}
	
}

void Player::updateAnimations()
{
	if (this->animState == PLAYER_ANIMATION_STATES::IDLE)
	{
		if (this->animationTimer.getElapsedTime().asSeconds() >= 0.2f || this->getAnimSwitch())
		{
			this->currentFrame.top = 0.f;
			this->currentFrame.left += 32.f;
			if (this->currentFrame.left >32.f)
				this->currentFrame.left = 0;

			this->animationTimer.restart();
			this->sprite.setTextureRect(this->currentFrame);
		}
	}
	else if (this->animState == PLAYER_ANIMATION_STATES::MOVING_RIGHT)
	{
		if (this->animationTimer.getElapsedTime().asSeconds() >= 0.1f || this->getAnimSwitch())
		{
			this->currentFrame.top = 32.f;
			this->currentFrame.left += 32*5.f;
			if (this->currentFrame.left > 196-32.f)
				this->currentFrame.left = 0;

			this->animationTimer.restart();
			this->sprite.setTextureRect(this->currentFrame);
		}

		this->sprite.setScale(3.f, 3.f);
		this->sprite.setOrigin(0.f, 0.f);
	}
	else if (this->animState == PLAYER_ANIMATION_STATES::MOVING_LEFT)
	{
		if (this->animationTimer.getElapsedTime().asSeconds() >= 0.1f || this->getAnimSwitch())
		{
			this->currentFrame.top = 32.f;
			this->currentFrame.left += 32 * 5.f;
			if (this->currentFrame.left > 196 - 32.f)
				this->currentFrame.left = 0;

			this->animationTimer.restart();
			this->sprite.setTextureRect(this->currentFrame);
		}

		this->sprite.setScale(-3.f, 3.f);
		this->sprite.setOrigin(this->sprite.getGlobalBounds().width / 3.f, 0.f);
	}
	else if (this->animState == PLAYER_ANIMATION_STATES::JUMPING)
	{
		if (this->animationTimer.getElapsedTime().asSeconds() >= 0.1f || this->getAnimSwitch())
		{
			this->currentFrame.top = 96.f;
			this->currentFrame.left += 32.f;
			if (this->currentFrame.left > 64.f)
				this->currentFrame.left = 0;

			this->animationTimer.restart();
			this->sprite.setTextureRect(this->currentFrame);
		}

		this->sprite.setScale(3.f, 3.f);
	}
	else if (this->animState == PLAYER_ANIMATION_STATES::SITDOWN)
	{
		if (this->animationTimer.getElapsedTime().asSeconds() >= 0.1f || this->getAnimSwitch())
		{
			this->currentFrame.top = 32*6.f;
			this->currentFrame.left = 64.f+32;
			this->animationTimer.restart();
			this->sprite.setTextureRect(this->currentFrame);
			this->sprite.setPosition(this->sprite.getPosition().x, this->sprite.getPosition().y + this->sprite.getGlobalBounds().height);
		}

		this->sprite.setScale(3.f, 3.f);
	}
	else if (this->animState == PLAYER_ANIMATION_STATES::SHOOTING_RIGHT)
	{
		if (this->animationTimer.getElapsedTime().asSeconds() >= 0.1f || this->getAnimSwitch())
		{
			this->currentFrame.top = 160.f;
			this->currentFrame.left += 128.f;
			if (this->currentFrame.left > 224.f)
				this->currentFrame.left = 0;

			this->animationTimer.restart();
			this->sprite.setTextureRect(this->currentFrame);
		}

		this->sprite.setScale(3.f, 3.f);
		//this->sprite.setOrigin(this->sprite.getGlobalBounds().width / 3.f, 0.f);
	}
	else if (this->animState == PLAYER_ANIMATION_STATES::SHOOTING_LEFT)
	{
		if (this->animationTimer.getElapsedTime().asSeconds() >= 0.1f || this->getAnimSwitch())
		{
			this->currentFrame.top = 160.f;
			this->currentFrame.left += 128.f;
			if (this->currentFrame.left > 224.f)
				this->currentFrame.left = 0;

			this->animationTimer.restart();
			this->sprite.setTextureRect(this->currentFrame);
		}

		this->sprite.setScale(-3.f, 3.f);
		this->sprite.setOrigin(this->sprite.getGlobalBounds().width / 3.f, 0.f);
	}
	
	else
	//this->sprite.setOrigin(0, 0);
		this->animationTimer.restart();
}

void Player::update()
{
	this->updateMovement();
	this->updateAnimations();
	this->updatePhysics();
	this->updateAttack();
}
void Player::updateAttack()
{
	if (this->attackCooldown < this->attackCooldownMax)
		this->attackCooldown += .1f;
}
const bool Player::canAttack()
{
	if (this->attackCooldown >= this->attackCooldownMax)
	{
		this->attackCooldown = 0.f;
		return true;
	}

	return false;
}


void Player::render(sf::RenderTarget& target)
{
	target.draw(this->sprite);
}
