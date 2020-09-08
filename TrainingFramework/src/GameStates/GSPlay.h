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

	
	void SetNewPostionForBullet();

private:

	std::shared_ptr<Sprite2D> m_BackGround;
	std::shared_ptr<Text>  m_score;
	std::shared_ptr<Player> player;
	std::shared_ptr<MainBase> base; 
	std::shared_ptr<Slime> slime; 
	
};

