#include "GSPlay.h"
#include <ctime>
#include <cstdlib>


extern int screenWidth; //need get on Graphic engine
extern int screenHeight; //need get on Graphic engine

GSPlay::GSPlay()
{
}


GSPlay::~GSPlay()
{

}

float timer = 0; 
std::string GSPlay::Timer(int timer)
{
	return std::to_string(timer); 
}


void GSPlay::Init()
{
	auto model = ResourceManagers::GetInstance()->GetModel("Sprite2D");
	auto texture = ResourceManagers::GetInstance()->GetTexture("bg_play");

	//BackGround
	auto shader = ResourceManagers::GetInstance()->GetShader("TextureShader");
	m_BackGround = std::make_shared<Sprite2D>(model, shader, texture);
	m_BackGround->Set2DPosition(screenWidth / 2, screenHeight / 2);
	m_BackGround->SetSize(screenWidth, screenHeight);

	//base 
	base = std::make_shared<MainBase>();
	base->Init(Vector2(658, 545));

	// player
	player = std::make_shared<Player>();
	player->Init("Animation//Char//2_north", Vector2(300, 700), 4, 0.1f);

	//score  

	shader = ResourceManagers::GetInstance()->GetShader("TextShader");
	std::shared_ptr<Font> font = ResourceManagers::GetInstance()->GetFont("terminal");
	m_score = std::make_shared< Text>(shader, font, Timer(timer), TEXT_COLOR::RED, 1.0);
	m_score->Set2DPosition(Vector2(5, 25));

	// base hp 
	//std::shared_ptr<Font> font = ResourceManagers::GetInstance()->GetFont("terminal");
	m_baseHp = std::make_shared< Text>(shader, font, std::to_string(base->getHp()), TEXT_COLOR::RED, 1.0);
	m_baseHp->Set2DPosition(Vector2(1000, 25));

}


//create sloime

void GSPlay::createSlime()
{
	srand((int)time(0));
	int res = -10 + rand() % (1290 + 1 + 10); 
	std::shared_ptr<Slime> slime = std::make_shared<Slime>();
	slime->Create(Vector2(res, -15)); 
	slimeList.push_back(slime);
}

void GSPlay::createSlime1()
{
	srand((int)time(0));
	int res = -10 + rand() % (400 + 1 + 10);
	std::shared_ptr<Slime> slime = std::make_shared<Slime>();
	slime->Create(Vector2(-15, res));
	slimeList.push_back(slime);
}

void GSPlay::createSlime2()
{
	srand((int)time(0));
	int res = -10 + rand() % (400 + 1 + 10);
	std::shared_ptr<Slime> slime = std::make_shared<Slime>();
	slime->Create(Vector2(1290, res));
	slimeList.push_back(slime);
}


void GSPlay::Exit()
{

}


void GSPlay::Pause()
{

}

void GSPlay::Resume()
{

}


void GSPlay::HandleEvents()
{

}

void GSPlay::HandleKeyEvents(int key, bool bIsPressed)
{
	player->HandleKeyEvents(key, bIsPressed);
}

void GSPlay::HandleTouchEvents(int x, int y, bool bIsPressed)
{
	

}



float timeforcreate = 0; 

void GSPlay::Update(float deltaTime)
{
	timeforcreate += deltaTime; 
	player->Update(deltaTime);

	// create slime 
	
	if (timeforcreate > 3)
	{
		createSlime() ; 
		createSlime1(); 
		createSlime2(); 
		timeforcreate = 0; 
	}

	for (auto obj : slimeList)
	{
		obj->Update(deltaTime); 
		obj->attackBase(base); 
	}

	// timer update 
	timer += deltaTime ; 
	m_score->setText(Timer(timer));

	// base hp update 
	m_baseHp->setText(std::to_string(base->getHp())); 


	// set slime uprgade 
	if ( (int) timer )
	{

	}

	



	
}

void GSPlay::Draw()
{
	m_BackGround->Draw();
	
	for (auto obj : slimeList)
	{
		obj->Draw();
	}
	
	base->Draw();
	player->Draw();
	m_score->Draw(); 
	m_baseHp->Draw(); 

}

void GSPlay::SetNewPostionForBullet()
{
}