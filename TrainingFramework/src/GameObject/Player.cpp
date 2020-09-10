#pragma once
#include "Player.h"

Player::Player()
{}

Player::~Player()
{}

void Player::Init(std::string nameFile, Vector2 pos , int numFrame , float frameTime)
{
	auto model = ResourceManagers::GetInstance()->GetModel("Sprite2D");
	auto texture = ResourceManagers::GetInstance()->GetTexture(nameFile);
	auto shader = ResourceManagers::GetInstance()->GetShader("AnimationShader");
	obj = std::make_shared<AnimationSprite>(model , shader , texture , numFrame , frameTime);
	obj->Set2DPosition(pos);
	obj->SetSize(28, 36);
	m_pos = pos;
	shootSpeed = 0.4f; 
}


int KeyPress = 0 ; 


enum DKEY
{
	DKEY_NULL = 0,
	DKEY_UP = 1,
	DKEY_DOWN = 2,
	DKEY_LEFT = 4,
	DKEY_RIGHT = 8,
};

void Player::HandleKeyEvents(int key, bool bIsPressed)
{
	if (bIsPressed == true)
	{
		switch (key)
		{
		case 'W':
			KeyPress |= DKEY_UP;
			break;
		case 'A':
			KeyPress |= DKEY_LEFT;
			break;
		case 'S':
			KeyPress |= DKEY_DOWN;
			break;
		case 'D':
			KeyPress |= DKEY_RIGHT;
			break;
		default:
			break;
		}
	}
	else
	{
		switch (key)
		{
		case 'W':
			KeyPress ^= DKEY_UP;
			break;
		case 'A':
			KeyPress ^= DKEY_LEFT;
			break;
		case 'S':
			KeyPress ^= DKEY_DOWN;
			break;
		case'D':
			KeyPress ^= DKEY_RIGHT;
			break;
		default:
			break;
		}
	}
}


void Player::HandleTouchEvents(int x, int y, bool bIsPressed)
{
}

float time = 0;

void Player::Update(GLfloat deltaTime)
{
	obj->Update(deltaTime);
	if (KeyPress & DKEY_RIGHT)
	{
		m_pos.x += speed * deltaTime;
	}
	if (KeyPress & DKEY_UP)
	{
		m_pos.y -= speed * deltaTime;
	}
	if (KeyPress & DKEY_DOWN)
	{
		m_pos.y += speed * deltaTime;
	}
	if (KeyPress & DKEY_LEFT)
	{
		m_pos.x -= speed * deltaTime;
	}
	
	obj->Set2DPosition(m_pos);

	// Shoot and destroy out range bullet
	time += deltaTime; 
	if (time >= shootSpeed)
	{
		Shoot(); 
		time = 0; 
	}

	for (int i = 0; i < m_bullet.size(); i++)
	{
		std::shared_ptr<Bullet> bullet = m_bullet[i];
		m_bullet[i]->Update(deltaTime);
		if (bullet->Get2DPosition().y < 0) {
			m_bullet.erase(m_bullet.begin());
			bullet = NULL;
		}
	}

}

void Player::Shoot()
{
	float x = this->m_pos.x; 
	float y = this->m_pos.y; 
	auto model = ResourceManagers::GetInstance()->GetModel("Sprite2D");
	auto shader = ResourceManagers::GetInstance()->GetShader("TextureShader");
	auto texture = ResourceManagers::GetInstance()->GetTexture("bullet");
	std::shared_ptr<Bullet> bullet = std::make_shared<Bullet>(model, shader, texture);
	bullet->Set2DPosition(x, y - 60);
	bullet->SetSize(20, 20);
	m_bullet.push_back(bullet);
}


void Player::Draw()
{
	obj->Draw();

	for (auto i : m_bullet)
	{
		i->Draw(); 
	}
}