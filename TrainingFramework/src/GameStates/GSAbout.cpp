#include "GSAbout.h"

extern int screenWidth; //need get on Graphic engine
extern int screenHeight; //need get on Graphic engine

GSAbout::GSAbout()
{

}


GSAbout::~GSAbout()
{
}



void GSAbout::Init()
{
	auto model = ResourceManagers::GetInstance()->GetModel("Sprite2D");
	auto texture = ResourceManagers::GetInstance()->GetTexture("bg");

	//BackGround
	auto shader = ResourceManagers::GetInstance()->GetShader("TextureShader");
	m_BackGround = std::make_shared<Sprite2D>(model, shader, texture);
	m_BackGround->Set2DPosition(screenWidth / 2, screenHeight / 2);
	m_BackGround->SetSize(screenWidth, screenHeight);

	// back button 
	texture = ResourceManagers::GetInstance()->GetTexture("button_ok");
	std::shared_ptr<GameButton> button = std::make_shared<GameButton>(model, shader, texture);
	button->Set2DPosition(screenWidth / 2, screenHeight / 2 + 250);
	button->SetSize(86, 37);
	button->SetOnClick([]() {
		GameStateMachine::GetInstance()->PopState();
		});
	m_listButton.push_back(button);


	//logo 
	texture = ResourceManagers::GetInstance()->GetTexture("logo");
	logo = std::make_shared<Sprite2D>(model, shader, texture);
	logo->Set2DPosition(screenWidth / 2, screenHeight / 2 + 95);
	logo->SetSize(150, 150);


	//text 
	shader = ResourceManagers::GetInstance()->GetShader("TextShader");
	std::shared_ptr<Font> font = ResourceManagers::GetInstance()->GetFont("terminal");
	m_Text = std::make_shared< Text>(shader, font, "This game designed by a DOGE", TEXT_COLOR::YELLOW, 1.0);
	m_Text->Set2DPosition(screenWidth / 2-200, screenHeight / 2);
 
	shader = ResourceManagers::GetInstance()->GetShader("TextShader");
	m_Text2 = std::make_shared< Text>(shader, font, "RIP", TEXT_COLOR::YELLOW, 1.0);
	m_Text2->Set2DPosition(screenWidth / 2, screenHeight / 2 - 50);

}

void GSAbout::Exit()
{
}


void GSAbout::Pause()
{

}

void GSAbout::Resume()
{

}


void GSAbout::HandleEvents()
{

}

void GSAbout::HandleKeyEvents(int key, bool bIsPressed)
{

}

void GSAbout::HandleTouchEvents(int x, int y, bool bIsPressed)
{
	for (auto it : m_listButton)
	{
		(it)->HandleTouchEvents(x, y, bIsPressed);
		if ((it)->IsHandle()) break;
	}
}

void GSAbout::Update(float deltaTime)
{
	m_BackGround->Update(deltaTime);
	for (auto it : m_listButton)
	{
		it->Update(deltaTime);
	}
}

void GSAbout::Draw()
{
	m_BackGround->Draw();
	m_Text->Draw();
	m_Text2->Draw();
	logo->Draw();
	for (auto it : m_listButton)
	{
		it->Draw();
	}
}
