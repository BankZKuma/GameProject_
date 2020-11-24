#pragma once
enum PLAYER_ANIMATION_STATES { IDLE = 0, MOVING_LEFT, MOVING_RIGHT, JUMPING, FALLING,SHOOTING_RIGHT, SHOOTING_LEFT,SHOOTING_45 ,SHOOTING_TOP,SITDOWN};

class Player
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
	Player();
	virtual ~Player();
	Clock animationTimer;
	//Accessors
	const bool& getAnimSwitch();
	const sf::Vector2f getPosition() const;
	const sf::FloatRect getGlobalBounds() const;

	//Modifiers
	void setPosition(const float x, const float y);
	void resetVelocityY();
	void resetVelocityX();

	//Functions	
	void resetAnimationTimer();
	void move(const float dir_x, const float dir_y);
	void updatePhysics();
	void updateMovement();
	void updateAnimations();
	void update();
	void render(sf::RenderTarget& target);
	void updateBulllet();


	const sf::Vector2f& getPos() const;
	const sf::FloatRect getBounds() const;
	const bool canAttack();
	void updateAttack();
	//UI
	const int& getHp() const;
	const int& getHpMax() const;
	void setHp(const int hp);
	void loseHp(const int value);
	void attainhp(const int value);
	//ammor
	const int& getAmmor() const;
	const int& getAmmorMax() const;
	void setAmmor(const int hp);
	void loseAmmor(const int value);
	void attainAmmor(const int value);
};