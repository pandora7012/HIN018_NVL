#include "GSSettings.h"

extern int screenWidth; //need get on Graphic engine
extern int screenHeight; //need get on Graphic engine

GSSettings::GSSettings()
{

}


GSSettings::~GSSettings()
{
}



void GSSettings::Init()
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

	//bg setting 
	texture = ResourceManagers::GetInstance()->GetTexture("bg_setting");
	m_Table = std::make_shared<Sprite2D>(model, shader, texture);
	m_Table->Set2DPosition(screenWidth / 2, screenHeight / 2);
	m_Table->SetSize(111, 231);

}

void GSSettings::Exit()
{
}


void GSSettings::Pause()
{

}

void GSSettings::Resume()
{

}


void GSSettings::HandleEvents()
{

}

void GSSettings::HandleKeyEvents(int key, bool bIsPressed)
{

}

void GSSettings::HandleTouchEvents(int x, int y, bool bIsPressed)
{
	for (auto it : m_listButton)
	{
		(it)->HandleTouchEvents(x, y, bIsPressed);
		if ((it)->IsHandle()) break;
	}
}

void GSSettings::Update(float deltaTime)
{
	m_BackGround->Update(deltaTime);
	for (auto it : m_listButton)
	{
		it->Update(deltaTime);
	}
}

void GSSettings::Draw()
{
	m_BackGround->Draw();
	//m_Table->Draw(); 
	for (auto it : m_listButton)
	{
		it->Draw();
	}

}
