#include "stdafx.h"
#include "bot001__HP.h"

bot001__HP::bot001__HP(Vector2f pos001,Vector2f setSize)
{
	this->inintHpbar001();
	this->bot001Hpbar.setSize(setSize);
	this->bot001Hpbar.setPosition(pos001);
	this->bot001HpbarBack = this->bot001Hpbar;
}

bot001__HP::~bot001__HP()
{
}

void bot001__HP::render(sf::RenderTarget* target)
{
	target->draw(this->bot001Hpbar);
	target->draw(this->bot001HpbarBack);
}

void bot001__HP::inintHpbar001()
{
	this->bot001Hpbar.setFillColor(Color::Red);
	this->bot001HpbarBack.setFillColor(Color(25, 25, 25, 200));
}
