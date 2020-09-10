#include "Bullet.h"
#include "Slime.h"
Bullet::Bullet() {
}

Bullet::Bullet(std::shared_ptr<Models> model, std::shared_ptr<Shaders> shader, std::shared_ptr<Texture> texture) : Sprite2D(model, shader, texture)
{
	
	this->m_dmg = 100;
	this->SetSize(40, 40);
}

int Bullet::getDmg() {
	return this->m_dmg;
}

void  Bullet::setDmg(int dmg)
{
	m_dmg = dmg; 
}

void Bullet::Update(GLfloat deltaTime) {
	this->Set2DPosition(this->Get2DPosition().x, this->Get2DPosition().y - deltaTime * 700);
}
