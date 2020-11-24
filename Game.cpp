#include "stdafx.h"
#include "Game.h"
void Game::initmenuSound()
{
	this->menu.openFromFile("Sound/mainmenusong.ogg");
	this->menu.setPitch(1);
	this->menu.setVolume(10);
	this->menu.setLoop(true);
}
void Game::initRankSound()
{
	this->rankShow.openFromFile("Sound/leadersong.ogg");
	this->rankShow.setVolume(10);
}
void Game::initleaderSprite()
{
	this->leaderTex.loadFromFile("Texture/scoreboard_.png");
	this->leaderSprite.setTexture(this->leaderTex);
	this->leaderSprite.setPosition(-2350, 150);
	this->leaderSprite.setScale(.5, .5);
}
void Game::initLeaderboard()
{
	this->leaderBoardtex.loadFromFile("Texture/scoreleader.jpg");
	this->leaderBoardsprite.setTexture(this->leaderBoardtex);
	this->leaderBoardsprite.setPosition(-3070, -10);
	this->leaderBoardsprite.setScale(3, 3);
}
void Game::initBacktomenu()
{
	this->backTomenutex.loadFromFile("Texture/backtomenu.png");
	this->backTomenusprite.setTexture(this->backTomenutex);
	this->backTomenusprite.setPosition(-2900, 100);
	this->backTomenusprite.setScale(1, 1);
}
void Game::initGameengine()
{
	this->startoexit = true;
	this->startogame = true;
	this->startoleader = true;
	this->pauseDie = true;
	this->gameover = true;
	this->startoScore = true;
	this->exit=true;
	this->mvpAlive = true;
}
void Game::initWindow()
{
	this->window.create(sf::VideoMode(1500, 900), "!!!Bang Bang You Die!!!", Style::Close| Style::Titlebar);
	this->window.setFramerateLimit(60);
	this->window.setVerticalSyncEnabled(false);
}
void Game::initPlayer()
{
	this->player = new Player();
}

void Game::initTextures()
{
	this->textures["BULLET"] = new Texture();
	this->textures["BULLET"]->loadFromFile("Texture/bulletred.png");
}
void Game::initGUI()
{
	//Load font
	if (!this->font.loadFromFile("otf.otf"))
		std::cout << "ERROR::GAME::Failed to load font" << "\n";
	this->font2.loadFromFile("8bit_ttf.ttf");
	//Init potext
	this->pointText.setPosition(1000.f, 25.f);
	this->pointText.setFont(this->font2);
	this->pointText.setCharacterSize(50);
	this->pointText.setString("test");
	//State annouce
	this->pressTogate.setFont(this->font2);
	this->pressTogate.setCharacterSize(50);
	this->pressTogate.setString("");
	this->pressTogate.setPosition(800.f, 820.f);

	this->pressEsctomenu.setFont(this->font); 
	this->pressEsctomenu.setCharacterSize(200);
	this->pressEsctomenu.setString("Press:ESC:to:Escape");
	this->pressEsctomenu.setPosition(270,210);

	this->gameOverText.setFont(this->font);
	this->gameOverText.setCharacterSize(300);
	this->gameOverText.setFillColor(Color::Red);
	this->gameOverText.setString("Game Over!");
	this->gameOverText.setPosition(
	this->window.getSize().x/2.0f- this->gameOverText.getGlobalBounds().width / 2.f,
	this->window.getSize().y/2.0f - this->gameOverText.getGlobalBounds().height / 2.f);

	//Init player GUI
	//--------------------------------------------------------------
	this->playerHpBar.setSize(Vector2f(300.f, 20.f));
	this->playerHpBar.setFillColor(Color::Red);
	this->playerHpBar.setPosition(Vector2f(220.f, 15.f));
	this->playerHpBarBack = this->playerHpBar;
	this->playerHpBarBack.setFillColor(Color(25, 25, 25, 200));
	//--------------------------------------------------------------
	this->playerAmmorBar.setSize(Vector2f(300.f, 20.f));
	this->playerAmmorBar.setFillColor(Color::Blue);
	this->playerAmmorBar.setPosition(Vector2f(220.f, 75.f));
	this->playerAmmorBarBack = this->playerAmmorBar;
	this->playerAmmorBarBack.setFillColor(Color(25, 25, 25, 200));
	//-------------------------------------------------------------
	//HP
	this->HP.setFont(this->font2);
	this->HP.setPosition(130, 10);
	this->HP.setCharacterSize(30);
	this->HP.setString("HP :");
	//Ammor
	this->Ammor.setFont(this->font2);
	this->Ammor.setPosition(10, 70);
	this->Ammor.setCharacterSize(30);
	this->Ammor.setString("AMMOR :");

	//---------------------------------------------------------------------------------------
	//MVP(HP)
	this->HPMVP.setFont(this->font2);
	this->HPMVP.setPosition(1020, 800);//<-----------------(Edit)-
	this->HPMVP.setCharacterSize(30);
	this->HPMVP.setString("HP :");
	//HP&&Ammor Bar(MVP)
	this->MVPHpBar.setSize(Vector2f(300.f, 20.f));
	this->MVPHpBar.setFillColor(Color::Red);
	this->MVPHpBar.setPosition(Vector2f(1120.f, 805.f));//<-----------------
	this->MVPHpBarBack = this->MVPHpBar;
	this->MVPHpBarBack.setFillColor(Color(25, 25, 25, 200));
}
void Game::initGate()
{
	this->gateTex.loadFromFile("Texture/gateNoback.png");
	this->gate.setTexture(this->gateTex);
	this->gate.setPosition(18000, 200);
	this->gate.setScale(5, 5);
}
void Game::initMouse()
{
	this->mouseTex.loadFromFile("Texture/mouse.png");
	this->mouseSprite.setTexture(this->mouseTex);
	this->mouseSprite.setScale(1, 1);
}
void Game::initMenuBackground()
{
	this->menuTex.loadFromFile("Texture/menu_.jpg");
	this->menuSprite.setTexture(this->menuTex);
	this->menuSprite.setScale(1,1);
	this->menuSprite.setPosition(-5000,-10);
}
void Game::initStart()
{
	this->startTex.loadFromFile("Texture/start.png");
	this->startSprite.setTexture(this->startTex);
	this->startSprite.setScale(2, 2);
	this->startSprite.setPosition(-4500, 400);
}
void Game::initExit()
{
	this->exitTex.loadFromFile("Texture/exit.png");
	this->exitSprite.setTexture(this->exitTex);
	this->exitSprite.setScale(2, 2);
	this->exitSprite.setPosition(-4200, 400);
}
void Game::intshowScore()
{
	this->rank1.setFont(this->font2);
	this->rank2.setFont(this->font2);
	this->rank3.setFont(this->font2);
	this->rank4.setFont(this->font2);
	this->rank5.setFont(this->font2);
	this->rank1.setCharacterSize(32);
	this->rank2.setCharacterSize(32);
	this->rank3.setCharacterSize(32);
	this->rank4.setCharacterSize(32);
	this->rank5.setCharacterSize(32);
	this->rank1.setPosition(-2500, 400);
	this->rank2.setPosition(-2500, 500);
	this->rank3.setPosition(-2500, 600);
	this->rank4.setPosition(-2500, 700);
	this->rank5.setPosition(-2500, 800);
	this->rank1.setString(scoreBoard[4].second);
	this->rank2.setString(scoreBoard[3].second);
	this->rank3.setString(scoreBoard[2].second);
	this->rank4.setString(scoreBoard[1].second);
	this->rank5.setString(scoreBoard[0].second);
	//---------------------------------------
	this->rank1_.setFont(this->font2);
	this->rank2_.setFont(this->font2);
	this->rank3_.setFont(this->font2);
	this->rank4_.setFont(this->font2);
	this->rank5_.setFont(this->font2);
	this->rank1_.setCharacterSize(32);
	this->rank2_.setCharacterSize(32);
	this->rank3_.setCharacterSize(32);
	this->rank4_.setCharacterSize(32);
	this->rank5_.setCharacterSize(32);
	this->rank1_.setPosition(-2050, 400);
	this->rank2_.setPosition(-2050, 500);
	this->rank3_.setPosition(-2050, 600);
	this->rank4_.setPosition(-2050, 700);
	this->rank5_.setPosition(-2050, 800);
	this->rank1_.setString(to_string(scoreBoard[4].first));
	this->rank2_.setString(to_string(scoreBoard[3].first));
	this->rank3_.setString(to_string(scoreBoard[2].first));
	this->rank4_.setString(to_string(scoreBoard[1].first));
	this->rank5_.setString(to_string(scoreBoard[0].first));
}
void Game::initScore()
{
	this->startscoreTex.loadFromFile("Texture/scoremenu.png");
	this->startscoreSprite.setTexture(this->startscoreTex);
	this->startscoreSprite.setScale(2, 2);
	this->startscoreSprite.setPosition(-3800, 150);
}
void Game::pauseNotdie_()
{
	this->notDietex.loadFromFile("Texture/Pausegame_.png");
	this->notDiesprite.setTexture(this->notDietex);
	this->notDiesprite.setPosition(this->window.getSize().x / 2+
		450, this->window.getPosition().y / 2+300);
	this->notDiesprite.setScale(1, 1);
}
void Game::initNotdie()
{
	this->pausebyNodie = true;
	this->exitNotdie = true;
	this->continueNotdie = true;
	this->menuNotdie = true;
	this->pauseNotdie = true;
}
void Game::initBackground1()
{
	this->texture.loadFromFile("Texture/background_2.png");
	this->sprite.setTexture(this->texture);
	this->sprite.scale(5, 2);
	this->sprite.setPosition(this->player->getPosition().x -
		this->window.getSize().x / 2,this->player->getPosition().y);
}

