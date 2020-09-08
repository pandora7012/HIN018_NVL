#pragma once
#include "Slime.h"

Slime::Slime()
{}

Slime::~Slime()
{}

void Slime::Init(Vector2 pos)
{
	auto model = ResourceManagers::GetInstance()->GetModel("Sprite2D");
	auto texture = ResourceManagers::GetInstance()->GetTexture("Animation//Slime//slime1_front");
	auto shader = ResourceManagers::GetInstance()->GetShader("AnimationShader");
	obj = std::make_shared<AnimationSprite>(model, shader, texture, 4, 0.35f);
	obj->Set2DPosition(pos);
	obj->SetSize(24, 24);
	m_pos = pos;
}

void Slime::Update(GLfloat deltaTime)
{
	obj->Update(deltaTime);
	if (m_pos.x <= 620) {
		m_pos.x += speed * deltaTime; 
	}
	if (m_pos.y <= 470)
	{
		m_pos.y += speed * deltaTime;
	}
	if (m_pos.x > 680)
	{
		m_pos.x -= speed * deltaTime; 
	}
	

	obj->Set2DPosition(m_pos);
}
void Slime::Draw()
{
	obj->Draw();
}