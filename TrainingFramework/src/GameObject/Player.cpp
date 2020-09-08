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
	obj->SetSize(38, 48);
	m_pos = pos;
}


int KeyPress = 0 ; 




enum DKEY
{
	DKEY_NULL = 0,
	DKEY_UP = 1,
	DKEY_DOWN = 2,
	DKEY_LEFT = 4,
	DKEY_RIGHT = 8,
	DKEY_FIRE = 16,
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
		case ' ':
			KeyPress |= DKEY_FIRE;
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
		case ' ':
			KeyPress ^= DKEY_FIRE;
			break;
		default:
			break;
		}
	}
}


void Player::HandleTouchEvents(int x, int y, bool bIsPressed)
{

}

void Player::Update(GLfloat deltaTime)
{
	obj->Update(deltaTime); 
	if (KeyPress & DKEY_RIGHT)
	{
		m_pos.x += speed*deltaTime;
	}
	if (KeyPress & DKEY_UP)
	{
		m_pos.y -= speed* deltaTime;
	}
	if (KeyPress & DKEY_DOWN)
	{
		m_pos.y += speed* deltaTime;
	}
	if (KeyPress & DKEY_LEFT)
	{
		m_pos.x -= speed* deltaTime;
	}
	if (KeyPress && DKEY_FIRE)
	{

	}
	obj->Set2DPosition(m_pos); 
	
}
void Player::Draw()
{
	obj->Draw();
}