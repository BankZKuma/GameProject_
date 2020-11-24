#pragma once
#include"Player.h"
#include"Enemy.h"
#include"Bullet.h"
#include"bot001.h"
#include<map>
#include"bot001__HP.h"
#include"bot_002.h"
#include"gateAuraIn.h"
#include"MVP.h"
#include"bot004.h"
#include"Electrical.h"
#include"MVPfire.h"
#include"botFly.h"
#include"flyAttack.h"
#include"box.h"
 class Game
{
private:
	//Sound
	void initmenuSound();
	void initRankSound();
	
	
	Music menu;
	Music charp1;
	Music rankShow;
	Music charp2;
	Music charp3;
	Music charp4;
	Music charpMVP;








	//Leaderboard
	Texture leaderBoardtex;
	Sprite leaderBoardsprite;
	void initleaderSprite();
	void initLeaderboard();
	void initBacktomenu();
	Texture backTomenutex;
	Sprite backTomenusprite;
	Texture leaderTex;
	Sprite	leaderSprite;

	//Score
	void intshowScore();
	bool mvpAlive;
	void initScore();
	FILE* fp;
	vector<pair<unsigned int, string>> scoreBoard;
	char temp[255];
	int score[6];
	string name[6];
	Text rank1;
	Text rank2;
	Text rank3;
	Text rank4;
	Text rank5;
	Text rank1_;
	Text rank2_;
	Text rank3_;
	Text rank4_;
	Text rank5_;
	//------------------------------------
	//Menu
	Texture nextStartTex;
	Sprite nexStartSprite;
	Texture startscoreTex;
	Sprite startscoreSprite;
	Texture gameTex;
	Sprite gameSprite;
	Texture exitTex;
	Sprite exitSprite;
	Texture myNameTex;
	Sprite myNameSprite;
	Texture menuTex;
	Sprite menuSprite;
	Texture startTex;
	Sprite startSprite;
	//Enter name screen
	Texture enterNamescreenTex;
	Sprite enterNamescreeSprite;
	//Score
	//For game enter
	void initGameengine();
	bool startoleader;
	bool startogame;
	bool startoexit;
	bool startoScore;
	bool pauseDie;
	bool gameover;
	bool exit;
	//
	//Pause and run
	//-----------------------|
	unsigned points;
	unsigned pointUpdate;
	//-----------------------|
	//view
	View view;
	//GUI--------------------|
	sf::Font font;
	Text pressEsctomenu;
	Font frontEsc;
	Font font2;
	Text pointText;
	Text gameOverText;
	Text HP;
	Text Ammor;
	Text pressTogate;
	Text HPMVP;
	Text AmmorMVP;
	//PlayerGUI---------------
	RectangleShape playerHpBar;
	RectangleShape playerHpBarBack;
	//ammor
	RectangleShape playerAmmorBar;
	RectangleShape playerAmmorBarBack;
	//MVP gui
	RectangleShape MVPHpBar;
	RectangleShape MVPHpBarBack;
	RectangleShape MVPammorBar;
	RectangleShape MVPammorBarBack;
	//-------------------------

	RenderWindow window;
	Event ev;
	Player* player;
	Sprite sprite;
	Texture texture;//1
	Sprite sprite2;
	Texture texture2;//2
	Sprite sprite3;
	Texture texture3;//3
	Sprite sprite4;
	Texture texture4;//4
	Sprite sprite5;
	Texture texture5;//5
	Sprite gate;
	gateAuraIn *gatein;
	Texture gateTex;
	Sprite aurain;
	Texture aurainTex;
	//Enemy UI
	RectangleShape EnemyShootHpbar;//<-----------just use later
	//InnitValuable------------
	void initWindow();
	void initPlayer();
	void initTextures();
	void initTextures2();
	void initEnemy();
	void initBot1();
	void innitBot2();
	void initBot4();
	void initBotfly();
	void initElectri();
	void initGUI();
	void initGate();
	void initSystems();
	void initAurain();
	void initMVP();
	void initBox();
	void initPos();
	//---------------------
	void initETC();


