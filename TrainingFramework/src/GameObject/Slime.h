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

	void Create(Vector2); 

	void Update(GLfloat deltaTime);
	void Draw();

	Vector2 getPos(); 
	int getDmg(); 
	int getSpd(); 
	int getHp(); 

	void setPos(Vector2 pos); 
	void setDmg(int dmg); 
	void setSpd(int spd); 
	void setHp(int hp); 

private :

	Vector2 m_pos;
	std::shared_ptr<AnimationSprite> obj;
	int m_speed = 50;
	int m_dmg = 50;
	int m_hp = 100; 

};