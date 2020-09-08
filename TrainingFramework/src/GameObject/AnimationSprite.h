#pragma once
#include "Sprite2D.h" 

class AnimationSprite : public Sprite2D
{
public:
	AnimationSprite(); 
	AnimationSprite(std::shared_ptr<Models> model, std::shared_ptr<Shaders> shader, std::shared_ptr<Texture> texture, int numFrames, float frameTime);
	~AnimationSprite();

	void		Init();
	void		Draw();
	void		Update(GLfloat deltatime);
protected: 
	int m_numFrames; 
	float m_frameTime; 
	int m_currentFrame; 
	float m_currentTime;
};