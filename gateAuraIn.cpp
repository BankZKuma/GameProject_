#include "stdafx.h"
#include "gateAuraIn.h"

void gateAuraIn::initTexture()
{
	this->textureSheet.loadFromFile("Texture/portalwarp.png");
}

void gateAuraIn::initSprite()
{
	this->sprite.setTexture(this->textureSheet);
	this->currentFrame = sf::IntRect(0, 0, 114, 217);
	this->sprite.setTextureRect(this->currentFrame);
	this->sprite.setScale(2, 2);
}

void gateAuraIn::initAnimations()
{
	this->animationTimer.restart();
	this->animationSwitch = true;
}

gateAuraIn::gateAuraIn()
{
	this->sprite.setPosition(18600, 500);
	this->initTexture();
	this->initSprite();
	this->initAnimations();
}

const FloatRect gateAuraIn::getBounds() const
{
	return this->sprite.getGlobalBounds();
}

gateAuraIn::~gateAuraIn()
{
}

const bool& gateAuraIn::getAnimSwitch()
{
	bool anim_switch = this->animationSwitch;
	if (this->animationSwitch)
		this->animationSwitch = false;
	return anim_switch;
}

void gateAuraIn::resetAnimationTimer()
{
	this->animationTimer.restart();
	this->animationSwitch = true;
}

void gateAuraIn::updateAnimations()
{
	if (this->animationTimer.getElapsedTime().asSeconds() > .02f || this->getAnimSwitch())
	{
		this->currentFrame.top = 0.f;
		this->currentFrame.left += 103;
		if (this->currentFrame.left > 103 * 4.f)
			this->currentFrame.left = 0;

		this->animationTimer.restart();
		this->sprite.setTextureRect(this->currentFrame);
	}
	else
		this->animationTimer.restart();
}

void gateAuraIn::update()
{
	this->updateAnimations();
}

void gateAuraIn::render(sf::RenderTarget* target)
{
	target->draw(this->sprite);
}
