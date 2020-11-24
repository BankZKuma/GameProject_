#pragma once
class Electrical
{
private:
	Sprite sprite;
	Texture textureSheet;

	short animState;
	IntRect currentFrame;
	bool animationSwitch;

	Texture texture;
	int type;
	float speed;
	int damage;

	void initVariables();
	void initTexture();
	void initSprite();
	void initAnimations();
public:
	Electrical(float pos_x, float pos_y);
	virtual ~Electrical();
	Clock animationTimer;
	//Accessors
	const FloatRect getBounds() const;
	const int& getDamage() const;
	//Animation
	const bool& getAnimSwitch();
	void resetAnimationTimer();
	void updateAnimations();


	//Functions
	void updateMove();
	void update();
	void render(sf::RenderTarget* target);
};