void Game::initBackground2()
{
	this->texture2.loadFromFile("Texture/school.jpg");
	this->sprite2.setTexture(this->texture2);
	this->sprite2.scale(5, 2);
	this->sprite2.setPosition(5603,-10);
}

void Game::initBackground3()
{
	this->texture3.loadFromFile("Texture/walking_street.jpg");
	this->sprite3.setTexture(this->texture3);
	this->sprite3.setPosition(10652,-120);
	this->sprite3.scale(5, 3);
}

void Game::initBackground4()
{
	this->texture4.loadFromFile("Texture/background_5.png");
	this->sprite4.setTexture(this->texture4);
	this->sprite4.setPosition(15750,-120);
	this->sprite4.scale(5, 2);
}

void Game::initEndState()
{
	this->texture5.loadFromFile("Texture/valley_of_end.gif");
	this->sprite5.setTexture(this->texture5);
	this->sprite5.setPosition(19550, -20);
	this->sprite5.scale(4, 2.5);
}

void Game::initView()
{
	this->view.setSize(window.getSize().x,window.getSize().y);
}

void Game::initname()
{
	this->gameTex.loadFromFile("Texture/gamename_.png");
	this->gameSprite.setTexture(this->gameTex);
	this->gameSprite.setScale(3, 3);
	this->gameSprite.setPosition(-5000, 50);
}

void Game::initmyName()
{
	this->myNameTex.loadFromFile("Texture/name.png");
	this->myNameSprite.setTexture(this->myNameTex);
	this->myNameSprite.setScale(1, 1);
	this->myNameSprite.setPosition(-5050, 650);
}

void Game::initSystems()
{
	this->points = 0;
}

void Game::initAurain()
{
	this->player->setPosition(-4240, 0);
	this->aurainTex.loadFromFile("Texture/magic_No.png");
	this->aurain.setTexture(this->aurainTex);
	this->aurain.setPosition(18700, 500);
	this->aurain.setScale(.1, 1);
}

