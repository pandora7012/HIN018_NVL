#pragma once
#pragma once
#include "ResourceManagers.h"
#include"AnimationSprite.h"


class Bullet
{
public:
	Bullet();
	~Bullet();

	void HandleKeyEvents(int key, bool bIsPressed);
	void HandleTouchEvents(int x, int y, bool bIsPressed);

	void Init(Vector2);

	void Update(GLfloat deltaTime);
	void Draw();



	Vector2 m_pos;
	std::shared_ptr<AnimationSprite> obj;
	int speed = 50;

};