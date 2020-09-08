#include "Bullet.h"
#include "Player.h" 

Bullet::Bullet()
{

}

Bullet::~Bullet()
{

}

void Bullet::Init(Vector2 pos)
{
	auto model = ResourceManagers::GetInstance()->GetModel("Sprite2D");
	auto texture = ResourceManagers::GetInstance()->GetTexture("Animation/bullet");
	auto shader = ResourceManagers::GetInstance()->GetShader("AnimationShader");
	obj = std::make_shared<AnimationSprite>(model, shader, texture, 8, 0.25f);
	obj->Set2DPosition(pos);
	obj->SetSize(38, 48);
	m_pos = pos;
}


void Bullet::Update(float deltaTime)
{
	obj->Update(deltaTime); 
}

void Bullet::Draw()
{
	obj->Draw(); 
}