void Game::initMVP()
{
	this->mvp = new MVP();
}
void Game::initBox()
{
	this->Box = new box();
}
void Game::initPos()
{
	for (size_t i = 0; i < this->botfly.size(); i++)
	{
		for (size_t i = 0; i < this->flyattack.size(); i++)
		{
			this->posShoot = ((this->botfly[i]->getPosition() -this->flyattack[i]->getPosition()) /
				sqrt(pow(this->botfly[i]->getPosition().x-this->flyattack[i]->getPosition().x,2)
					+ pow(this->botfly[i]->getPosition().y - this->flyattack[i]->getPosition().y, 2)));
		}
	}
}
void Game::initEnemy()
{
	this->spawnTimerMax = 500.f;
	this->spawnTimer = this->spawnTimerMax;
}
void Game::initBot1()
{
	this->spawnTimerMax2 = 500.f;
	this->spawnTimer2 = this->spawnTimerMax2;
}
void Game::innitBot2()
{
	//this->spawnTimerMax3 = 500.f;
	this->spawnTimer3 = 0;
}
void Game::initBot4()
{
	this->spawnTimer5 = 0;
}
void Game::initBotfly()
{
	this->spawnTimerFly = 0;
}
void Game::initElectri()
{
	this->spawnElectric = 0;
}
void Game::initAura()
{
	this->aura = new gateAuraIn();
}
Game::Game()
{

	this->initmenuSound();
	this->initRankSound();



	this->intiTrowvalue();
	//Leaderboard
	this->initLeaderboard();
	this->initBacktomenu();
	this->initleaderSprite();
	this->intshowScore();

	//Menu
	this->initStart();
	this->initname();
	this->initMenuBackground();	
	this->initGameengine();
	this->initExit();
	this->initmyName();
	this->initScore();
	//PauseNotdie
	this->initNotdie();
	this->pauseNotdie_();
	//--------------------
	this->initAura();
	this->initWindow();
	this->initPlayer();
	this->initMVP();
	this->initElectri();
	this->initTextures();
	this->initBackground1();
	this->initBackground2();
	this->initBackground3();
	this->initBackground4();
	this->initGate();
	this->initAurain();
	this->initEndState();
	this->initView();
	//Add after
	this->initGUI();
	this->initEnemy();
	this->initSystems();
	this->initBox();
	//Mouse
	this->initMouse();
}

Game::~Game()
{
	delete this->aura;
	delete this->player;
	delete this->mvp;
	delete this->Box;
	for (auto& i : this->textures)
	{
		delete i.second;
	}

	//Delete bullets
	for (auto* i : this->bullets)
	{
		delete i;
	}
	//---------------------------
	//Delete bot1&&bot_HP
	for (auto* i : this->bot1)
	{
		delete i;
		//---------------------------
	}
	//Bot2
	for (auto* i : this->bot2)
	{
		delete i;
	}
	//Bot4
	for (auto* i : this->bot4)
	{
		delete i;
	}
	//mvp acccer
	for (auto* i : this->electri)
	{
		delete i;
	}
	for (auto* i : this->fire)
	{
		delete i;
	}
	//botFly
	for (auto* i : this->botfly)
	{
		delete i;
	}
}
void Game::updateSound()
{
	menu.play();
	//rankShow.play();
}
void Game::gamerun()
{
	this->updateSound();
	while (this->window.isOpen()&&this->exit==true)

	{
		this->window.setMouseCursorVisible(false);
		cout << Mouse::getPosition().x << "|" << Mouse::getPosition().y << endl;
		this->update();
		this->render();
	}
}
void Game::updateAura()
{
	this->aura->update();
}
void Game::updateGameover()
{
	if (this->player->getHp() <= 0)
		this->gameover = false;
}
void Game::updateBullets()
{
	unsigned counter = 0;
	for (auto* bullet : this->bullets)
	{
		bullet->update();

		//Bullet culling (top of screen)
		if (bullet->getBounds().top + bullet->getBounds().height < 0.f)
		{
			//Delete bullet
			delete this->bullets.at(counter);
			this->bullets.erase(this->bullets.begin() + counter);
		}

		++counter;
	}
}
void Game::updatefire()
{
	for (int i = 0; i < this->fire.size(); i++) {
		this->fire[i]->update();
		if (this->fire[i]->getBounds().intersects(this->player->getBounds())) {
			this->player->loseAmmor(5);
			if (this->player->getAmmor() < 0) {
				this->player->loseHp(5);
			}
			this->fire.erase(fire.begin() + i);
		}
	}
}
void Game::updateBox()
{
	this->Box->update();
	if (this->player->getGlobalBounds().intersects(this->Box->getGlobalBounds()))
	{
		this->Box->loseHp(100);
		this->player->setHp(100);
		this->player->setAmmor(100);
	}
}
void Game::updateMVPfire()
{
	if (abs(this->player->getPosition().x-this->mvp->getPosition().x)<=500&&this->mvp->canAttack())
	{
		this->fire.push_back(
			new MVPfire(
				this->mvp->getPos().x ,
				this->mvp->getPos().y + (this->mvp->getBounds().height / 2)+rand()%100,
				-5.f,
				0.f,
				5.f
			)
		);
	}
}

