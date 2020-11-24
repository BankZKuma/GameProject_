#pragma once
class MVPfire
{
private:
	Texture texture;
	Sprite shape;
	Vector2f direction;
	float movementSpeed;
	void initTexture();
	void initSprite();

public:
	MVPfire(float pos_x, float pos_y, float dir_x, float dir_y, float movement_speed);
	virtual ~MVPfire();
	const Vector2f getPosition() const;
	const FloatRect getBounds() const;
	//Accessor

	void update();
	void render(sf::RenderTarget&);
};


