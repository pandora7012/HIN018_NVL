#include "GSMenu.h"

extern int screenWidth; //need get on Graphic engine
extern int screenHeight; //need get on Graphic engine

GSMenu::GSMenu()
{

}


GSMenu::~GSMenu()
{
}



void GSMenu::Init()
{
	auto model = ResourceManagers::GetInstance()->GetModel("Sprite2D");
	auto texture = ResourceManagers::GetInstance()->GetTexture("bg");

	//BackGround
	auto shader = ResourceManagers::GetInstance()->GetShader("TextureShader");
	m_BackGround = std::make_shared<Sprite2D>(model, shader, texture);
	m_BackGround->Set2DPosition(screenWidth / 2, screenHeight / 2);
	m_BackGround->SetSize(screenWidth, screenHeight);

	//button 

	//play button
	texture = ResourceManagers::GetInstance()->GetTexture("button_play");
	std::shared_ptr<GameButton> button = std::make_shared<GameButton>(model, shader, texture);
	button->Set2DPosition(screenWidth / 2, screenHeight/2);
	button->SetSize(250, 62.5);
	button->SetOnClick([]() {
		GameStateMachine::GetInstance()->ChangeState(StateTypes::STATE_Play);
		});
	m_listButton.push_back(button);

	//exit button
	texture = ResourceManagers::GetInstance()->GetTexture("button_quit");
	button = std::make_shared<GameButton>(model, shader, texture);
	button->Set2DPosition( 1150 , 650);
	button->SetSize(50, 50);
	button->SetOnClick([]() {
		exit(0);
		});
	m_listButton.push_back(button);

	// setting button 
	texture = ResourceManagers::GetInstance()->GetTexture("button_setting");
	button = std::make_shared<GameButton>(model, shader, texture);
	button->Set2DPosition(screenWidth / 2, screenHeight / 2 + 100 );
	button->SetSize(200, 50);
	button->SetOnClick([]() {
		GameStateMachine::GetInstance()->ChangeState(StateTypes::STATE_Settings);
		});
	m_listButton.push_back(button);

	// about button
	texture = ResourceManagers::GetInstance()->GetTexture("button_about");
	button = std::make_shared<GameButton>(model, shader, texture);
	button->Set2DPosition(screenWidth / 2, screenHeight / 2 + 200);
	button->SetSize(200, 50);
	button->SetOnClick([]() {
		GameStateMachine::GetInstance()->ChangeState(StateTypes::STATE_About);
		});
	m_listButton.push_back(button);


	// anim

	texture = ResourceManagers::GetInstance()->GetTexture("Animation//Slime//slime1_front");
	shader = ResourceManagers::GetInstance()->GetShader("AnimationShader");
	std::shared_ptr<AnimationSprite> test = std::make_shared<AnimationSprite>(model, shader, texture, 4, 0.2f);
	test->Set2DPosition(screenWidth / 2 -100, screenHeight / 2+100);
	test->SetSize(25, 25);
	m_listAnimation.push_back(test);

	texture = ResourceManagers::GetInstance()->GetTexture("Animation//Slime//slime1_front");
	//shader = ResourceManagers::GetInstance()->GetShader("AnimationShader");
	std::shared_ptr<AnimationSprite> test2 = std::make_shared<AnimationSprite>(model, shader, texture, 4, 0.2f);
	test2->Set2DPosition(screenWidth / 2 +100, screenHeight / 2 + 100);
	test2->SetSize(25, 25);
	m_listAnimation.push_back(test2);
	
	


	//text game 
	shader = ResourceManagers::GetInstance()->GetShader("TextShader");
	std::shared_ptr<Font> font = ResourceManagers::GetInstance()->GetFont("terminal");
	m_Text_gameName = std::make_shared< Text>(shader, font, "HIGH SCORE: 10s", TEXT_COLOR::YELLOW, 1.0);
	m_Text_gameName->Set2DPosition(Vector2(screenWidth / 2 - 110, 270));
}

void GSMenu::Exit()
{
}


void GSMenu::Pause()
{

}

void GSMenu::Resume()
{

}


void GSMenu::HandleEvents()
{

}

void GSMenu::HandleKeyEvents(int key, bool bIsPressed)
{

}

void GSMenu::HandleTouchEvents(int x, int y, bool bIsPressed)
{
	for (auto it : m_listButton)
	{
		(it)->HandleTouchEvents(x, y, bIsPressed);
		if ((it)->IsHandle()) break;
	}
}

void GSMenu::Update(float deltaTime)
{
	m_BackGround->Update(deltaTime);
	for (auto it : m_listButton)
	{
		it->Update(deltaTime);
	}
	for (auto obj : m_listAnimation)
	{
		obj->Update(deltaTime); 
	}
}

void GSMenu::Draw()
{
	m_BackGround->Draw();
	for (auto it : m_listButton)
	{
		it->Draw();
	}
	for (auto obj : m_listAnimation)
	{
		//obj->Draw(); 
	}
	//m_Text_gameName->Draw();
}
