#pragma once
#pragma once
#include "ResourceManagers.h"
#include"AnimationSprite.h"
#include "MainBase.h"

class Slime
{
public:
	Slime();
	~Slime();


	void Init( Vector2 pos);

	void Update(GLfloat deltaTime);
	void Draw();


	Vector2 m_pos;
	std::shared_ptr<AnimationSprite> obj;
	int speed = 100;
	int dmg = 200;
	int hp = 100; 

};