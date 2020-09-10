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

int timer = 0; 
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

	//score  

	shader = ResourceManagers::GetInstance()->GetShader("TextShader");
	std::shared_ptr<Font> font = ResourceManagers::GetInstance()->GetFont("terminal");
	m_score = std::make_shared< Text>(shader, font, Timer(timer), TEXT_COLOR::RED, 1.0);
	m_score->Set2DPosition(Vector2(5, 25));

	// player
	player = std::make_shared<Player>(); 
	player->Init("Animation//Char//2_north" , Vector2(300,700)  , 4 , 0.1f); 

	//base 
	base = std::make_shared<MainBase>(); 
	base->Init(Vector2(290, 545)); 

	//slime
	srand((int)time(0));
	std::shared_ptr<Slime> slime = std::make_shared<Slime>();
	slime->Init(Vector2(rand() % (540 + 5 + 1), -10));
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

void GSPlay::Update(float deltaTime)
{
	player->Update(deltaTime);
	for (auto obj : slimeList)
	{
		obj->Update(deltaTime); 
	}
	timer += 1 ; 
	m_score->setText(Timer(timer));
	std::cout << timer << std::endl; 
}

void GSPlay::Draw()
{
	m_BackGround->Draw();
	player->Draw(); 
	for (auto obj : slimeList)
	{
		obj->Draw();
	}
	
	base->Draw();
	m_score->Draw(); 

}

void GSPlay::SetNewPostionForBullet()
{
}