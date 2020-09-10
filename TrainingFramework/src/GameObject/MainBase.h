#pragma once
#pragma once
#pragma once
#include "ResourceManagers.h"
#include"AnimationSprite.h"

class MainBase
{
public:
	MainBase();
	~MainBase();


	void Init(Vector2 pos);

	void Update(GLfloat deltaTime);
	void Draw();

	void setHp(int hp); 
	int getHp(); 

private:
	Vector2 m_basepos;
	std::shared_ptr<Sprite2D> base; 
	int m_hp; 

};