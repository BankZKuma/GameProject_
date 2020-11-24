 #ifndef ENEMY_H
#define ENEMY_H
#include<SFML/Graphics.hpp>

class Enemy
{
private:
	Sprite sprite;
	Texture textureSheet;

	short animState;
	IntRect currentFrame;
	bool animationSwitch;


	unsigned pointCount;
	Texture texture;
	int type;
	float speed;
	int damage;
	int points;

	void initVariables();
	void initTexture();
	void initSprite();
	void initAnimations();
public:
	Enemy(float pos_x, float pos_y);
	virtual ~Enemy();
	Clock animationTimer;
	//Accessors
	const FloatRect getBounds() const;
	const int& getPoints() const;
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

#endif //!ENEMY_H