void Game::updateInput()
{
	
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && this->player->canAttack())
	{
		this->bullets.push_back(
			new Bullet(
				this->textures["BULLET"],
				this->player->getPos().x + this->player->getBounds().width / 2.f,
				this->player->getPos().y + this->player->getBounds().height / 2.f,
				5.f,
				0.f,
				5.f
			)
		);
	}
	else if (Keyboard::isKeyPressed(Keyboard::Left) && this->player->canAttack())
	{
		this->bullets.push_back(
			new Bullet(
				this->textures["BULLET"],
				this->player->getPos().x + this->player->getBounds().width / 2.f,
				this->player->getPos().y + this->player->getBounds().height / 2.f,
				-5.f,
				0.f,
				5.f
			)
		);
	}
	else if (Keyboard::isKeyPressed(Keyboard::Key::Up) && this->player->canAttack())
	{
		this->bullets.push_back(
			new Bullet(
				this->textures["BULLET"],
				this->player->getPos().x + this->player->getBounds().width / 2.f,
				this->player->getPos().y + this->player->getBounds().height / 2.f,
				-5.f,
				5.f,
				5.f
			)
		);
	}
}
void Game::updateGUI()
{
	//cout << this->points << endl;
	std::stringstream ss;
	stringstream  to;

	{
		to << "Press|Enter";
	this->pressTogate.setString(to.str());
	}

	ss << "SCORE " << this->points;

	this->pointText.setString(ss.str());
	//Update player GUI
	float hpPercent = static_cast<float>(this->player->getHp()) / this->player->getHpMax();
	this->playerHpBar.setSize(sf::Vector2f(300.f * hpPercent, this->playerHpBar.getSize().y));
	//Update ammor
	float ammorPercent = static_cast<float>(this->player->getAmmor()) / this->player->getAmmorMax();
	this->playerAmmorBar.setSize(sf::Vector2f(300.f * ammorPercent, this->playerAmmorBar.getSize().y));
}
void Game::updatePlayer()
{
	this->player->update();
}
void Game::updateEnemy()
{
	//Spawning
	this->spawnTimer += 50.f;
	if (this->spawnTimer >= this->spawnTimerMax)
	{
		this->spawnNumBot002++;
		this->enemy.push_back(new Enemy(rand() % 19650, 0.f));
		this->spawnTimer = 0.f;
	}

	//Update
	unsigned counter = 0;
	for (auto* enemies : this->enemy)
	{
		enemies->update();
		//Bullet culling (top of screen)
		if (enemies->getBounds().top > this->window.getSize().y)
		{
			//Delete enemy
			delete this->enemy.at(counter);
			this->enemy.erase(this->enemy.begin() + counter);
		}
		//Enemy player collision
		else if (enemies->getBounds().intersects(this->player->getBounds()))
		{
			this->player->loseAmmor(this->enemy.at(counter)->getDamage());
			if (this->player->getAmmor() <=0) {
				this->player->loseHp(this->enemy.at(counter)->getDamage());
			}
			delete this->enemy.at(counter);
			this->enemy.erase(this->enemy.begin() + counter);
		}

		++counter;
	}
}
void Game::updateCombat()
{
	for (int i = 0; i < this->enemy.size(); ++i)
	{
		bool enemy_deleted = false;
		for (size_t k = 0; k < this->bullets.size() && enemy_deleted == false; k++)
		{
			if (this->enemy[i]->getBounds().intersects(this->bullets[k]->getBounds()))
			{
				this->points += this->enemy[i]->getPoints();

				delete this->enemy[i];
				this->enemy.erase(this->enemy.begin() + i);

				delete this->bullets[k];
				this->bullets.erase(this->bullets.begin() + k);

				enemy_deleted = true;
			}
		}
	}
}
void Game::updateGate()
{
	if (this->player->getGlobalBounds().intersects(this->aurain.getGlobalBounds()) 
		&& Keyboard::isKeyPressed(Keyboard::Return))
	{
		this->player->setPosition(20000, 804);
	}
}
void Game::updateMVP()
{
	this->mvp->update();
}
void Game::updateCombat_bot1()
{	
	for (int i = 0; i < this->bot1.size(); ++i)
	{
		bool bot1_deleted = false;
		for (size_t k = 0; k < this->bullets.size() && bot1_deleted == false; k++)
		{
			if (this->bot1[i]->getBounds().intersects(this->bullets[k]->getBounds()))
			{
				this->bot1[i]->loseHp(rand()%10+15);
				if(this->bot1[i]->getHp()<=0)
				{this->points += this->bot1[i]->getPoints();
				delete this->bot1[i];
				this->bot1.erase(this->bot1.begin() + i);
				}
				
				delete this->bullets[k];
				this->bullets.erase(this->bullets.begin() + k);

				bot1_deleted = true;
			}
		}
	}
}

void Game::intiTrowvalue()
{
	this->fp = fopen("score/score.txt", "r");
	for (int i = 0; i < 5; i++) {
		fscanf(fp, "%s", &this->temp);
		this->name[i] = this->temp;
		fscanf(fp, "%d", &this->score[i]);
		this->scoreBoard.push_back(make_pair(this->score[i], this->name[i]));
	}
	sort(this->scoreBoard.begin(), this->scoreBoard.end());
	fclose(this->fp);
		this->score[5] = this->pointUpdate;
		this->name[5] = "GREEK";
		this->scoreBoard.push_back(make_pair(this->score[5], this->name[5]));
		sort(this->scoreBoard.begin(), this->scoreBoard.end());
		this->fp = fopen("score/score.txt", "w");
		for (int i = 4; i >= 0; i--) {
			strcpy(this->temp, this->scoreBoard[i].second.c_str());
			fprintf(this->fp, "%s %d\n", this->temp, this->scoreBoard[i].first);
		}
		fclose(this->fp);
}

