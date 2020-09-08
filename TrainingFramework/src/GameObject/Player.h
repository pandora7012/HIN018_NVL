#pragma once
#include "ResourceManagers.h"
#include"AnimationSprite.h"
#include "Bullet.h"


class Player 
{
public:
	Player();
	~Player();

	void HandleKeyEvents(int key, bool bIsPressed);
	void HandleTouchEvents(int x, int y, bool bIsPressed);

	void Init(std::string nameFile, Vector2 pos , int numFrames , float frameTime ) ;

	void Update(GLfloat deltaTime);
	void Draw();

	void setBulletlist(std::vector<std::shared_ptr<Bullet>> bullet) {
		m_bullet = bullet; 
	}

	std::vector < std::shared_ptr<Bullet> >GetBullet() const {
		return m_bullet; 
	}

	Vector2 m_pos;
	std::shared_ptr<AnimationSprite> obj;
	std::vector<std::shared_ptr<Bullet>> m_bullet; 
	int speed = 100; 

};