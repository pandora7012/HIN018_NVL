#pragma once
#pragma once
#include "ResourceManagers.h"
#include"AnimationSprite.h"
#include "MainBase.h"

enum SlimeState
{
	MOVING,
	DIE,
	ATTACK,
};

class Slime
{
public:
	Slime();
	~Slime();

	void Create(Vector2); 

	void Update(GLfloat deltaTime);
	void Draw();

	void changeAnim(); 

	Vector2 getPos(); 
	int getDmg(); 
	int getSpd(); 
	int getHp(); 
	SlimeState getState(); 

	void setPos(Vector2 pos); 
	void setDmg(int dmg); 
	void setSpd(int spd); 
	void setHp(int hp); 
	void setState(SlimeState state); 

	void attackBase(std::shared_ptr<MainBase> obj); 

private :

	Vector2 m_pos;
	std::shared_ptr<AnimationSprite> obj;
	int m_speed = 100;
	int m_dmg = 500;
	int m_hp = 100; 
	SlimeState m_state; 

};