void Game::renderShowscore()
{
	this->window.draw(this->rank1);
	this->window.draw(this->rank2);
	this->window.draw(this->rank3);
	this->window.draw(this->rank4);
	this->window.draw(this->rank5);
	this->window.draw(this->rank1_);
	this->window.draw(this->rank2_);
	this->window.draw(this->rank3_);
	this->window.draw(this->rank4_);
	this->window.draw(this->rank5_);
}
void Game::updateOutput()
{
	this->score[5] = 1000;
	this->name[5] = "GREEK";
	this->scoreBoard.push_back(make_pair(this->score[5], this->name[5]));
	sort(this->scoreBoard.begin(), this->scoreBoard.end());
	this->fp = fopen("score/score.txt", "w");
	for (int i = 4; i >= 0; i--) {
		strcpy(this->temp, this->scoreBoard[i].second.c_str());
		fprintf(this->fp, "%s %d\n", this->temp, this->scoreBoard[i].first);
	}
	fclose(this->fp);
}
void Game::updateBot1()
{
	this->spawnTimer2 += 5.f;
	if ((this->spawnTimer2 >= this->spawnTimerMax)&& this->player->getPosition().x > 0
		&& this->player->getPosition().x <= 5500)
	{
		this->bot1.push_back(new bot001(rand() % 5590 + this->player->getPosition().x +
			this->window.getSize().x / 2, 1000.f));//spawn []<----
		this->spawnTimer2 = 0.f;
	}
	//Update
	unsigned counter = 0;
	for (auto* bot_1 : this->bot1)
	{
		bot_1->update();
		//Bullet culling (top of screen)
		if (bot_1->getBounds().top > this->window.getSize().y)
		{
			//Delete enemy
			delete this->bot1.at(counter);
			this->bot1.erase(this->bot1.begin() + counter);
		}
		//Enemy player collision
		else if (bot_1->getBounds().intersects(this->player->getBounds()))
		{
			if (this->player->getPosition().x <= 5590)
			{
				this->player->loseAmmor(1);
				if (this->player->getAmmor() <= 0) {
					this->player->loseHp(1);
				}
			}
		}

		++counter;
	}
}
void Game::updateCombat_bot2()
{
	for (int i = 0; i < this->bot2.size(); ++i)
	{
		bool bot2_deleted = false;
		for (size_t k = 0; k < this->bullets.size() && bot2_deleted == false; k++)
		{
			if (this->bot2[i]->getBounds().intersects(this->bullets[k]->getBounds()))
			{
				this->bot2[i]->loseHp(rand()%20+10);
				if (this->bot2[i]->getHp() <= 0)
				{
					this->points += this->bot2[i]->getPoints();
					delete this->bot2[i];
					this->bot2.erase(this->bot2.begin() + i);
				}

				delete this->bullets[k];
				this->bullets.erase(this->bullets.begin() + k);

				bot2_deleted = true;
			}
		}
	}
}
void Game::updateBot2()
{
	if (this->spawnTimer3 < 50)
		this->spawnTimer3++;
	if (this->spawnTimer3 >= 50) {
	this->bot2.push_back(new bot_002(rand() % 10650 +
		this->player->getPosition().x + this->window.getSize().x,
		1000.f));//spawn []<----
	this->spawnTimer3 = 0.f;
}

	//Update
	unsigned counter = 0;
	for (auto* bot_2 : this->bot2)
	{
		bot_2->update();
		//Bullet culling (top of screen)
		if (bot_2->getBounds().top > this->window.getSize().y)
		{
			//Delete enemy
			delete this->bot2.at(counter);
			this->bot2.erase(this->bot2.begin() + counter);
		}
		//Enemy player collision
		else if (bot_2->getBounds().intersects(this->player->getBounds()))
		{
			if (this->player->getPosition().x >= 5590&&this->player->getPosition().x<= 10650)
			{
				this->player->loseAmmor(1);
				if (this->player->getAmmor() <= 0) {
					this->player->loseHp(1);
				}
			}
		}
		++counter;
	}
}
void Game::updateCombat_bot4()
{
	for (int i = 0; i < this->bot4.size(); ++i)
	{
		bool bot4_deleted = false;
		for (size_t k = 0; k < this->bullets.size() && bot4_deleted == false; k++)
		{
			if (this->bot4[i]->getBounds().intersects(this->bullets[k]->getBounds()))
			{
				this->bot4[i]->loseHp(rand() % 20 + 10);
				if (this->bot4[i]->getHp() <= 0)
				{
					this->points += this->bot4[i]->getPoints();
					delete this->bot4[i];
					this->bot4.erase(this->bot4.begin() + i);
				}

				delete this->bullets[k];
				this->bullets.erase(this->bullets.begin() + k);

				bot4_deleted = true;
			}
		}
	}
}
void Game::updateBot4()

{
	if (this->spawnTimer5 < 50)
		this->spawnTimer5++;
	if (this->spawnTimer5 >= 50) {
		this->bot4.push_back(new bot004(rand() % 10650 + this->player->getPosition().x +
			this->window.getSize().x,
			1000.f));//spawn []<----
		this->spawnTimer5 = 0.f;
	}

	//Update
	unsigned counter = 0;
	for (auto* bot_4 : this->bot4)
	{
		bot_4->update();
		//Bullet culling (top of screen)
		if (bot_4->getBounds().top > this->window.getSize().y)
		{
			//Delete enemy
			delete this->bot4.at(counter);
			this->bot4.erase(this->bot4.begin() + counter);
		}
		//Enemy player collision
		else if (bot_4->getBounds().intersects(this->player->getBounds()))
		{
			if (this->player->getPosition().x >= 10650 && this->player->getPosition().x <= 15740)
			{
				this->player->loseAmmor(1);
				if (this->player->getAmmor() <= 0) {
					this->player->loseHp(1);
				}
			}
		}
		++counter;
	}
}
void Game::updateBotfly()
{
	if (this->spawnTimerFly < 300)
		this->spawnTimerFly++;
	if (this->spawnTimerFly >= 300) {
		this->botfly.push_back(new botFly(rand()%19516 + 
			this->player->getPosition().x + 
			this->window.getSize().x/1.5f, 1000.f));//spawn []<----
		this->spawnTimerFly = 0.f;
	}

	//Update
	unsigned counter = 0;
	for (auto* botfly_ : this->botfly)
	{
		botfly_->update();
		//Bullet culling (top of screen)
		if (botfly_->getBounds().top > this->window.getSize().y)
		{
			//Delete enemy
			delete this->botfly.at(counter);
			this->botfly.erase(this->botfly.begin() + counter);
		}
		//Enemy player collision
		else if (botfly_->getBounds().intersects(this->player->getBounds()))
		{
				this->player->loseAmmor(1);
				if (this->player->getAmmor() <= 0) {
					this->player->loseHp(1);
			}
		}
		++counter;
	}
}
void Game::updateCombat_botFly()
{
	for (int i = 0; i < this->botfly.size(); ++i)
	{
		bool botfly_deleted = false;
		for (size_t k = 0; k < this->bullets.size() && botfly_deleted == false; k++)
		{
			if (this->botfly[i]->getBounds().intersects(this->bullets[k]->getBounds()))
			{
				this->botfly[i]->loseHp(rand() % 20 + 10);
				if (this->botfly[i]->getHp() <= 0)
				{
					this->points += 10;
					this->points += this->botfly[i]->getPoints();
					delete this->botfly [i] ;
					this->botfly.erase(this->botfly.begin() + i);
				}

				delete this->bullets[k];
				this->bullets.erase(this->bullets.begin() + k);

				botfly_deleted = true;
			}
		}
	}

}

