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
	base->Init(Vector2(240, 685));

	// player
	player = std::make_shared<Player>();
	player->Init("Animation//Char//2_north", Vector2(300, 780), 4, 0.1f);

	//score  

	shader = ResourceManagers::GetInstance()->GetShader("TextShader");
	std::shared_ptr<Font> font = ResourceManagers::GetInstance()->GetFont("terminal");
	m_score = std::make_shared< Text>(shader, font,  Timer(timer), TEXT_COLOR::WHILE, 1.0);
	m_score->Set2DPosition(Vector2(5, 55));

	// base hp 
	//std::shared_ptr<Font> font = ResourceManagers::GetInstance()->GetFont("terminal");
	m_baseHp = std::make_shared< Text>(shader, font,  std::to_string(base->getHp()), TEXT_COLOR::RED, 1.0);
	m_baseHp->Set2DPosition(Vector2(400, 55));

	//static text  
	std::shared_ptr<Text> score = std::make_shared<Text>(shader, font, "Score ", TEXT_COLOR::WHILE, 1.0);
	score->Set2DPosition(Vector2(5, 25));
	m_staticText.push_back(score); 

	std::shared_ptr<Text> hpt = std::make_shared<Text>(shader, font, "HP ", TEXT_COLOR::RED, 1.0);
	hpt->Set2DPosition(Vector2(425, 25));
	m_staticText.push_back(hpt);


	// critals ? 
	model = ResourceManagers::GetInstance()->GetModel("Sprite2D"); 
	texture = ResourceManagers::GetInstance()->GetTexture("Animation//crystal1"); 
	shader = ResourceManagers::GetInstance()->GetShader("AnimationShader");
	std::shared_ptr<AnimationSprite> crital = std::make_shared<AnimationSprite>(model, shader, texture, 4, 0.2f);
	crital->Set2DPosition(240, 655); 
	crital->SetSize(10, 24); 
	Anim.push_back(crital); 

	//effect 
	 model = ResourceManagers::GetInstance()->GetModel("Sprite2D");
	//texture = ResourceManagers::GetInstance()->GetTexture("Animation//crystal1");
	 shader = ResourceManagers::GetInstance()->GetShader("AnimationShader");
	 texture = ResourceManagers::GetInstance()->GetTexture("Animation//burning");
	std::shared_ptr<AnimationSprite> burn = std::make_shared<AnimationSprite>(model, shader, texture, 4, 0.2f);
	burn->Set2DPosition(224, 690);
	burn->SetSize(32, 26);
	Anim.push_back(burn);

	std::shared_ptr<AnimationSprite> burn2 = std::make_shared<AnimationSprite>(model, shader, texture, 4, 0.2f);
	burn2->Set2DPosition(265, 700);
	burn2->SetSize(32, 26);
	Anim.push_back(burn2);

	std::shared_ptr<AnimationSprite> burn3 = std::make_shared<AnimationSprite>(model, shader, texture, 4, 0.2f);
	burn3->Set2DPosition(250, 680);
	burn3->SetSize(32, 26);
	Anim.push_back(burn3);

	// after game 
	model = ResourceManagers::GetInstance()->GetModel("Sprite2D");
	texture = ResourceManagers::GetInstance()->GetTexture("bg_play");
	shader = ResourceManagers::GetInstance()->GetShader("TextureShader");
	m_endbg = std::make_shared<Sprite2D>(model, shader, texture);
	m_endbg->Set2DPosition(screenWidth / 2, screenHeight / 2);
	m_endbg->SetSize(screenWidth, screenHeight);

	shader = ResourceManagers::GetInstance()->GetShader("TextShader");
	//std::shared_ptr<Font> font = ResourceManagers::GetInstance()->GetFont("terminal");
	m_endtext = std::make_shared< Text>(shader, font, "YOUR SCORE: ", TEXT_COLOR::BLUE, 1.0);
	m_endtext->Set2DPosition(screenWidth / 2-120, screenHeight / 2);

	shader = ResourceManagers::GetInstance()->GetShader("TextureShader");
	texture = ResourceManagers::GetInstance()->GetTexture("button_ok");
	m_Button = std::make_shared<GameButton>(model, shader, texture);
	m_Button->Set2DPosition(screenWidth / 2, screenHeight / 2 + 250);
	m_Button->SetSize(86, 37);
	m_Button->SetOnClick([]() {
		GameStateMachine::GetInstance()->PopState();
		GameStateMachine::GetInstance()->ChangeState(StateTypes::STATE_Menu);
		});


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
	slime->Create(Vector2(600, res));
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
	m_Button->HandleTouchEvents(x, y, bIsPressed);

}



