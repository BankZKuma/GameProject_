#pragma once
class gateAuraIn
{
private:
	Sprite sprite;
	Texture textureSheet;
	Clock animationTimer;

	short animState;
	IntRect currentFrame;
	bool animationSwitch;

	void initTexture();
	void initSprite();
	void initAnimations();
public:
	gateAuraIn();
	const FloatRect getBounds() const;
	virtual ~gateAuraIn();
	//Accessors
	//Animation
	const bool& getAnimSwitch();
	void resetAnimationTimer();
	void updateAnimations();
	void update();
	void render(RenderTarget* target);
};

