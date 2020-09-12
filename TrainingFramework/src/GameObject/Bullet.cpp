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

bool Bullet::checkCollision(std::shared_ptr<Slime> obj1)
{
	float obj1_up = obj1->getPos().y - 12;
	float obj1_down = obj1->getPos().y + 12;
	float obj1_left = obj1->getPos().x - 12;
	float obj1_right = obj1->getPos().x + 12;

	float obj2_up = this->Get2DPosition().y - 20;
	float obj2_down = this->Get2DPosition().y + 20;
	float obj2_left = this->Get2DPosition().x - 20;
	float obj2_right = this->Get2DPosition().x + 20;

	if (obj1_up > obj2_down) return false;
	if (obj1_left > obj2_right) return false;
	if (obj1_down < obj2_up) return false;
	if (obj1_right < obj2_left) return false;
	return true;
}

void Bullet::Update(GLfloat deltaTime) {
	this->Set2DPosition(this->Get2DPosition().x, this->Get2DPosition().y - deltaTime * 700);
}
