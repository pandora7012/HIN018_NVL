#pragma once
#include "gamestatebase.h"
#include "Player.h"
#include "MainBase.h"
#include "Slime.h"
#include <time.h> 
#include "GameButton.h"
#include <string.h>




class GSPlay :
	public GameStateBase
{
public:
	GSPlay();
	~GSPlay();

	void Init();
	void Exit();

	void Pause();
	void Resume();

	void HandleEvents();
	void HandleKeyEvents(int key, bool bIsPressed);

	void HandleTouchEvents(int x, int y,  bool  bIsPressed);
	void Update(float deltaTime);
	void Draw();

	std::shared_ptr<AnimationSprite> explodeAnim(Vector2);

	std::string Timer(int timer);

	void createSlime(); 
	void createSlime1();
	void createSlime2();

	
	void SetNewPostionForBullet();

	SoLoud::Wav bg; 
	SoLoud::Wav explode; 
	SoLoud::Wav end; 

	bool check;
private:

	std::shared_ptr<Sprite2D> m_BackGround;
	std::shared_ptr<Text>  m_score;
	std::shared_ptr<Player> player;
	std::shared_ptr<MainBase> base; 
	std::vector<std::shared_ptr<Slime>> slimeList; 
	std::shared_ptr<Text> m_baseHp; 
	std::vector< std::shared_ptr<AnimationSprite>> Anim;  
	std::list<std::shared_ptr<Text> > m_staticText; 
	std::shared_ptr<Text>  m_endtext; 
	std::shared_ptr<Sprite2D> m_endbg;
	std::shared_ptr<GameButton>m_Button;
	std::shared_ptr<Text>  m_endscore; 
	std::shared_ptr<AnimationSprite> a1; 
	std::list<std::shared_ptr< AnimationSprite>>  m_explode; 

	
};

