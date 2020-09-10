#pragma once
#include "Slime.h"

Slime::Slime()
{}

Slime::~Slime()
{}

void Slime::Create(Vector2 pos)
{
	auto model = ResourceManagers::GetInstance()->GetModel("Sprite2D");
	auto texture = ResourceManagers::GetInstance()->GetTexture("Animation//Slime//slime1_front");
	auto shader = ResourceManagers::GetInstance()->GetShader("AnimationShader");
	int numFrames; 
	obj = std::make_shared<AnimationSprite>(model, shader, texture, 4 , 0.15f);
	obj->setFrames(4); 
	obj->Set2DPosition(pos);
	obj->SetSize(24, 24);
	m_pos = pos;
}



// Get stuff

Vector2 Slime::getPos()
{
	return m_pos; 
}

int Slime::getDmg()
{
	return m_dmg; 
}

int Slime::getHp()
{
	return m_hp; 
}

int Slime::getSpd()
{
	return m_speed; 
}


// Set stuff 

void Slime::setPos(Vector2 pos)
{
	m_pos = pos; 
}

void Slime::setDmg(int dmg)
{
	m_dmg = dmg; 
}

void Slime::setSpd(int spd)
{
	m_speed = spd; 
}

void Slime::setHp(int hp)
{
	m_hp = hp; 
}




// Update and draw


void Slime::Update(GLfloat deltaTime)
{
	obj->Update(deltaTime);
	if (m_pos.x <= 270) {
		m_pos.x += m_speed * deltaTime; 
	}
	if (m_pos.y <= 515)
	{
		m_pos.y += m_speed * deltaTime;
	}
	if (m_pos.x > 310)
	{
		m_pos.x -= m_speed * deltaTime; 
	}
	if (m_pos.x > 270 && m_pos.x <=310 && m_pos.y >515)
	{
		auto texture = ResourceManagers::GetInstance()->GetTexture("Animation//Slime//slime_explode");
		obj->SetTexture(texture);
		obj->SetSize(37, 41); 
		obj->setFrames(8); 
	}

	obj->Set2DPosition(m_pos);
}
void Slime::Draw()
{
	obj->Draw();
}