float timeforcreate = 0; 
int p = 1; 

void GSPlay::Update(float deltaTime)
{
	timeforcreate += deltaTime; 
	player->Update(deltaTime);

	// create slime 
	
	if (timeforcreate > 1.25)
	{
		createSlime() ; 
		createSlime1(); 
		createSlime2(); 
		timeforcreate = 0; 
	}

	for (auto obj : slimeList)
	{
		obj->Update(deltaTime); 
		player->checkShooting(obj); 
	}

	for (int i = 0; i < slimeList.size(); i++)
	{
		if (slimeList[i]->getState() == ATTACK)
		{
			slimeList[i]->attackBase(base); 
			std::cout << slimeList[i]->getDmg() << "   " << slimeList[i]->getSpd() << std::endl ;
			slimeList.erase(slimeList.begin() + i); 
		}
		else if (slimeList[i]->getState() == DIE)
		{
			slimeList.erase(slimeList.begin() + i);
		}
	}


	// timer update 
	if (base->getHp() > 0 ) timer += deltaTime ;
	m_score->setText(Timer(timer));
	//std::cout << timer << std::endl; 

	// base hp update + slime upgrade 

	if ( (int) timer % 30 == 0 )
	{
		for (auto obj : slimeList)
		{
			obj->changeAnim(); 
			obj->setSpd(200); 
			obj->setDmg(500);  
		}
	}
	
	m_baseHp->setText(std::to_string(base->getHp())); 
	


	// Update effect 

	for (auto obj : Anim)
	{
		obj->Update(deltaTime); 
	}
	m_Button->Update(deltaTime); 
	
}

void GSPlay::Draw()
{
	m_BackGround->Draw();
	
	for (auto obj : slimeList)
	{
		obj->Draw();
	}
	//m_explodeAnim->Draw(); 
	base->Draw();
	player->Draw();
	m_score->Draw(); 
	m_baseHp->Draw(); 

	for (auto obj : m_staticText)
	{
		obj->Draw(); 
	}

	// effect update ; 
	Anim[0]->Draw(); 
	
	if ( base->getHp() <2500 & base->getHp() >= 2000 ) 
	{
		Anim[1]->Draw(); 
	}
	else if (base->getHp() < 2000 & base->getHp() >= 1000)
	{
		Anim[1]->Draw();
		Anim[2]->Draw();
	}
	else if ( base->getHp() < 1000 & base->getHp() >= 1)
	{
		Anim[1]->Draw();
		Anim[2]->Draw();
		Anim[3]->Draw();
	}
	else if (base->getHp() <= 0)
	{
		m_endbg->Draw(); 
		m_endtext->Draw(); 
		auto model = ResourceManagers::GetInstance()->GetModel("Sprite2D");
		auto texture = ResourceManagers::GetInstance()->GetTexture("Animation//crystal1");
		auto shader = ResourceManagers::GetInstance()->GetShader("TextShader");
		std::shared_ptr<Font> font = ResourceManagers::GetInstance()->GetFont("terminal");
		m_endscore = std::make_shared< Text>(shader, font, std::to_string((int)timer), TEXT_COLOR::BLUE, 1.0);
		m_endscore->Set2DPosition(screenWidth / 2+40, screenHeight / 2);
		m_endscore->Draw();
		
		m_Button->Draw(); 
		
	}

	
}

void GSPlay::SetNewPostionForBullet()
{
}