	//Mouse
	Texture mouseTex;
	Sprite mouseSprite;
	void initMouse();
	//---------------------
	void initMenuBackground();
	void enterMenu();
	void leaderBackground();
	void initStart();
	void initExit();
	//void initScore();

	//Pause not die
	void pauseNotdie_();
	void initNotdie();
	bool pauseNotdie;
	bool continueNotdie;
	bool menuNotdie;
	bool exitNotdie;
	bool pausebyNodie;
	Texture notDietex;
	Sprite notDiesprite;

	//Gamemenu
	void initname();
	void initmyName();
	//--------------------

	void initBackground1();
	void initBackground2();
	void initBackground3();
	void initBackground4();
	void initEndState();
	void initView();
	//---------------------------------|
	//---------------------------------|
	//Bullet
	map<string,Texture*> textures;
	vector<Bullet*> bullets;
	//Enemies
	float spawnTimer;
	float spawnTimerMax; 
	vector<Enemy*> enemy;
	Enemy *enemy_;
	//Bot------------------------------|
	float spawnTimer2;
	float spawnTimerMax2;
	vector<bot001*> bot1;
	//Bot001's HP----------------------|
	RectangleShape HP001;
	//Bot002
	float spawnTimer3;
	float spawnTimerMax3;
	int spawnNumBot002;
	vector<bot_002*> bot2;
	//BotFly
	float spawnTimerFly;
	vector<botFly*> botfly;//<--------
	vector<flyAttack*> flyattack;//<--------
	Vector2f posShoot;

	//Bot004
	float spawnTimer5;
	vector<bot004*> bot4;
	//--------------------------------
	//MVP
	vector<Electrical*> electri;
	vector<MVPfire*> fire;
	float spwanMVPfire;
	float spawnElectric;
	MVP *mvp;
	box* Box;
	gateAuraIn *aura;
	void initAura();
	void intiTrowvalue();



	public:
	Game();
	virtual ~Game();
	void updateSound();


	void gamerun();
	//LeaderBoard(Page2)
	void renderShowscore();
	//---------------
	void updateOutput();
	//Score
	void updateHighscore();
	//Functions
	void updateAura();
	void updateGameover();
	void updateBullets();
	void updateMVPfire();
	void updateInput();
	void updatePlayer();
	void updateCollision();
	void update();
	void allUpdate();
	void updateEnemy();
	void updateCombat();
	void updateGate();
	void updateMVP();
	void updatefire();
	void updateBox();
	//bot001&HP
	void updateCombat_bot1();
	void updateBot1();
	void updateGUI();
	void updateEnemyShoot();
	//------------------------
	void updateHP001();
	//bot002-----------------
	void updateCombat_bot2();
	void updateBot2();
	//bot004-----------------
	void updateCombat_bot4();
	void updateBot4();
	//botFly
	void updateBotfly();
	void updateCombat_botFly();
	void updateRedspot();
	void updateBotRedspot();
	
	//MVP
	void mvpmovement();
	void updateCombat_MVP();
	void updateCollios_MVP();
	void updateElectricalCollsion();
	void updateGUIMVP();
	//
	//render
	void renderAura();
	void renderallBackground();
	void renderGUI();
	void renderPlayer();
	void renderEnemyShoot();
	void gateRender();
	void render();
	void renderMVP();
	void renderBox();
	void renderGUIMVP();
	//Background------------
	void renderMenubackground();
	void renderName();
	void renderStart();
	void renderExit();
	void renderScoretext();
	void renderLeader();
	//Menu
	void renderMenuObj();
	void updateClickMenu();
	//Leaderboard
	void renderBacktomenu();
	void renderLeaderboard();
	void updateBacktomenu();

	//---------------------------
	void renderBackground1();
	void renderBackground2();
	void renderBackground3();
	void renderBackground4();
	void renderEndState();
	//----------------------
	void setView();
	void viewMove();
	void defaultView();
	const RenderWindow& getWindow() const;
	void gamePause();
	//Pause not die
	void updateClickalterpausenodie();
	void updatepauseNodie();
	void renderPausenodie();
};
