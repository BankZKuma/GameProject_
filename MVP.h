#pragma once
class MVP
{
private:
	//UI
	int hp;
	int hpMax;
	int ammor;
	int ammorMax;


	//ETC
	Sprite sprite;
	Texture textureSheet;

	//Animation
	short animState;
	IntRect currentFrame;
	bool animationSwitch;

	//Physics
	Vector2f velocity;
	float velocityMax;
	float velocityMin;
	float acceleration;
	float drag;
	float gravity;
	float velocityMaxY;
	float attackCooldown;
	float attackCooldownMax;
	//Core

	void initVariables();
	void initTexture();
	void initSprite();
	void initAnimations();
	void initPhysics();
	void innitBulletTex();
	//Bullet
	Texture bulleTex;
	void innitBullet();
	void settingBullet();
public:

	MVP();
	virtual ~MVP();
	Clock animationTimer;
	//Accessors
	const bool& getAnimSwitch();
	const sf::Vector2f getPosition() const;
	const sf::FloatRect getGlobalBounds() const;

	//Modifiers
	void setPosition();
	void resetVelocityY();
	void resetVelocityX();

	//Functions	
	void resetAnimationTimer();
	void move(const float dir_x, const float dir_y);
	void updateMovement(float x,float y);
	void updateAnimations();
	void update();
	void render2(sf::RenderTarget& target);


	const sf::Vector2f& getPos() const;
	const sf::FloatRect getBounds() const;
	const bool canAttack();
	void updateAttack();
	//UI
	const int& getHp() const;
	const int& getHpMax() const;
	void setHp(const int hp);
	void loseHp(const int value);
	//ammor
	const int& getAmmor() const;
	const int& getAmmorMax() const;
	void setAmmor(const int hp);
	void loseAmmor(const int value);
};