void Game::updateBotRedspot()
{
	for (size_t i = 0; i < this->botfly.size(); i++)
	{
		for (size_t i = 0; i <this->flyattack.size(); i++)
		{
			if (abs(this->player->getPosition().x - this->botfly[i]->getPosition().x) >= 0 &&
				abs(this->player->getPosition().x - this->botfly[i]->getPosition().x) <= 500 
				&& this->botfly[i]->canAttack())
			{
				this->flyattack.push_back(new flyAttack(this->botfly[i]->getPosition().x / 2,
					this->botfly[i]->getPosition().y,
					this->posShoot, 10));
			}
		}
	}



	
}

void Game::mvpmovement()
{
	if (((this->player->getPosition().x + this->player->getGlobalBounds().left)-
		(this->mvp->getPosition().x+this->mvp->getGlobalBounds().left)) >=-1000&&
		((this->player->getPosition().x + this->player->getGlobalBounds().left) - 
			(this->mvp->getPosition().x + this->mvp->getGlobalBounds().left)) <=0)
		this->mvp->updateMovement(-.5, 0);

}
void Game::updateCombat_MVP()
{
		bool MVP_deleted = false;
		for (size_t k = 0; k < this->bullets.size() && MVP_deleted == false; k++)
		{
			if (this->mvp->getBounds().intersects(this->bullets[k]->getBounds()))
			{
				this->mvp->loseAmmor(rand() % 20 + 10);
				if (this->mvp->getAmmor() <= 0)
				{
					this->mvp->loseHp(rand() % 20 + 10);
					if (this->mvp->getHp() <= 0) {
						this->points += 200;
					}
				}
				delete this->bullets[k];
				this->bullets.erase(this->bullets.begin() + k);
				MVP_deleted = true;
			}
		}
}
void Game::updateCollios_MVP()
{
	bool MVP_collsion = false;
	if (this->player->getGlobalBounds().intersects(this->mvp->getGlobalBounds())&&MVP_collsion==false) {
		this->player->loseAmmor(.5);
		if (this->player->getAmmor() <= 0)
			this->player->loseHp(.5);
		MVP_collsion = true;
	}
}
void Game::updateElectricalCollsion()
{
	
	if (this->spawnElectric < 5)
		this->spawnElectric++;
	if (this->spawnElectric>= 5) {
		this->electri.push_back(new Electrical(rand() % 22325+ 20490, 0.f));
		this->spawnElectric = 0.f;
	}

	//Update
	unsigned counter = 0;
	for (auto* elec : this->electri)
	{
		elec->update();
		//Bullet culling (top of screen)
		if (elec->getBounds().top > this->window.getSize().y)
		{
			//Delete enemy
			delete this->electri.at(counter);
			this->electri.erase(this->electri.begin() + counter);
		}
		//Enemy player collision
		else if (elec->getBounds().intersects(this->player->getBounds()))
		{
				this->player->loseAmmor(1);
				if (this->player->getAmmor() <= 0) {
					this->player->loseHp(1);
				}
			}
		}
		++counter;
	}
void Game::updateGUIMVP()
{
	if (this->player->getPosition().x >= 19530 && this->player->getPosition().x <= 22325)
	{
		float hpPercent1 = static_cast<float>(this->mvp->getHp()) / this->mvp->getHpMax();
		this->MVPHpBar.setSize(sf::Vector2f(300.f * hpPercent1, this->MVPHpBar.getSize().y));

	}
}
void Game::updateCollision()
{
	//Collision bottom of screen
	if (this->player->getPosition().y +
		this->player->getGlobalBounds().height > this->window.getSize().y)
	{
		this->player->resetVelocityY();
		this->player->setPosition(
			this->player->getPosition().x,
			this->window.getSize().y - this->player->getGlobalBounds().height);
	}
	else if (this->player->getPosition().x >= 9000&& this->player->getPosition().x<=9555|| 
		this->player->getPosition().x>=9733&& this->player->getPosition().x<=10480) {
		this->player->resetVelocityY();
		this->player->setPosition(
			this->player->getPosition().x,
			730);
	}
	else if (this->player->getPosition().x >= 10715 && this->player->getPosition().x <= 11285)
	{
		this->player->resetVelocityY();
		this->player->setPosition(
			this->player->getPosition().x,
			700);
	}
}

void Game::update()
{
	//Polling window event
	while (this->window.pollEvent(this->ev))
	{
	
		if (this->ev.type == sf::Event::Closed)
			this->window.close();
	} 
	cout << int(this->player->getPosition().x )<< "|" << int(this->player->getPosition().y )<< endl;
	//cout << this->mvp->getAmmor() << "|" << this->mvp->getHp() << endl;
	//cout << this->points << endl;
	this->allUpdate();
}
void Game::allUpdate()
{
	this->pointUpdate = this->points;
	this->updateOutput();
	this->mouseSprite.setPosition(Mouse::getPosition().x-this->window.getPosition().x-30, Mouse::getPosition().y-150);
	//Pause notdie
	if (this->pauseNotdie == true) {
		this->updatepauseNodie();
		this->updatePlayer();
	}
	this->updateBacktomenu();
	//Menu
	this->viewMove();
	this->updateClickMenu();
	this->updateClickalterpausenodie();
	//Leaderboard
	//---------------------

	this->updateCollision();
	this->updateInput();
	if (this->pausebyNodie&&this->gameover&&this->player->getPosition().x>0)
	{
		this->updateGUI();
		this->updateGameover();
		this->updateCombat();
		this->updateGUIMVP();
		this->updateBullets();
		this->updateEnemy();
		this->updateGate();
		this->updateAura();
		this->updatefire();
		this->updateMVPfire();
		if (this->mvp->getHp() > 0 && this->player->getPosition().x >= 20000)
		{
			this->updateMVP();
			this->updateCollios_MVP();
			this->updateElectricalCollsion();
			this->mvpmovement();
			this->updateCombat_MVP();
		}
		//Bot
		if (this->player->getPosition().x > 0 && this->player->getPosition().x < 5960)
		{
			this->updateBot1();
			this->updateCombat_bot1();
		}
		if (this->player->getPosition().x >= 5960 && this->player->getPosition().x <= 10650)
		{
			this->updateBot2();
			this->updateCombat_bot2();
		}
		if (this->player->getPosition().x >= 10650 && this->player->getPosition().x <= 15740)
		{
			this->updateBot4();
			this->updateCombat_bot4();
		}
		if (this->player->getPosition().x >= 0 && this->player->getPosition().x <= 19516)
		{
			this->updateBotfly();
			this->updateCombat_botFly();
			//this->updateRedspot();
		}
		if (this->Box->getHp() > 0)
		{
			this->updateBox();
		}
	}

}
void Game::renderGUI()
{
	if (this->player->getGlobalBounds().intersects(this->aurain.getGlobalBounds()))
		this->window.draw(this->pressTogate);
	this->window.draw(this->pointText);
	this->window.draw(this->playerHpBarBack);
	this->window.draw(this->playerHpBar);
	if (this->player->getAmmor() > 0)
	{
		this->window.draw(this->playerAmmorBar);
		this->window.draw(this->playerAmmorBarBack);
	}
	this->window.draw(this->HP);
	this->window.draw(this->Ammor);
	this->HP.setFillColor(Color(rand() % 255 + 1, rand() % 255 + 1, rand() % 255 + 1, 255));
	this->Ammor.setFillColor(Color(rand() % 255 + 1, rand() % 255 + 1, rand() % 255 + 1, 255));
	this->pointText.setFillColor(sf::Color(rand() % 255 + 1, rand() % 255 + 1, rand() % 255 + 1, 255));
}

