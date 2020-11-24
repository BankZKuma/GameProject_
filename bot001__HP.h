class bot001__HP
{
public:
	bot001__HP(Vector2f pos001,Vector2f setSize);
	~bot001__HP();
	void render(sf::RenderTarget* target);
private:
	RectangleShape bot001Hpbar;
	RectangleShape bot001HpbarBack;
	void  inintHpbar001();
};

