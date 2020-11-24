#pragma once
class flyAttack
{
private:
	Texture texture;
	Sprite shape;
	Vector2f direction;
	float movementSpeed;
	void initTexture();
	void initSprite();

public:
	flyAttack(float pos_x, float pos_y,Vector2f dir_xy , float movement_speed);
	virtual ~flyAttack();
	const Vector2f getPosition() const;
	const FloatRect getBounds() const;
	//Accessor

	void update();
	void render(sf::RenderTarget&);
};