void Game::renderAura()
{
	this->aura->render(&this->window);
}

void Game::renderallBackground()
{
	this->renderBackground1();
	this->renderBackground2();
	this->renderBackground3();
	this->renderBackground4();
	this->renderEndState();
}

void Game::renderPlayer()
{
	this->player->render(this->window);
}

void Game::gateRender()
{
	this->window.draw(this->gate);
	//this->window.draw(this->aurain);
}
void Game::renderMVP()
{
	this->mvp->render2(this->window);
}

void Game::renderBox()
{
	this->Box->render2(this->window);
}

void Game::renderGUIMVP()
{
	if (this->player->getPosition().x >= 19530 && this->player->getPosition().x <= 22325&&this->mvp->getHp()>0)
	{
		this->window.draw(this->MVPHpBarBack);
		this->window.draw(this->MVPHpBar);
		this->window.draw(this->HPMVP);
		this->HPMVP.setFillColor(Color(rand() % 255 + 1, rand() % 255 + 1, rand() % 255 + 1, 255));
	}
}

void Game::render()
{
	this->window.clear(Color::Yellow);
	//Render game
	this->setView();
	this->renderallBackground();
	this->gateRender();
	this->renderAura();
	for (auto* bullet : this->bullets)
	{
		bullet->render(&this->window);
	}
	for (auto* enemy : this->enemy)
	{
		enemy->render(&this->window);
	}
	//Bot&&BotHPbar
	if (this->player->getPosition().x > 0 && this->player->getPosition().x <= 5590)
	{
		for (auto* botauto : this->bot1)
		{

			botauto->render(&this->window);
		}
	}
	if (this->player->getPosition().x >= 5591 && this->player->getPosition().x <= 10650)
	{
		for (auto* bot02auto : this->bot2)
		{

			bot02auto->render(&this->window);
		}
	}
	if (this->player->getPosition().x >= 10650 && this->player->getPosition().x <= 15740)
	{
		for (auto* bot04auto : this->bot4)
		{

			bot04auto->render(&this->window);
		}
	}
	if (this->player->getPosition().x >= 19530 &&
		this->player->getPosition().x <= 22325) {
		for (auto* MVP_elec : this->electri)
		{

			MVP_elec->render(&this->window);
		}
	}
	for (auto* fire3 : this->fire)
	{

		fire3->render(this->window);
	}
	if (this->player->getPosition().x >= 0 && 
		this->player->getPosition().x <= 19516) {
		for (auto* bot_fly : this->botfly)
		{

			bot_fly->render(&this->window);
		}
	}
	if (this->player->getPosition().x >= 0 && 
		this->player->getPosition().x <= 19516) {
		for (auto* bot_flyattack :this->flyattack)
		{

			bot_flyattack->render(this->window);
		}
	}
	//---------------------------------
	if (this->mvp->getHp() > 0)
	{
		this->renderMVP();
	}
	if (this->Box->getHp() > 0)
	{
		this->renderBox();
	}
	this->renderPlayer();
	this->renderMenubackground();
	this->renderMenuObj();
	this->renderLeaderboard();
	this->renderBacktomenu();
	this->renderShowscore();
	this->defaultView();
	if (this->player->getHp() <= 0) {
		this->window.draw(this->gameOverText);
	}
	if (this->gameover == false) {
		//cout << "++++++++++";
		this->window.draw(this->pressEsctomenu);
	}
	if(this->player->getPosition().x>0)
	this->renderGUI();
	this->renderGUIMVP();
	this->renderPausenodie();
	if (this->pausebyNodie == false||this->startogame==true||this->startoleader==false) 
	this->window.draw(this->mouseSprite);
	this->window.display();
}
void Game::renderMenubackground()
{
	this->window.draw(this->menuSprite);
}
void Game::renderMenuObj()
{
	this->window.draw(this->gameSprite);
	this->window.draw(this->startSprite);
	this->window.draw(this->exitSprite);
	this->window.draw(this->myNameSprite);
	this->window.draw(this->startscoreSprite);
}
void Game::updateClickMenu()
{
	if (this->exit == true && this->startogame == true&&this->startoleader==true)
	{
		if (Mouse::isButtonPressed(Mouse::Left) &&
			this->startogame == true &&
			(Mouse::getPosition().x >= 725 &&
				Mouse::getPosition().x <= 1100)
			&& (Mouse::getPosition().y >= 530 &&
				Mouse::getPosition().y <= 600))
		{
			this->startogame = false;
			this->player->setPosition(1, 800);
		}
		if (Mouse::isButtonPressed(Mouse::Left) &&
			this->exit == true &&
			(Mouse::getPosition().x >= 1350 &&
				Mouse::getPosition().x <= 1670)
			&& (Mouse::getPosition().y >= 780 &&
				Mouse::getPosition().y <= 880))
		{
			this->exit = false;
		}

		if (Mouse::isButtonPressed(Mouse::Left) &&
			this->startogame == true &&
			(Mouse::getPosition().x >= 1460 &&
				Mouse::getPosition().x <= 1700)
			&& (Mouse::getPosition().y >= 290 &&
				Mouse::getPosition().y <= 540))
		{
			this->startoleader = false;
			this->startogame = false;
			this->player->setPosition(-2200, 800);
		}
		
	}
}
void Game::renderBacktomenu()
{
	this->window.draw(this->backTomenusprite);
	this->window.draw(this->leaderSprite);
}
void Game::renderLeaderboard()
{
	this->window.draw(this->leaderBoardsprite);
}
void Game::updateBacktomenu()
{
		if(Mouse::isButtonPressed(Mouse::Left) &&
			(this->startoleader == false)&&
			(Mouse::getPosition().x >= 190 &&
				Mouse::getPosition().x <= 350)
			&& (Mouse::getPosition().y >= 195 &&
				Mouse::getPosition().y <= 255))
		{
			this->startoleader = true;
			this->startogame = true;
			this->player->setPosition(-2200, 800);
		}
}
void Game::renderBackground1()
{
	this->window.draw(this->sprite);
}
void Game::renderBackground2() 
{
	this->window.draw(this->sprite2);
}

