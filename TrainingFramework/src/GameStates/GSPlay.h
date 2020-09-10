#pragma once
#include "gamestatebase.h"
#include "Player.h"
#include "MainBase.h"
#include "Slime.h"


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

	std::string Timer(int timer);

	void createSlime(); 
	void SetNewPostionForBullet();

private:

	std::shared_ptr<Sprite2D> m_BackGround;
	std::shared_ptr<Text>  m_score;
	std::shared_ptr<Player> player;
	std::shared_ptr<MainBase> base; 
	std::vector<std::shared_ptr<Slime>> slimeList; 
	
};

