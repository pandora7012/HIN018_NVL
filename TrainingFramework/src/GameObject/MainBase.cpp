#pragma once
#include "MainBase.h"

MainBase::MainBase()
{}

MainBase::~MainBase()
{}

void MainBase::Init(Vector2 pos)
{
	auto model = ResourceManagers::GetInstance()->GetModel("Sprite2D");
	auto texture = ResourceManagers::GetInstance()->GetTexture("base");
	auto shader = ResourceManagers::GetInstance()->GetShader("TextureShader");
	base = std::make_shared<Sprite2D>(model, shader, texture);
	base->Set2DPosition(pos);
	base->SetSize(54, 54);
	m_basepos = pos;
}

void MainBase::Update(GLfloat deltaTime)
{
}
void MainBase::Draw()
{
	base->Draw();
}