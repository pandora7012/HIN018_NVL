#pragma once
#include "Slime2.h"

Slime2::Slime2()
{}

Slime2::~Slime2()
{}

void Slime2::Create(Vector2 pos)
{
	auto model = ResourceManagers::GetInstance()->GetModel("Sprite2D");
	auto texture = ResourceManagers::GetInstance()->GetTexture("Animation//Slime//slime1_front");
	auto shader = ResourceManagers::GetInstance()->GetShader("AnimationShader");
	int numFrames;
	obj = std::make_shared<AnimationSprite>(model, shader, texture, 4, 0.15f);
	obj->setFrames(4);
	obj->Set2DPosition(pos);
	obj->SetSize(24, 24);
	m_pos = pos;
	this->setState(MOVING);
}

void Slime2::attackBase(std::shared_ptr<MainBase> obj)
{
	obj->setHp(obj->getHp() - this->getDmg());
}


// Get stuff

Vector2 Slime2::getPos()
{
	return m_pos;
}

int Slime2::getDmg()
{
	return m_dmg;
}

int Slime2::getHp()
{
	return m_hp;
}

int Slime2::getSpd()
{
	return m_speed;
}
SlimeState Slime2::getState()
{
	return m_state;
}

// Set stuff 

void Slime2::setPos(Vector2 pos)
{
	m_pos = pos;
}

void Slime2::setDmg(int dmg)
{
	m_dmg = dmg;
}

void Slime2::setSpd(int spd)
{
	m_speed = spd;
}

void Slime2::setHp(int hp)
{
	m_hp = hp;
}
void Slime2::setState(SlimeState state)
{
	m_state = state;
}

void Slime2::changeAnim()
{
	auto texture = ResourceManagers::GetInstance()->GetTexture("Animation//Slime//slime_explode");
	obj->SetTexture(texture);
}


// Update and draw


void Slime2::Update(GLfloat deltaTime)
{
	obj->Update(deltaTime);


	if (m_pos.x <= 220) {
		m_pos.x += m_speed * deltaTime;
	}
	if (m_pos.y <= 670)
	{
		m_pos.y += m_speed * deltaTime;
	}
	if (m_pos.x >= 260)
	{
		m_pos.x -= m_speed * deltaTime;
	}
	if (m_pos.x > 220 && m_pos.x < 260 && m_pos.y >670)
	{
		auto texture = ResourceManagers::GetInstance()->GetTexture("Animation//Slime//slime_explode");
		obj->SetTexture(texture);
		obj->SetSize(37, 41);
		obj->setFrames(8);
		this->setState(ATTACK);
	}

	if (m_hp < 0)
	{
		this->setState(DIE);
	}

	obj->Set2DPosition(m_pos);
}
void Slime2::Draw()
{
	obj->Draw();
}