void Game::renderBackground3()
{
	this->window.draw(this->sprite3);
}

void Game::renderBackground4()
{
	this->window.draw(this->sprite4);
}

void Game::renderEndState()
{
	this->window.draw(this->sprite5);
}

void Game::setView()
{
	this->window.setView(this->view);
}

void Game::viewMove()
{
	if (this->player->getPosition().x >= 4830 && this->player->getPosition().x <= 5590)
	{
		this->view.setCenter(4850, 804 - this->window.getSize().y / 3);
	}
	else if ( this->player->getPosition().y <= 804 - window.getSize().y / 1.1) \
	{
		this->view.setCenter(0, this->window.getSize().y / 2 + 54);
	}
	else if (this->player->getPosition().x >= 5590 && this->player->getPosition().x <= 5590 + this->window.getSize().x/2) {
		this->view.setCenter(6380, this->window.getSize().y / 2 + 54);
	}
	 else if (this->player->getPosition().x >= 9900 && this->player->getPosition().x <= 10652)
	{
		this->view.setCenter(9900, 804 - this->window.getSize().y / 3);
	}
	else if (player->getPosition().x >= 10652 && player->getPosition().x <= 10652 + this->window.getSize().x / 2) {
		this->view.setCenter(11478, 804 - this->window.getSize().y / 3);
	}
	else if (this->player->getPosition().x >= 15000 && this->player->getPosition().x <= 15750) {
		this->view.setCenter(15000, 804 - this->window.getSize().y / 3);
	}
	else if (this->player->getPosition().x >= 15750 && this->player->getPosition().x <= 15750 + this->window.getSize().x / 2) {
		this->view.setCenter(16528, 804 - this->window.getSize().y / 3);
	}
	else if (this->player->getPosition().x >= 18786&&this->player->getPosition().x <= 19530) {
		this->view.setCenter(18786, 804 - this->window.getSize().y / 3);
	}
	else if (this->player->getPosition().x >= 19530 && this->player->getPosition().x <= 20320) {
		this->view.setCenter(20320, 804 - this->window.getSize().y / 3);
	}
	else if (this->player->getPosition().x >= 21597)
	{
		this->view.setCenter(21597, 804- this->window.getSize().y / 3);
	}
	else if (this->startogame == true) {
		this->view.setCenter(-4240, 804 - this->window.getSize().y / 3);
	}
	else if (this->startoleader == false) {
		this->view.setCenter(-2200, 804 - this->window.getSize().y / 3);
	}
	else
		this->view.setCenter(this->player->getPosition().x, this->window.getSize().y / 2 + 54);
}
void Game::defaultView()
{
	this->window.setView(this->window.getDefaultView());
}

const RenderWindow& Game::getWindow() const
{
	return this->window;
}

void Game::updateClickalterpausenodie()
{
	if (this->pauseNotdie == false&&this->startoleader==true) {
		if (Mouse::isButtonPressed(Mouse::Left)
			&&(Mouse::getPosition().x>=900
				&&Mouse::getPosition().x<=1075)
			&&(Mouse::getPosition().y>=590&&Mouse::getPosition().y<=640)) {
			this->startogame = true;
			this->player->setPosition(-4240,806);
			this->points = 0;
			this->player->setHp(100);
			this->player->setAmmor(100);
			this->pauseNotdie = true;
			this->pausebyNodie = true;
		}
		if (Mouse::isButtonPressed(Mouse::Left)
			&& (Mouse::getPosition().x >= 730
				&& Mouse::getPosition().x <= 890)
			&& (Mouse::getPosition().y >= 590 && Mouse::getPosition().y <= 640)) {
			this->pausebyNodie = true;
			this->pauseNotdie = true;
		}
		if (Mouse::isButtonPressed(Mouse::Left)
			&& (Mouse::getPosition().x >= 1090
				&& Mouse::getPosition().x <= 1260)
			&& (Mouse::getPosition().y >= 590 && Mouse::getPosition().y <= 640)) {
			this->exit = false;
			this->pausebyNodie = true;
			this->pauseNotdie = true;
		}
	}
}

void Game::updatepauseNodie()
{
	 if (Keyboard::isKeyPressed(Keyboard::Escape)
		 &&this->startogame==false && this->startoleader == true) {
		 this->pauseNotdie = false;
		 this->pausebyNodie = false;
	 }
}

 void Game::renderPausenodie()
 {
	 if(this->pauseNotdie==false)
	 this->window.draw(this->notDiesprite);
 }
