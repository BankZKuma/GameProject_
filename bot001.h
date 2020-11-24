#pragma once
class bot001
{
private:
	Sprite sprite;
	Texture textureSheet;
	Clock animationTimer;

	short animState;
	IntRect currentFrame;
	bool animationSwitch;
	bool moveRand();

	unsigned pointCount;
	Texture texture;
	int type;
	float speed;
	int damage;
	int points;
	int hp;
	int hpMax;

	void initVariables();
	void initTexture();
	void initSprite();
	void initAnimations();
public:
	bot001(float dir_x,float dir_y);
	virtual ~bot001();
	//Accessors
	const Vector2f getPosition() const;
	const FloatRect getBounds() const;
	const int& getPoints() const;
	const int& getDamage() const;
	//Animation
	const bool& getAnimSwitch();
	void resetAnimationTimer();
	void updateAnimations();
	//bot ui
	const int& getHp() const;
	const int& getHpMax() const;
	void setHp(const int hp);
	void loseHp(const int value);

	//Functions
	void updateMove();
	void update();
	void render(sf::RenderTarget* target);
};

