#pragma once
class box
{
private:
	//UI
	int hp;
	int hpMax;
	//ETC
	Sprite sprite;
	Texture textureSheet;

	//Animation
	short animState;
	IntRect currentFrame;
	bool animationSwitch;

	void initVariables();
	void initTexture();
	void initSprite();
	void initAnimations();
public:

	box();
	virtual ~box();
	Clock animationTimer;
	//Accessors
	const bool& getAnimSwitch();
	const sf::Vector2f getPosition() const;
	const sf::FloatRect getGlobalBounds() const;

	//Modifiers
	void setPosition();
	//Functions	
	void resetAnimationTimer();
	void updateAnimations();
	void update();
	void render2(sf::RenderTarget& target);


	const sf::Vector2f& getPos() const;
	const sf::FloatRect getBounds() const;
	//UI
	const int& getHp() const;
	const int& getHpMax() const;
	void setHp(const int hp);
	void loseHp(const int value);
};
