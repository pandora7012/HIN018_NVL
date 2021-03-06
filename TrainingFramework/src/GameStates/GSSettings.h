#pragma once
#include "gamestatebase.h"
#include "GameButton.h"

class GSSettings :
	public GameStateBase
{
public:
	GSSettings();
	~GSSettings();

	void Init();
	void Exit();

	void Pause();
	void Resume();

	void HandleEvents();
	void HandleKeyEvents(int key, bool bIsPressed);
	void HandleTouchEvents(int x, int y, bool bIsPressed);
	void Update(float deltaTime);
	void Draw();

private:
	std::shared_ptr<Sprite2D> m_BackGround;
	std::list<std::shared_ptr<GameButton>>	m_listButton;
	std::shared_ptr<Text>  m_Text, m_Text2;
	std::shared_ptr<Sprite2D> m_Table, m_bg;
};

